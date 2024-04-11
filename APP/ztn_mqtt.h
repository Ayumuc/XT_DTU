#ifndef _ZTN_MQTT_H_
#define _ZTN_MQTT_H_

#include "main.h"

typedef struct ZTN_DATA{
	int charge_status;
	int v_power;
	int v_bat;
	int i_charge;
	int v_output;
	int v_load;
	int i_load;
	int power_charge;
	int power_load;
	int T_bat;
	int T_inside;
	int surplus;
	int ztn[2200];
}ZTN_data;


uint8_t ZTN_MQTT_ENCODE(void);
extern ZTN_data ztn_data;

#endif   // _ZTN_MQTT_H_

