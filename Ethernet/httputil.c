/**
******************************************************************************
* @file    			httputil.c
* @author  			WIZnet Software Team 
* @version 			V1.0
* @date    			2015-12-12
* @brief   	  	http中需要的实用函数
******************************************************************************
*/
#include "httputil.h"
#include "webpge.h"
#include "utility.h"
#include "w5500_conf.h"
#include "webpge.h"
#include "board_config.h"
#include "flash.h"
#include "config_handle_task.h"
#include "stm32f4xx_hal_uart.h"
#include "usart.h"
#include "ztn_mqtt.h"
#include "flash_if.h"

#define DEBUG_HTTP

extern CONFIG_MSG  ConfigMsg;
extern char tx_buf[MAX_URI_SIZE];
extern char rx_buf[MAX_URI_SIZE];
uint8 reboot_flag;
static uint32 ContentLengthOffset =0,BrowserFlag=0;
uint32 DataOffset, FilenameOffset;		
uint32 write_len=0;
static char LeftBytesTab[4];
static uint8 LeftBytes=0;
uint8 boundary[64];
uint8 tmp_buf[1460]={0xff,};
extern uint8 pub_buf[1024];
static uint32 twoCRLFOffset=0;
static __IO uint32 TotalData=0, checklogin=0; 
static __IO uint32_t FlashWriteAddress;
static uint32 TotalReceived=0;
static __IO uint32 DataFlag=0;
static __IO uint32 size =0;
static uint32_t Parse_Content_Length(char *data, uint32 len);
static void IAP_HTTP_writedata(char * ptr, uint32 len);

static const struct Webpage_Reg Wevpage[] ={								//	向http服务器功能注册页面
	{"/index.html",XT_INDEX,PTYPE_HTML},
	{"/style.css",style,PTYPE_CSS},
	{NULL,NULL,0}
};

/**
*@brief		将基本的配置信息设置到json_callback
*@param		无
*@return	无
*/
static void make_basic_config_setting_json_callback(int8* buf, CONFIG_MSG config_msg)
{
  sprintf(buf,"settingsCallback({\"ver\":\"%d.%d\",\
                \"ip\":\"%d.%d.%d.%d\",\
                \"gw\":\"%d.%d.%d.%d\",\
                \"sub\":\"%d.%d.%d.%d\",\
								\"sip\":\"%d.%d.%d.%d\",\
								\"stopic\":\"%s\",\
								\"lport\":\"%d\",\
								\"ptopic\":\"%s\",\
								\"rport\":\"%d\",\
								\"user\":\"%s\",\
								\"cid\":\"%s\",\
								\"password\":\"%s\",\
                });",config_msg.sw_ver[0],config_msg.sw_ver[1],
                XT_config.Config_network_local.Local_ip[0],XT_config.Config_network_local.Local_ip[1],XT_config.Config_network_local.Local_ip[2],XT_config.Config_network_local.Local_ip[3],
								XT_config.Config_network_local.Local_gw[0],XT_config.Config_network_local.Local_gw[1],XT_config.Config_network_local.Local_gw[2],XT_config.Config_network_local.Local_gw[3],
								XT_config.Config_network_local.Local_nm[0],XT_config.Config_network_local.Local_nm[1],XT_config.Config_network_local.Local_nm[2],XT_config.Config_network_local.Local_nm[3],
								XT_config.Mqtt_client_Config.Sip[0],XT_config.Mqtt_client_Config.Sip[1],XT_config.Mqtt_client_Config.Sip[2],XT_config.Mqtt_client_Config.Sip[3],
								XT_config.Mqtt_client_Config.subTopic,
								XT_config.Mqtt_client_Config.LPort,
								XT_config.Mqtt_client_Config.pubTopic,
								XT_config.Mqtt_client_Config.SPort,
								XT_config.Mqtt_client_Config.mqttUsername,
								XT_config.Mqtt_client_Config.mqttClientId,
								XT_config.Mqtt_client_Config.password
                );
								printf("1111:%s\r\n",buf);
}

