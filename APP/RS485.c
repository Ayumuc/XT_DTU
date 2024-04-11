#include "RS485.h"
#include "delay.h"


void Start485Task(void const * argument){
		printf("485 model\r\n");
		memset(RS485_2_BUFF,0,MAX_NUMBER);
		while(1){
			HAL_UART_Receive(&huart3,RS485_2_BUFF,MAX_NUMBER,100);
			printf("recv:");
			for(int i = 0 ; i < MAX_NUMBER ; i++){
				printf(" %x",RS485_2_BUFF[i]);
			}
			printf("\r\n");
			RS485_Data_Handle(RS485_2_BUFF);
			delay_ms(100);
		}
}

void RS485_Data_Handle(uint8_t* buf){
		Decode_485data.Device_id = buf[0];
		Decode_485data.Function_id = buf[1];
		Decode_485data.Data_NUM = buf[2];
		Decode_485data.Data = buf[3] << 8 | buf[4];
		Decode_485data.crc = buf[5] << 8 | buf[6];
	  printf("485data:\r\n id:%x\r\n fid:%x\r\n DNUM:%x\r\n DATA:%02X\r\n crc:%02X\r\n",Decode_485data.Device_id,Decode_485data.Function_id,Decode_485data.Data_NUM,Decode_485data.Data,Decode_485data.crc);
}


unsigned short int getModbusCRC16(unsigned char *_pBuf, unsigned short int _usLen)
{
    unsigned short int CRCValue = 0xFFFF;         
    unsigned char i,j;

    for(i=0;i<_usLen;++i)
    {
        CRCValue  ^= *(_pBuf+i);                   
        for(j=0;j<8;++j)                           
        {
            if((CRCValue & 0x01) == 0x01)          
            {
                 CRCValue = (CRCValue >> 1)^0xA001; 
            }else
            {
                CRCValue >>= 1;                    
            }
        }
    }
    return CRCValue;
}
