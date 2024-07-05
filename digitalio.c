/*
 * digitalio.c
 *
 *  Created on: Jul 5, 2024
 *      Author: mohamedhussein
 */
#include "digitalio.h"
#include "driverlib.h"

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