static void make_basic_Uartconfig_setting_json_callback(int8* buf, CONFIG_MSG config_msg){
	int data1;
	int data2;
	int data3;
	int stop1;
	int stop2;
	int stop3;
	if(XT_config.Usart_Config.rs485_1_wordlength == UART_WORDLENGTH_8B){data1 = 8;}
	if(XT_config.Usart_Config.rs485_2_wordlength == UART_WORDLENGTH_8B){data2 = 8;}
	if(XT_config.Usart_Config.rs232_wordlength == UART_WORDLENGTH_8B){data3 = 8;}
	if(XT_config.Usart_Config.rs485_1_stopbit == UART_STOPBITS_1){stop1 = 1;}
	if(XT_config.Usart_Config.rs485_2_stopbit == UART_STOPBITS_1){stop2 = 1;}
	if(XT_config.Usart_Config.rs232_stopbit == UART_STOPBITS_1){stop3 = 1;} 
	sprintf(buf,"settingsUartCallback({\"baut1\":\"%d\",\
                \"baut2\":\"%d\",\
                \"baut3\":\"%d\",\
								\"data1\":\"%d\",\
								\"data2\":\"%d\",\
								\"data3\":\"%d\",\
                \"stop1\":\"%d\",\
								\"stop2\":\"%d\",\
								\"stop3\":\"%d\",\
                });",XT_config.Usart_Config.rs485_1_baut,
										 XT_config.Usart_Config.rs485_2_baut,
										 XT_config.Usart_Config.rs232_baut,
										 data1,data2,data3,stop1,stop2,stop3);
}

static void make_basic_ModbusTask_setting_json_callback(int8* buf, CONFIG_MSG config_msg){
	int count = XT_config.modbus_count;
	char inset_buff[1024];
	char tmp_buf[256]=""; 
	char tmp_buf_addr[256]=""; 
	char* set_buf1;
	char* set_buf2;
	char* set_buf3;
	char sum_buf[500];
	char sum_buf_addr[500];
	printf("modbus_count:%d\r\n",XT_config.modbus_count);
	for(int i = 0 ; i < (XT_config.modbus_count + 1) ; i++){
		printf("XT_config.modbus_data[%d]:%s\r\n",i,XT_config.modbus_data[i]);
	}
	for(int i = 0 ; i < (XT_config.modbus_count + 1) ; i++){
		printf("XT_config.modbus_flag[%d]:%d\r\n",i,XT_config.modbus_flag[i]);
	}
	sprintf(inset_buff,"settingsTaskCallback({\"modbus_count\":%d,\
													\"Addr\":\
													\"value\":\
					)}",count
					);
	//printf("ztn_data.ztn[XT_config.modbus_flag[0]:%d\r\n]",ztn_data.ztn[XT_config.modbus_flag[0]]);
	for(int i = 0 ; i < count ; i++){
			if(i == 0){
					sprintf(tmp_buf,"%d",ztn_data.ztn[XT_config.modbus_flag[i]]);
					sprintf(tmp_buf_addr,"%d",XT_config.modbus_flag[i]);
			}
			else{
					sprintf(tmp_buf,"%s,%d",sum_buf,ztn_data.ztn[XT_config.modbus_flag[i]]);
					sprintf(tmp_buf_addr,"%s,%d",sum_buf_addr,XT_config.modbus_flag[i]);
			}
			sprintf(sum_buf,"%s",tmp_buf);
			sprintf(sum_buf_addr,"%s",tmp_buf_addr);
			memset(tmp_buf,0,strlen(tmp_buf));
			memset(tmp_buf_addr,0,strlen(tmp_buf_addr));
	}
	set_buf1 = strtok(inset_buff,":");
	set_buf3 = strtok(NULL,":");
	set_buf2 = strtok(NULL,":");
	sprintf(buf,"%s:%s:[%s],%s:[%s]})",set_buf1,set_buf3,sum_buf_addr,set_buf2,sum_buf);
	printf("s_buf:%s\r\n",buf);
}

static void make_basic_Update_setting_json_callback(int8* buf, CONFIG_MSG config_msg){
	 sprintf(buf,"settingsUpdateCallback({\"Version\":\"%s\",\
								\"Type\":%d\
                });",XT_config.Version,XT_config.Type);
}	

