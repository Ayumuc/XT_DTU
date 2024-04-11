#include "config_handle_task.h"
#include "flash.h"


void handler_1(uint8_t *buf)
{
	printf("hello\r\n");
}

void handler_2(uint8_t *buf)
{
	printf("bye\r\n");
}

void handler_3(uint8_t *buf)
{
	if (strHandler(buf) == 0)
	{
		printf("nsave done\r\n");
	}
	else
	{
		printf("nsave fail\r\n");
	}
}

void Local_Net_Set(uint8_t* buf);
void TcpClient_Set(uint8_t* buf);
void MQTTConfig_Set(uint8_t* buf);
char strHandler(uint8_t *buf)
{
	char ret = '1';

	/*add your program*/
	Local_Net_Set(buf);
	
	TcpClient_Set(buf);
	
	MQTTConfig_Set(buf);

	ret = saveConfig(&XT_config);

	return ret;
}




