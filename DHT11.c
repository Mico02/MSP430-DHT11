/*
 * DHT11.c
 *
 *  Created on: Jul 1, 2024
 *      Author: mohamedhussein
 */
#include "DHT11.h"
#include "driverlib.h"

/****** HELPER FUNCTIONS *****/
void setPortOutput(int port, int pin){
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

void setPortInput(int port, int pin){
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

void setPinHigh(int port, int pin){
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


void setPinLow(int port, int pin){
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



void DHT11_init(DHT11* sensor, int port, int pin){
    sensor->port = port;
    sensor->pin = pin;
    WDT_A_hold(WDT_A_BASE);
    PMM_unlockLPM5();
}




float DHT11_readTemperature(DHT11* sensor);
float DHT11_readHumidity(DHT11* sensor);
void DHT11_readTempHumd(DHT11* sensor, float* temperature, float* humidity);

