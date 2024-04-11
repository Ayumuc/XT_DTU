#include "Task_Handle.h"
#include "main.h"
#include "string.h"
#include "stdio.h"
#include "usart.h"
#include "board_config.h"
#include "stdlib.h"


void Local_Net_Set(uint8_t* buf){
	char *tmp_str;
  char _ip[20];
  char _port[20];
  char _netmask[30];
  char _gateway[30];

  uint8_t _ip_cfg[4];
  uint8_t _netmask_cfg[4];
  uint8_t _gateway_cfg[4];
  int     _port_cfg;
	//{"IP:10.193.6.207;PORT:5900;NETMASK:255.255.255.0;GATEWAY:10.193.6.1"}
  if (!strncasecmp((char*)buf, "IP", 2)){
		
			tmp_str = strtok((char*)buf, ";");  //printf("%s\r\n", tmp_str);//"IP"192.168.3.47"
      strcpy(_ip, tmp_str);

      tmp_str = strtok(NULL, ";");  //printf("%s\r\n", tmp_str);//"PORT:5506"
      strcpy(_port, tmp_str);       //printf("%s\r\n", _port);//"PORT:5506"

      tmp_str = strtok(NULL, ";");  //printf("%s\r\n", tmp_str);//"NETMASK:255.255.255.255"
      strcpy(_netmask, tmp_str);    //printf("%s\r\n", _netmask);//"NETMASK:255.255.255.255"

      tmp_str = strtok(NULL, ";");  //printf("%s\r\n", tmp_str);//"GATEWAY:192.168.3.1"
      strcpy(_gateway, tmp_str);    //printf("%s\r\n", _gateway);//"GATEWAY:192.168.3.1"
		
			tmp_str = strtok(_ip, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"IP"
      tmp_str = strtok(NULL, ":");  //printf("%d %s\r\n", __LINE__, tmp_str);  //"192.168.3.47"
      tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
      _ip_cfg[0] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[0]); //192

      tmp_str = strtok(NULL, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"168"
      _ip_cfg[1] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[1]); //168

      tmp_str = strtok(NULL, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"3"
      _ip_cfg[2] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[2]); //3

      tmp_str = strtok(NULL, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"3"
      _ip_cfg[3] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[3]); //3
		
			tmp_str = strtok(_port, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
      tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
      _port_cfg = atoi(tmp_str);       //printf("%d %d\r\n", __LINE__, _port_cfg); //5506
		
			tmp_str = strtok(_netmask, ":");  // printf("%d %s\r\n", __LINE__, tmp_str); //"NETMASK"
      tmp_str = strtok(NULL, ":");  //printf("%d %s\r\n", __LINE__, tmp_str);  //"255.255.255.255"
      tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"255"
      _netmask_cfg[0] = atoi(tmp_str); // printf("%d %d\r\n", __LINE__, _netmask_cfg[0]); //255

      tmp_str = strtok(NULL, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"255"
      _netmask_cfg[1] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _netmask_cfg[1]); //255

      tmp_str = strtok(NULL, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"255"
      _netmask_cfg[2] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _netmask_cfg[2]); //255

      tmp_str = strtok(NULL, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"255"
      _netmask_cfg[3] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _netmask_cfg[3]); //255
			
			 tmp_str = strtok(_gateway, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"GATEWAY"
      tmp_str = strtok(NULL, ":");       //printf("%d %s\r\n", __LINE__, tmp_str);  //"192.168.3.47"
      tmp_str = strtok(tmp_str, ".");    //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
      _gateway_cfg[0] = atoi(tmp_str);    //printf("%d %d\r\n", __LINE__, _gateway_cfg[0]); //192

      tmp_str = strtok(NULL, ".");       //printf("%d %s\r\n", __LINE__, tmp_str); //"168"
      _gateway_cfg[1] = atoi(tmp_str);    //printf("%d %d\r\n", __LINE__, _gateway_cfg[1]); //168

      tmp_str = strtok(NULL, ".");       //printf("%d %s\r\n", __LINE__, tmp_str); //"3"
      _gateway_cfg[2] = atoi(tmp_str);    //printf("%d %d\r\n", __LINE__, _gateway_cfg[2]); //3

      tmp_str = strtok(NULL, ".");       //printf("%d %s\r\n", __LINE__, tmp_str); //"3"
      _gateway_cfg[3] = atoi(tmp_str);    //printf("%d %d\r\n", __LINE__, _gateway_cfg[3]); //1
			
			XT_config.Config_network_local.Local_ip[0] = _ip_cfg[0];
			XT_config.Config_network_local.Local_ip[1] = _ip_cfg[1];
			XT_config.Config_network_local.Local_ip[2] = _ip_cfg[2];
			XT_config.Config_network_local.Local_ip[3] = _ip_cfg[3];
			
			XT_config.Tcp_Client_mode.Tcp_dest_port = _port_cfg;
			
			XT_config.Config_network_local.Local_nm[0] = _netmask_cfg[0];
			XT_config.Config_network_local.Local_nm[1] = _netmask_cfg[1];
			XT_config.Config_network_local.Local_nm[2] = _netmask_cfg[2];
			XT_config.Config_network_local.Local_nm[3] = _netmask_cfg[3];
			
			XT_config.Config_network_local.Local_gw[0] = _gateway_cfg[0];
			XT_config.Config_network_local.Local_gw[1] = _gateway_cfg[1];
			XT_config.Config_network_local.Local_gw[2] = _gateway_cfg[2];
			XT_config.Config_network_local.Local_gw[3] = _gateway_cfg[3];
	}
}

void TcpClient_Set(uint8_t* buf){
		 char *tmp_str;
		 char _sip[20];
		 char _sport[20];
	
		 uint8_t _sip_cfg[4];
		 uint8_t _sport_cfg;
		 if (!strncasecmp((char*)buf, "SIP", 3)){
				
				tmp_str = strtok((char*)buf, ";");  
				strcpy(_sip, tmp_str);
				tmp_str = strtok(NULL, ";"); 
				strcpy(_sport, tmp_str);
				
				tmp_str = strtok(_sip, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"IP"
				tmp_str = strtok(NULL, ":");  //printf("%d %s\r\n", __LINE__, tmp_str);  //"192.168.3.47"
				tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
				_sip_cfg[0] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[0]); //192
				tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
				_sip_cfg[1] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[0]); //192
				tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
				_sip_cfg[2] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[0]); //192
			  tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
				_sip_cfg[3] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[0]); //192
			 
				tmp_str = strtok(_sport, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
				tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
				_sport_cfg = atoi(tmp_str);       //printf("%d %d\r\n", __LINE__, _port_cfg); //5506
				
				XT_config.Tcp_Client_mode.Tcp_dest_ip[0] = _sip_cfg[0];
				XT_config.Tcp_Client_mode.Tcp_dest_ip[1] = _sip_cfg[1];
				XT_config.Tcp_Client_mode.Tcp_dest_ip[2] = _sip_cfg[2];
				XT_config.Tcp_Client_mode.Tcp_dest_ip[3] = _sip_cfg[3];
				
				XT_config.Tcp_Client_mode.Tcp_dest_port = _sport_cfg;
				
		 }
}

