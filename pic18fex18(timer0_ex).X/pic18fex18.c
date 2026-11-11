/*
 * File:   pic18fex18.c
 * Author: rohit
 *
 * Created on 24 July, 2025, 6:00 PM
 */


#include <pic18.h>

void main(){
    TRISB=0x00;
    T0CON=0xC7;
    TRISD=0x00;
    int i=0;
    ADCON1=0x0F;
    RB1=0;
    while(1){
        if(TMR0IF==1){
            i++;
            if(i==100){
                PORTB = ~PORTB;
                i=0;
            }
            TMR0IF=0;
        }
    }
}