/**
*@brief		完成http响应
*@param		无
*@return	无
*/
#define SOCK_HTTPS            4
void do_https(void)
{
	uint8 ch=SOCK_HTTPS;																		/*定义一个socket*/
	uint16 len;
	
	st_http_request *http_request;													/*定义一个结构指针*/
	memset(rx_buf,0x00,MAX_URI_SIZE);
	http_request = (st_http_request*)rx_buf;					 
	/* http service start */
	switch(getSn_SR(ch))																		/*获取socket状态*/
	{
		case SOCK_INIT:																				/*socket处于初始化状态*/
			listen(ch);
			break;
		
		case SOCK_LISTEN:																			/*socket处于监听状态*/
			break;
		
		case SOCK_ESTABLISHED:																/*socket处于连接状态*/
			if(getSn_IR(ch) & Sn_IR_CON)
			{
				setSn_IR(ch, Sn_IR_CON);													/*清除中断标志位*/
			}
			if ((len = getSn_RX_RSR(ch)) > 0)		
			{
				len = recv(ch, (uint8*)http_request, len); 				/*接收http请求*/
				*(((uint8*)http_request)+len) = 0;
				proc_http(ch, (uint8*)http_request,len);							/*接收http请求并发送http响应*/
				disconnect(ch);
			}
			break;
			
		case SOCK_CLOSE_WAIT:   															/*socket处于等待关闭状态*/
			if ((len = getSn_RX_RSR(ch)) > 0)
			{
				len = recv(ch, (uint8*)http_request, len);				/*接收http请求*/      
				*(((uint8*)http_request)+len) = 0;
				proc_http(ch, (uint8*)http_request,len);							/*接收http请求并发送http响应*/
			}
			disconnect(ch);
			break;
			
		case SOCK_CLOSED:                   									/*socket处于关闭状态*/
			socket(ch, Sn_MR_TCP, 80, 0x00);   									/*打开socket*/
			break;
		
		default:
			break;
	}
}

