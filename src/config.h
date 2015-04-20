#ifndef CONFIG_H
#define CONFIG_H


typedef struct t_payload{
	unsigned long timeStamp;
	int16_t valLight;
	int16_t valTemperature;
	int16_t valHumidity;
} payload;


#endif CONFIG_H