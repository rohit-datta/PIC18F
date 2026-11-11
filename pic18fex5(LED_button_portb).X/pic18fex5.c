/*
 * File:   pic18fex5.c
 * Author: rohit
 *
 * Created on 2 July, 2025, 10:00 AM
 */


#include <pic18.h>

void main() {
    TRISB=0x01;
    ADCON1=0xFF;
    while(1){
        if (PORTBbits.RB0==1){
            LATBbits.LB3=1;
            LATBbits.LB7=1;
        }
        else
            LATB=0;
    }
}
