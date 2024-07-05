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
 * Converts 8-bit sequence stored in an array into a byte.
 * @param bits : pointer to address of array
 * @param start: starting index of bits for the byte
 * @param end: ending index of bits for the byte
 * @requires bits.length >= 8 and end-start = 8.
 */
char bitsToByte(int* bits, int start, int end){
    char result = 0; // stores final result

    /* Iterating through each bit in the array and forms the byte in results */
    unsigned int i;
    for(i = start; i < end; i++){
        result += (bits[i] << (end - 1 - i));
    }

    return result;
}

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

    //Enabling capture mode, interrupts, sync. capture
    TA0CCTL0 |= CAP | CCIE | CM_2 | SCS;
    _enable_interrupts();

    while(count < 40){} // run until all 40 bits are captured.


    int i =0;
    int bits[40];
    bits[0] = 0;
    for(i = 1; i < 40; i++){
        if(data[i] >= 80){ bits[i] = 1;}
        if(data[i] <= 80){ bits[i] = 0;}
    }
    __no_operation();
    return 0;

}



float DHT11_readHumidity(DHT11* sensor);
void DHT11_readTempHumd(DHT11* sensor, float* temperature, float* humidity);


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0(void)
{
    data[count] = TA0CCR0; //reading time from capture register
    count++; //incrementing the number of bits captured
    TA0CCTL0 &= ~CCIFG; //resetting interrupt flag
    TA0CTL |= BIT2; //resetting timer

}

