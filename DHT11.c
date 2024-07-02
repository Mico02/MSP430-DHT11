/*
 * DHT11.c
 *
 *  Created on: Jul 1, 2024
 *      Author: mohamedhussein
 */
#include "DHT11.h"
#include "driverlib.h"
#include <stdint.h>

/****** HELPER FUNCTIONS *****/

/**
 * Sets a GPIO pin as output given its port and pin.
 * @param port : port of pin
 * @param pin  : pin number
 */
void setPortOutput(uint8_t port, uint8_t pin){
    //Checks what port was chosen and SETS the bit for the corresponding pin in PxDIR register
    switch(port){
        case 1:
            P1DIR |= (1 << pin);
            break;
        case 2:
            P2DIR |= (1 << pin);
            break;
        case 3:
            P3DIR |= (1 << pin);
            break;
        case 4:
            P4DIR |= (1 << pin);
            break;
        case 5:
            P5DIR |= (1 << pin);
            break;
        case 6:
            P6DIR |= (1 << pin);
            break;
        case 7:
            P7DIR |= (1 << pin);
            break;
        case 8:
            P8DIR |= (1 << pin);
            break;
        case 9:
            P9DIR |= (1 << pin);
            break;
        default:
            break;
    }
}


/**
 * Sets a GPIO pin as input given its port and pin.
 * @param port : port of pin
 * @param pin  : pin number
 */
void setPortInput(uint8_t port, uint8_t pin){
    //Checks what port was chosen and RESETS the bit for the corresponding pin in PxDIR register
    switch(port){
        case 1:
            P1DIR &= ~(1 << pin);
            break;
        case 2:
            P2DIR &= ~(1 << pin);
            break;
        case 3:
            P3DIR &= ~(1 << pin);
            break;
        case 4:
            P4DIR &= ~(1 << pin);
            break;
        case 5:
            P5DIR &= ~(1 << pin);
            break;
        case 6:
            P6DIR &= ~(1 << pin);
            break;
        case 7:
            P7DIR &= ~(1 << pin);
            break;
        case 8:
            P8DIR &= ~(1 << pin);
            break;
        case 9:
            P9DIR &= ~(1 << pin);
            break;
        default:
            break;
    }
}


/**
 * Sets a GPIO pin as HIGH given its port and pin, pin must be set at output
 * @param port : port of pin
 * @param pin  : pin number
 */
void setPinHigh(uint8_t port, uint8_t pin){
    //Checks what port was chosen and SETS the bit for the corresponding pin in PxOUT register
    switch(port){
		case 1:
		    P1OUT |= (1 << pin);
		    break;
		case 2:
		    P2OUT |= (1 << pin);
		    break;
		case 3:
		    P3OUT |= (1 << pin);
		    break;
		case 4:
		    P4OUT |= (1 << pin);
		    break;
		case 5:
		    P5OUT |= (1 << pin);
		    break;
		case 6:
		    P6OUT |= (1 << pin);
		    break;
		case 7:
		    P7OUT |= (1 << pin);
		    break;
		case 8:
		    P8OUT |= (1 << pin);
		    break;
		case 9:
		    P9OUT |= (1 << pin);
		    break;
		default:
		    break;
    }
}


/**
 * Sets a GPIO pin as LOW given its port and pin, pin must be set at output
 * @param port : port of pin
 * @param pin  : pin number
 */
void setPinLow(uint8_t port, uint8_t pin){
    //Checks what port was chosen and RESETS the bit for the corresponding pin in PxOUT register
    switch(port){
        case 1:
            P1OUT &= ~(1 << pin);
            break;
        case 2:
            P2OUT &= ~(1 << pin);
            break;
        case 3:
            P3OUT &= ~(1 << pin);
            break;
        case 4:
            P4OUT &= ~(1 << pin);
            break;
        case 5:
            P5OUT &= ~(1 << pin);
            break;
        case 6:
            P6OUT &= ~(1 << pin);
            break;
        case 7:
            P7OUT &= ~(1 << pin);
            break;
        case 8:
            P8OUT &= ~(1 << pin);
            break;
        case 9:
            P9OUT &= ~(1 << pin);
            break;
        default:
            break;
        }
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
    CSCTL0_H = CSKEY_H; // unlock clock control registers
    CSCTL1 = 0x0000; // set DCO to 1MHZ
    CSCTL3 &= ~(DIVM_0); // set MCLK to /1
    CSCTL0_H = 0; // lock clock control registers

    //setting struct variables to match port & pin
    sensor->port = port;
    sensor->pin = pin;

    __delay_cycles(1000000); // wait 1 second after initialization
}


float DHT11_readTemperature(DHT11* sensor){
    /* Setting pin low for 20mx as start signal for dh */
    setPinLow(sensor->port, sensor->pin);
    __delay_cycles(20000);
    /* disabling output to pull up with external pull-up resistor */

}



float DHT11_readHumidity(DHT11* sensor);
void DHT11_readTempHumd(DHT11* sensor, float* temperature, float* humidity);