/**
*@brief		接收http请求报文并发送http响应
*@param		s: http服务器socket
*@param		buf：解析报文内容
*@return	无
*/
void proc_http(SOCKET s, uint8 * buf,uint32_t len)
{
	int8* name; 
	int8* temp;	
	int8  i;
	int8  login[40];
  int8  filename[40]={0,};
	int8 req_name[32]={0x00,};															/*定义一个http响应报文的指针*/
	unsigned long file_len=0;																/*定义http请求报文头的结构体指针*/
	uint16 send_len=0;
	uint8* http_response;
	st_http_request *http_request;
	memset(tx_buf,0x00,MAX_URI_SIZE);
	http_response = (uint8*)rx_buf;
	http_request = (st_http_request*)tx_buf;
	parse_http_request(http_request, buf);    							/*解析http请求报文头*/

	switch (http_request->METHOD)		
  {
		case METHOD_ERR :																			/*请求报文头错误*/
			memcpy(http_response, ERROR_REQUEST_PAGE, sizeof(ERROR_REQUEST_PAGE));
			send(s, (uint8 *)http_response, strlen((int8 const*)http_response));
			break;
		
		case METHOD_HEAD:																			/*HEAD请求方式*/
			
		case METHOD_GET:					/*GET请求方式*/
			name = http_request->URI;
		  printf("name:%s\r\n",name);
			if(strcmp(name,"/index.htm")==0 || strcmp(name,"/")==0 || (strcmp(name,"/index.html")==0))
			{	
				file_len = strlen(XT_INDEX);
				printf("file_len:%d\r\n",strlen(XT_INDEX));
				make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
				send(s,http_response,strlen((char const*)http_response));
				send_len=0;
				while(file_len)
				{
					if(file_len>256)
					{
						if(getSn_SR(s)!=SOCK_ESTABLISHED)
						{
							return;
						}
						send(s, (uint8 *)XT_INDEX+send_len, 256);
						
						send_len+=256;
						file_len-=256;
					}
					else
					{
					  send(s, (uint8 *)XT_INDEX+send_len, file_len);
						send_len+=file_len;
						file_len-=file_len;
					} 
				}
			}
			else if(strcmp(name,"/XT_Main_Weight.html")==0){
				file_len = strlen(Main_weight);
				printf("file_len:%d\r\n",strlen(Main_weight));
				make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
				send(s,http_response,strlen((char const*)http_response));
				send_len=0;
				while(file_len)
				{
					if(file_len>256)
					{
						if(getSn_SR(s)!=SOCK_ESTABLISHED)
						{
							return;
						}

						send(s, (uint8 *)Main_weight+send_len, 256);
						
						send_len+=256;
						file_len-=256;
					}
					else
					{
					  send(s, (uint8 *)Main_weight+send_len, file_len);
						send_len+=file_len;
						file_len-=file_len;
					} 
				}
			}	
			else if(strcmp(name,"/Net_Config.html")==0){
				file_len = strlen(Net_Config_Html);
				printf("file_len:%d\r\n",strlen(Net_Config_Html));
				make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
				send(s,http_response,strlen((char const*)http_response));
				send_len=0;
				while(file_len)
				{
					if(file_len>256)
					{
						if(getSn_SR(s)!=SOCK_ESTABLISHED)
						{
							return;
						}

						send(s, (uint8 *)Net_Config_Html+send_len, 256);
						
						send_len+=256;
						file_len-=256;
					}
					else
					{
					  send(s, (uint8 *)Net_Config_Html+send_len, file_len);
						send_len+=file_len;
						file_len-=file_len;
					} 
				}
			}
			else if(strcmp(name,"/Usart_Config.html")==0){
				file_len = strlen(Usart_Config_html);
				printf("file_len:%d\r\n",strlen(Usart_Config_html));
				make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
				send(s,http_response,strlen((char const*)http_response));
				send_len=0;
				while(file_len)
				{
					if(file_len>256)
					{
						if(getSn_SR(s)!=SOCK_ESTABLISHED)
						{
							return;
						}

						send(s, (uint8 *)Usart_Config_html+send_len, 256);
						
						send_len+=256;
						file_len-=256;
					}
					else
					{
					  send(s, (uint8 *)Usart_Config_html+send_len, file_len);
						send_len+=file_len;
						file_len-=file_len;
					} 
				}
			}
			else if(strcmp(name,"/Modbus_Config.html")==0){
				file_len = strlen(Modbus_Config_html);
				printf("file_len:%d\r\n",strlen(Modbus_Config_html));
				make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
				send(s,http_response,strlen((char const*)http_response));
				send_len=0;
				while(file_len)
				{
					if(file_len>256)
					{
						if(getSn_SR(s)!=SOCK_ESTABLISHED)
						{
							return;
						}

						send(s, (uint8 *)Modbus_Config_html+send_len, 256);
						
						send_len+=256;
						file_len-=256;
					}
					else
					{
					  send(s, (uint8 *)Modbus_Config_html+send_len, file_len);
						send_len+=file_len;
						file_len-=file_len;
					} 
				}
			}
			else if(strcmp(name,"/Update.html")==0){
				file_len = strlen(Update_html);
				printf("file_len:%d\r\n",strlen(Update_html));
				make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
				send(s,http_response,strlen((char const*)http_response));
				send_len=0;
				while(file_len)
				{
					if(file_len>256)
					{
						if(getSn_SR(s)!=SOCK_ESTABLISHED)
						{
							return;
						}

						send(s, (uint8 *)Update_html+send_len, 256);
						
						send_len+=256;
						file_len-=256;
					}
					else
					{
					  send(s, (uint8 *)Update_html+send_len, file_len);
						send_len+=file_len;
						file_len-=file_len;
					} 
				}
			}
			else if(strcmp(name,"/Debug.html")==0){
				file_len = strlen(Debug_html);
				printf("file_len:%d\r\n",strlen(Debug_html));
				make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
				send(s,http_response,strlen((char const*)http_response));
				send_len=0;
				while(file_len)
				{
					if(file_len>256)
					{
						if(getSn_SR(s)!=SOCK_ESTABLISHED)
						{
							return;
						}

						send(s, (uint8 *)Debug_html+send_len, 256);
						
						send_len+=256;
						file_len-=256;
					}
					else
					{
					  send(s, (uint8 *)Debug_html+send_len, file_len);
						send_len+=file_len;
						file_len-=file_len;
					} 
				}
			}
			else if(strcmp(name,"/Account.html")==0){
				file_len = strlen(Account_html);
				printf("file_len:%d\r\n",strlen(Account_html));
				make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
				send(s,http_response,strlen((char const*)http_response));
				send_len=0;
				while(file_len)
				{
					if(file_len>256)
					{
						if(getSn_SR(s)!=SOCK_ESTABLISHED)
						{
							return;
						}

						send(s, (uint8 *)Account_html+send_len, 256);
						
						send_len+=256;
						file_len-=256;
					}
					else
					{
					  send(s, (uint8 *)Account_html+send_len, file_len);
						send_len+=file_len;
						file_len-=file_len;
					} 
				}
			}
			else if(strcmp(name,"/w5500.js")==0)
			{
				memset(tx_buf,0,MAX_URI_SIZE);
				make_basic_config_setting_json_callback(tx_buf,ConfigMsg);
				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
				send(s, (u_char *)http_response, strlen((char const*)http_response));
			}
			else if(strcmp(name,"/Taskctrl.js")==0){
				js_tasknet(http_request);												/*将配置信息写进单片机eeprom*/
				memset(tx_buf,0,MAX_URI_SIZE);
				make_basic_ModbusTask_setting_json_callback(tx_buf,ConfigMsg);
				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
				send(s, (u_char *)http_response, strlen((char const*)http_response));	
			}
			else if(strcmp(name,"/Deletetr.js")==0){
				NetTaskDele();
			}
			else if(strcmp(name,"/Uartw5500.js")==0){
				memset(tx_buf,0,MAX_URI_SIZE);
				make_basic_Uartconfig_setting_json_callback(tx_buf,ConfigMsg);
				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
				send(s, (u_char *)http_response, strlen((char const*)http_response));
			}
			else if(strcmp(name,"/Upadate.js")==0){
				memset(tx_buf,0,MAX_URI_SIZE);
				make_basic_Update_setting_json_callback(tx_buf,ConfigMsg);
				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
				send(s, (u_char *)http_response, strlen((char const*)http_response));
			}
			break;
			
		case METHOD_POST:																			/*POST请求*/
			mid(http_request->URI, "/", " ", req_name);					/*获取该请求的文件名*/
		printf("req_name:%s\r\n",req_name);
			if(strcmp(req_name,"config.cgi")==0)							  	
			{
				cgi_ipconfig(http_request);												/*将配置信息写进单片机eeprom*/
//				make_cgi_response(5,(int8*)ConfigMsg.lip,tx_buf);	/*生成响应的文本部分*/        
//				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
//																													/*发送http响应*/
//				send(s, (u_char *)http_response, strlen((char *)http_response));		
				disconnect(s);																		/*断开socket连接*/				
				HAL_NVIC_SystemReset();          	/* ?? */
				return;
			}
			
			else if(strcmp(req_name,"Uartconfig.cgi")==0){
				cgi_uartconfig(http_request);												/*将配置信息写进单片机eeprom*/
//				make_cgi_response(5,(int8*)ConfigMsg.lip,tx_buf);	/*生成响应的文本部分*/        
//				sprintf((char *)http_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s",strlen(tx_buf),tx_buf);
																													/*发送http响应*/
				//send(s, (u_char *)http_response, strlen((char *)http_response));		
				disconnect(s);																		/*断开socket连接*/				
				HAL_NVIC_SystemReset();          	/* ?? */
				return;
			}
			else if(strcmp(req_name,"upload.cgi")==0){
				#if 1
				{
				DataOffset=0;
				write_len=len;
				if (DataFlag ==0)                     // 第一接收到upload报文标志,带报文头部
				{ 
					BrowserFlag=0;                    // 浏览器标志清零
					TotalReceived =0;                 // 接收数据数量清零

					/* parse packet for Content-length field */
					size = Parse_Content_Length((char *)buf,len);   // 计算实体主体的size

					/* parse packet for the \r\n\r\n field */
					temp=strstr((char *)buf,"\r\n\r\n");
					if (temp!=NULL)
					{
						twoCRLFOffset = temp-(char *)buf+4;
					}					
					/* parse packet for the octet-stream field */
					temp=strstr((char *)buf,"octet-stream");
					if (temp!=NULL)
					{
						DataOffset = temp-(char *)buf+16;
					} 
					/* case of MSIE8 : we do not receive data in the POST packet */ 
					if (DataOffset==0)
					{
						DataFlag++;
						BrowserFlag = 1;
						return;					 
					}
					/* case of Mozilla Firefox : we receive data in the POST packet*/
					else
					{
						TotalReceived = len - twoCRLFOffset ;
					}
				}
				if (((DataFlag ==1)&&(BrowserFlag==1)) || ((DataFlag ==0)&&(BrowserFlag==0)))
				{ 
					if ((DataFlag ==0)&&(BrowserFlag==0)) 
					{
						DataFlag++;
					}
					else if ((DataFlag ==1)&&(BrowserFlag==1))
					{
						/* parse packet for the octet-stream field */
						temp=strstr((char *)buf,"octet-stream");
						if (temp!=NULL)
						{
							DataOffset = temp-(char *)buf+16;
						} 
						TotalReceived+=len;
						DataFlag++;
					}  
						
					/* parse packet for the filename field */
					FilenameOffset = 0;
					temp=strstr((char *)buf,"filename=");
					if (temp!=NULL)
					{
						FilenameOffset = temp-(char *)buf+10;
					} 
					i=0;
					if (FilenameOffset)
					{
						while((*((char *)buf+FilenameOffset + i)!=0x22 )&&(i < 40))
						{
							filename[i] = *((char *)buf+FilenameOffset + i);
							i++;
						}
						filename[i] = 0x0;
					}
					if (i==0)
					{
						/* no filename, in this case reload upload page */				
						file_len = strlen(Update_html);
						make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
						send(s,(uint8 *)http_response,strlen((char const*)http_response));
						send_len=0;
						while(file_len)
						{
							if(file_len>256)
							{
								if(getSn_SR(s)!=SOCK_ESTABLISHED)
								{
									return;
								}
								send(s, (uint8 *)Update_html+send_len, 1024);
								send_len+=256;
								file_len-=256;
							}
							else
							{
								send(s, (uint8 *)Update_html+send_len, file_len);
								send_len+=file_len;
								file_len-=file_len;
							} 
						}
						DataFlag=0;
						return;
					 
					}					               
					printf("IAP using HTTP\r\n");
					printf("File: %s\r\n",filename);
					printf("  State: Erasing...\r\n");
					
					TotalData =0;
					/* init flash */
					FLASH_If_Init();
					/* erase user flash area */
					FLASH_If_Erase(USER_FLASH_FIRST_PAGE_ADDRESS);
					
					FlashWriteAddress = USER_FLASH_FIRST_PAGE_ADDRESS;
					/*indicate start of flash programming */
					printf("  State: Programming...\r\n");
				}
				/* DataFlag >1 => the packet is data only  */
				else 
				{
					TotalReceived +=len;
				}
				temp = (char*)(buf + DataOffset);
				write_len-= DataOffset;

				/* update Total data received counter */
				TotalData +=write_len;

				/* check if last data packet */
				if (TotalReceived == size)
				{
					/* if last packet need to remove the http boundary tag */
					/* parse packet for "\r\n--" starting from end of data */
					i=4; 
					while (strncmp ((char *)(buf+len-i),"\r\n--" , 4) && (len-i > 0))
					{
						i++;
					}
					write_len-=i;
					TotalData-=i;

					/* write data in Flash */
					if (write_len)
					{
						IAP_HTTP_writedata(temp,len);
					}

					DataFlag=0;

					printf("Tot bytes Received: %d bytes\r\n", (int)TotalData);
					printf("  State: Prog Finished ");

					/* send uploaddone.html page */
					file_len = strlen(UPLOADDONE_HTML);
					make_http_response_head((uint8*)http_response, PTYPE_HTML,file_len);
					send(s,(uint8 *)http_response,strlen((char const*)http_response));
					send_len=0;
					while(file_len)
					{
						if(file_len>256)
						{
							if(getSn_SR(s)!=SOCK_ESTABLISHED)
							{
								return;
							}
							send(s, (uint8 *)UPLOADDONE_HTML+send_len, 1024);
							send_len+=256;
							file_len-=256;
						}
						else
						{
							send(s, (uint8 *)UPLOADDONE_HTML+send_len, file_len);
							send_len+=file_len;
							file_len-=file_len;
						} 
					} 
					#endif
				}
				
				/* not last data packet */
				else
				{
					/* write data in flash */
					if(write_len)
					{
						IAP_HTTP_writedata(temp,write_len);
					}
				}		
			}																	/*重启标志位置1*/
			}
			break;
			
		default :
			break;
	}
}

