#include "w5500api.h"
#include "w5500.h"
#include <string.h>

W5500_CONFIG NET_CONFIG;

uint8 txsize[MAX_SOCK_NUM] = {2,2,2,2,2,2,2,2};
uint8 rxsize[MAX_SOCK_NUM] = {2,2,2,2,2,2,2,2};

//默认值
uint8 dmac[6]={0x02,0x0e,0xc3,0x23,0x12,0x45};
uint8 dlip[4]={192,168,1,100};
uint8 dsub[4]={255,255,255,0};
uint8 dgw[4]={192,168,2,1};
uint8 ddns[4]={114,114,114,114};
uint8 drip[4]={0,0,0,0};



void put_defaultNet(void){
	memcpy(NET_CONFIG.mac,dmac,6);
	memcpy(NET_CONFIG.lip,dlip,4);
	memcpy(NET_CONFIG.sub,dsub,4);
	memcpy(NET_CONFIG.gw,dgw,4);
	memcpy(NET_CONFIG.dns,ddns,4);
	memcpy(NET_CONFIG.rip,drip,4);
}
void sysinit( uint8 * tx_size, uint8 * rx_size  );
uint8 set_Network(void){
  uint8 temp[6];
  setSHAR(NET_CONFIG.mac);
  setSUBR(NET_CONFIG.sub);
  setGAR(NET_CONFIG.gw);
  setSIPR(NET_CONFIG.lip);
	printf("sub:%d.%d.%d.%d\r\n",NET_CONFIG.sub[0],NET_CONFIG.sub[1],NET_CONFIG.sub[2],NET_CONFIG.sub[3]);
	printf("sub:%d.%d.%d.%d\r\n",NET_CONFIG.gw[0],NET_CONFIG.gw[1],NET_CONFIG.gw[2],NET_CONFIG.gw[3]);
	printf("sub:%d.%d.%d.%d\r\n",NET_CONFIG.lip[0],NET_CONFIG.lip[1],NET_CONFIG.lip[2],NET_CONFIG.lip[3]);
  //Init. TX & RX Memory size of w5500
  sysinit(txsize, rxsize); 
  
  setRTR(2000);/*设置溢出时间值*/
  setRCR(3);/*最大重发次数*/
  
	getSHAR(temp);
	if(NET_CONFIG.mac[0]==temp[0]&&NET_CONFIG.mac[1]==temp[1]&&NET_CONFIG.mac[2]==temp[2]&&
		NET_CONFIG.mac[3]==temp[3]&&NET_CONFIG.mac[4]==temp[4]&&NET_CONFIG.mac[5]==temp[5]){
		getSIPR(temp);
		if(NET_CONFIG.lip[0]==temp[0]&&NET_CONFIG.lip[1]==temp[1]&&NET_CONFIG.lip[2]==temp[2]&&
			NET_CONFIG.lip[3]==temp[3]){
			getSUBR(temp);
			if(NET_CONFIG.sub[0]==temp[0]&&NET_CONFIG.sub[1]==temp[1]&&NET_CONFIG.sub[2]==temp[2]&&
			NET_CONFIG.sub[3]==temp[3]){
				getGAR(temp);
				if(NET_CONFIG.gw[0]==temp[0]&&NET_CONFIG.gw[1]==temp[1]&&NET_CONFIG.gw[2]==temp[2]&&
				NET_CONFIG.gw[3]==temp[3])return 1;
			}
		}
	}
	return 0;
}

/**
*@brief		检测网线是否正常
*@param		无
*@return	无
*/
uint8 PHY_check(void)
{
  return 0x01&IINCHIP_READ(PHYCFGR);
}




