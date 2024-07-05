/*
 * digitalio.h
 *
 *  Created on: Jul 5, 2024
 *      Author: mohamedhussein
 */

#ifndef DIGITALIO_H_
#define DIGITALIO_H_
#include <stdint.h>


void setPortOutput(uint8_t port, uint8_t pin);
void setPortInput(uint8_t port, uint8_t pin);
void setPinHigh(uint8_t port, uint8_t pin);
void setPinLow(uint8_t port, uint8_t pin);


#endif /* DIGITALIO_H_ */