/**
*@brief		将配置信息写进单片机eeprom
*@param		http_request：定义一个http请求的结构体指针
*@return	无
*/
#define MODBUS_RTU 1
#define MODBUS_TCP 2
#define MODBUS_UDP 3

#define RS485_1 1
#define RS485_2 2
#define RS232 3
void js_tasknet(st_http_request *http_request){
	
	uint8 * param;
	param = get_http_param_value(http_request->URI,"mode");
	printf("param:%s\r\n",param);
	if(param){
		switch(atoi((char*)param)){
			case MODBUS_RTU:{
					param = get_http_param_value(http_request->URI,"usart");
					if(param){
						switch(atoi((char*)param)){
							case RS485_1:break;
							case RS485_2:{
									param = get_http_param_value(http_request->URI,"sid");
									printf("sid:%s\r\n",param);
									param = get_http_param_value(http_request->URI,"fc");
									printf("fc:%s\r\n",param);
									param = get_http_param_value(http_request->URI,"addr");
									printf("addr:%s\r\n",param);
									param = get_http_param_value(http_request->URI,"number");
									printf("number:%s\r\n",param);
							}break;
							case RS232:break;
							default:break;
						}
					}
			}break;
			case MODBUS_TCP:break;
			case MODBUS_UDP:break;
			default:break;
		}
	}
	//XT_config.task_count = XT_config.task_count + 1;
	//saveConfig(&XT_config);
}