void MQTTConfig_Set(uint8_t* buf){
		char *tmp_str;
		char _MQTIP[20];
		char _MQTSPort[20];
		char _MQTLPort[20];
		char _MQTSubTopic[100];
		char _MQTPubTopic[100];
		char _MQTHeartbeat[20];
		char _MQTUsr[50];
		char _MQTPWD[100];
		char _MQTID[100];
	
		uint8_t _MQTSIP[4];
		uint8_t __MQTSPORT;
		uint8_t __MQTLPORT;
		char  __MQTSubTopic[100];
		char  __MQTPubTopic[100];
		uint8_t __MQTHeartbeat;
		char __MQTUsr[50];
		char __MQTPWD[100];
		char __MQTID[100];
		if (!strncasecmp((char*)buf, "MQTIP", 5)){
			 tmp_str = strtok((char*)buf, ";");  
			 strcpy(_MQTIP, tmp_str);
			 
			 tmp_str = strtok((char*)buf, ";"); 
			 strcpy(_MQTSPort, tmp_str);
			
			 tmp_str = strtok((char*)buf, ";"); 
			 strcpy(_MQTLPort, tmp_str);
			
			 tmp_str = strtok((char*)buf, ";");  
			 strcpy(_MQTSubTopic, tmp_str);
			
			 tmp_str = strtok((char*)buf, ";");  
			 strcpy(_MQTPubTopic, tmp_str);
			
			 tmp_str = strtok((char*)buf, ";");  
			 strcpy(_MQTHeartbeat, tmp_str);
			
			 tmp_str = strtok((char*)buf, ";");  
			 strcpy(_MQTUsr, tmp_str);
			
			 tmp_str = strtok((char*)buf, ";");  
			 strcpy(_MQTPWD, tmp_str);
			 
			 tmp_str = strtok((char*)buf, ";");  
			 strcpy(_MQTID, tmp_str);
			 
			 tmp_str = strtok(_MQTIP, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"IP"
			 tmp_str = strtok(NULL, ":");  //printf("%d %s\r\n", __LINE__, tmp_str);  //"192.168.3.47"
			 tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
			 _MQTSIP[0] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[0]); //192
			 tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
			 _MQTSIP[1] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[0]); //192
			 tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
			 _MQTSIP[2] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[0]); //192
			 tmp_str = strtok(tmp_str, ".");  //printf("%d %s\r\n", __LINE__, tmp_str); //"192"
			 _MQTSIP[3] = atoi(tmp_str);  //printf("%d %d\r\n", __LINE__, _ip_cfg[0]); //192
			 
			 tmp_str = strtok(_MQTSPort, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
			 tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
			 __MQTSPORT = atoi(tmp_str);       //printf("%d %d\r\n", __LINE__, _port_cfg); //5506
			 
			 tmp_str = strtok(_MQTLPort, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
			 tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
			 __MQTLPORT = atoi(tmp_str);       //printf("%d %d\r\n", __LINE__, _port_cfg); //5506
			 
			 tmp_str = strtok(_MQTSubTopic, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
			 tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
			 sprintf(__MQTSubTopic,"%s",tmp_str);
			 
			 tmp_str = strtok(_MQTPubTopic, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
			 tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
			 sprintf(__MQTPubTopic,"%s",tmp_str);
			 
			 tmp_str = strtok(_MQTHeartbeat, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
			 tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
			 __MQTHeartbeat = atoi(tmp_str);       //printf("%d %d\r\n", __LINE__, _port_cfg); //5506
			 
			 tmp_str = strtok(_MQTUsr, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
			 tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
			 sprintf(__MQTUsr,"%s",tmp_str);
			 
			 tmp_str = strtok(_MQTPWD, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
			 tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
			 sprintf(__MQTPWD,"%s",tmp_str);
			 
			 tmp_str = strtok(_MQTID, ":");   //printf("%d %s\r\n", __LINE__, tmp_str); //"PORT"
			 tmp_str = strtok(NULL, ":");    //printf("%d %s\r\n", __LINE__, tmp_str);   //"5506"
			 sprintf(__MQTID,"%s",tmp_str);
			 
			 XT_config.Mqtt_client_Config.Sip[0] = _MQTSIP[0];
			 XT_config.Mqtt_client_Config.Sip[1] = _MQTSIP[1];
			 XT_config.Mqtt_client_Config.Sip[2] = _MQTSIP[2];
			 XT_config.Mqtt_client_Config.Sip[3] = _MQTSIP[3];
						
			 XT_config.Mqtt_client_Config.SPort = __MQTSPORT;
			 
			 XT_config.Mqtt_client_Config.LPort = __MQTLPORT;
			 
			 sprintf(XT_config.Mqtt_client_Config.subTopic,"%s",__MQTSubTopic);
			 
			 sprintf(XT_config.Mqtt_client_Config.pubTopic,"%s",__MQTPubTopic);
			 
			 XT_config.Mqtt_client_Config.keepalive = __MQTHeartbeat;
			 
			 sprintf(XT_config.Mqtt_client_Config.mqttUsername,"%s",__MQTUsr);
			 
			 sprintf(XT_config.Mqtt_client_Config.password,"%s",__MQTPWD);
			 
			 sprintf(XT_config.Mqtt_client_Config.mqttClientId,"%s",__MQTID);
		}
}


