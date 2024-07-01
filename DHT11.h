/*
 * DHT11.h
 *
 *  Created on: Jul 1, 2024
 *      Author: mohamedhussein
 */


#ifndef DHT11_H_
#define DHT11_H_


typedef struct{
    int port;
    int pin;
} DHT11;

void DHT11_init(DHT11* sensor, int port, int pin);
float DHT11_readTemperature(DHT11* sensor);
float DHT11_readHumidity(DHT11* sensor);
void DHT11_readTempHumd(DHT11* sensor, float* temperature, float* humidity);


#endif /* DHT11_H_ */