void cgi_uartconfig(st_http_request *http_request){
	uint8 * param;
  param = get_http_param_value(http_request->URI,"baut1");
	if(param){XT_config.Usart_Config.rs485_1_baut = atoi((char*)param);}
	param = get_http_param_value(http_request->URI,"baut2");
	if(param){XT_config.Usart_Config.rs485_2_baut = atoi((char*)param);}
	param = get_http_param_value(http_request->URI,"baut3");
	if(param){XT_config.Usart_Config.rs232_baut = atoi((char*)param);}
	param = get_http_param_value(http_request->URI,"data1");
	if(param){XT_config.Usart_Config.rs485_1_wordlength = atoi((char*)param);}
	param = get_http_param_value(http_request->URI,"data2");
	if(param){XT_config.Usart_Config.rs485_2_wordlength = atoi((char*)param);}
	param = get_http_param_value(http_request->URI,"data3");
	if(param){XT_config.Usart_Config.rs232_wordlength = atoi((char*)param);}
	param = get_http_param_value(http_request->URI,"stop1");
	if(param){XT_config.Usart_Config.rs485_1_stopbit = atoi((char*)param);}
	param = get_http_param_value(http_request->URI,"stop2");
	if(param){XT_config.Usart_Config.rs485_2_stopbit = atoi((char*)param);}
	param = get_http_param_value(http_request->URI,"stop3");
	if(param){XT_config.Usart_Config.rs232_stopbit = atoi((char*)param);}
	saveConfig(&XT_config);
} 
	


