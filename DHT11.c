/*
 * DHT11.c
 *
 *  Created on: Jul 1, 2024
 *      Author: mohamedhussein
 */
#include "DHT11.h"
#include "digitalio.h"
#include "driverlib.h"
#include <stdint.h>
#include <stdio.h>

int count = 0;
int data[40];

/**
 * Initializes the DHT sensor on the given port and pin
 * @param port : port of pin
 * @param pin  : pin number
 */
void DHT11_init(DHT11* sensor, uint8_t port, uint8_t pin){

    //Clock setup
    WDT_A_hold(WDT_A_BASE); // disable wdt
    PMM_unlockLPM5(); // unlock all pins
    int temp = CSCTL0_H;
    CSCTL0_H = CSKEY_H; // unlock clock control registers
    CSCTL1 = 0x0000; // set DCO to 1MHZ
    CSCTL3 = 0x0000; // no division on clocks
    CSCTL0_H = temp; // lock clock control registers

    //setting struct variables to match port & pin
    sensor->port = port;
    sensor->pin = pin;

    __delay_cycles(1000000); // wait 1 second after initialization
}


float DHT11_readTemperature(DHT11* sensor){
    /* Setting pin low for 20ms as start signal for dh */
    setPortOutput(sensor->port, sensor->pin);
    setPinLow(sensor->port, sensor->pin);
    __delay_cycles(20000);
    /* disabling output to pull up with external pull-up resistor */
    setPortInput(sensor->port, sensor->pin);

    //SET THE SENSORS PIN AS A TIMER USING P1.5
    P1SEL1 |= BIT5;
    P1SEL0 |= BIT5;

    //Connect TA0 to SMCLK, continous mode
    TA0CTL = 0x0220;



    /* waiting for 80us low and 80us high */
    __delay_cycles(160);
    TA0CCTL0 |= CAP | CCIE | CM_2 | SCS;
    _enable_interrupts();
    while(count < 40){}
    int i =0;
    int newdata[40];
    newdata[0] - 0;
    for(i = 1; i < 40; i++){
        if(data[i] >= 80){ newdata[i] = 1;}
        if(data[i] <= 80){ newdata[i] = 0;}
    }
    __no_operation();
    return 0;

}



float DHT11_readHumidity(DHT11* sensor);
void DHT11_readTempHumd(DHT11* sensor, float* temperature, float* humidity);


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0(void)
{
    data[count] = TA0CCR0;
    count++;
    TA0CCTL0 &= ~CCIFG;
    TA0CTL |= BIT2;

}