void cgi_ipconfig(st_http_request *http_request)
{ 
  uint8 * param;
  param = get_http_param_value(http_request->URI,"ip");		/*获取修改后的IP地址*/
  if(param)
  {
    inet_addr_((uint8*)param, XT_config.Config_network_local.Local_ip);	
  }
  param = get_http_param_value(http_request->URI,"gw");		/*获取修改后的网关*/
  if(param)
  {
    inet_addr_((uint8*)param, XT_config.Config_network_local.Local_gw);	
  }
  param = get_http_param_value(http_request->URI,"sub");	/*获取修改后的子网掩码*/
  if(param)
  {
    inet_addr_((uint8*)param, XT_config.Config_network_local.Local_nm);		
  }
	param = get_http_param_value(http_request->URI,"sp");
	if(param)
  {
    inet_addr_((uint8*)param, XT_config.Mqtt_client_Config.Sip);		
  }
	param = get_http_param_value(http_request->URI,"stopic");
	if(param)
  {
    memset(XT_config.Mqtt_client_Config.subTopic,0,strlen(XT_config.Mqtt_client_Config.subTopic));	
		sprintf(XT_config.Mqtt_client_Config.subTopic,"%s",(char*)param);
  }
	param = get_http_param_value(http_request->URI,"lport");
	if(param)
  {
    XT_config.Mqtt_client_Config.LPort = atoi((char*)param);
  }
	param = get_http_param_value(http_request->URI,"ptopic");
	if(param)
  {
    memset(XT_config.Mqtt_client_Config.pubTopic,0,strlen(XT_config.Mqtt_client_Config.pubTopic));	
		sprintf(XT_config.Mqtt_client_Config.pubTopic,"%s",(char*)param);
  }
	param = get_http_param_value(http_request->URI,"rport");
	if(param)
  {
		XT_config.Mqtt_client_Config.SPort = atoi((char*)param);
  }
	param = get_http_param_value(http_request->URI,"user");
	if(param)
  {
    memset(XT_config.Mqtt_client_Config.mqttUsername,0,strlen(XT_config.Mqtt_client_Config.mqttUsername));	
		sprintf(XT_config.Mqtt_client_Config.mqttUsername,"%s",(char*)param);
  }
	param = get_http_param_value(http_request->URI,"clientid");
	if(param)
  {
    memset(XT_config.Mqtt_client_Config.mqttClientId,0,strlen(XT_config.Mqtt_client_Config.mqttClientId));	
		sprintf(XT_config.Mqtt_client_Config.mqttClientId,"%s",(char*)param);
  }
	param = get_http_param_value(http_request->URI,"pwd");
	if(param)
  {
    memset(XT_config.Mqtt_client_Config.password,0,strlen(XT_config.Mqtt_client_Config.password));	
		sprintf(XT_config.Mqtt_client_Config.password,"%s",(char*)param);
  }
	saveConfig(&XT_config);
}

/**
*@brief		执行http响应
*@param		无  
*@return	无
*/
void make_cgi_response(uint16 delay, int8* url,int8* cgi_response_buf)
{
  sprintf(cgi_response_buf,"<html><head><title>iWeb - Configuration</title><script language=javascript>j=%d;function func(){document.getElementById('delay').innerText=' '+j + ' ';j--;setTimeout('func()',1000);if(j==0)location.href='http://%d.%d.%d.%d/';}</script></head><body onload='func()'>please wait for a while, the module will boot in<span style='color:red;' id='delay'></span> seconds.</body></html>",delay,url[0],url[1],url[2],url[3]);
  return;
}

static uint32_t Parse_Content_Length(char *data, uint32 len)
{
  uint32 i=0,size=0, S=1;
  int32 j=0;
  char sizestring[6], *ptr;
   
  ContentLengthOffset =0;
  
  /* find Content-Length data in packet buffer */
  for (i=0;i<len;i++)
  {
    if (strncmp ((char*)(data+i), "Content-Length:", 15)==0)
    {
      ContentLengthOffset = i+16;
      break;
    }
  }
  /* read Content-Length value */
  if (ContentLengthOffset)
  {
    i=0;
    ptr = (char*)(data + ContentLengthOffset);
    while(*(ptr+i)!=0x0d)
    {
      sizestring[i] = *(ptr+i);
      i++;
      ContentLengthOffset++; 
    }
    if (i>0)
    {
      /* transform string data into numeric format */
      for(j=i-1;j>=0;j--)
      {
        size += (sizestring[j]-'0')*S;
        S=S*10;
      }
    }
  }
  return size;
}
static void IAP_HTTP_writedata(char * ptr, uint32 len)            
{
  uint32 count, i=0, j=0;
  
  /* check if any left bytes from previous packet transfer*/
  /* if it is the case do a concat with new data to create a 32-bit word */
  if (LeftBytes)
  {
    while(LeftBytes<=3)
    {
      if(len>j)
      {
        LeftBytesTab[LeftBytes++] = *(ptr+j);
      }
      else
      {
        LeftBytesTab[LeftBytes++] = 0xFF;
      }
      j++;
    }
    FLASH_If_Write(&FlashWriteAddress, (uint32_t*)(LeftBytesTab),1);
    LeftBytes =0;
    
	if(len>j)
	{
		/* update data pointer */
		ptr = (char*)(ptr+j);
		len = len -j;
	}
  }
  
  /* write received bytes into flash */
  count = len/4;
  
  /* check if remaining bytes < 4 */
  i= len%4;
  if (i>0)
  {
    if (TotalReceived != size)
    {
      /* store bytes in LeftBytesTab */
      LeftBytes=0;
      for(;i>0;i--)
      LeftBytesTab[LeftBytes++] = *(char*)(ptr+ len-i);  
    }
    else count++;
  }
  
  if(count)
	FLASH_If_Write(&FlashWriteAddress, (uint32_t*)ptr ,count);
}

uint8_t NetTaskDele(void){
	static int netTask = 0;
	netTask++;
	if(netTask%2 == 0){
		XT_config.modbus_count--;
		memset(XT_config.modbus_data[XT_config.modbus_count],0,strlen(XT_config.modbus_data[XT_config.modbus_count]));
		XT_config.modbus_flag[XT_config.modbus_count] = 0;
		saveConfig(&XT_config);
	}
}

