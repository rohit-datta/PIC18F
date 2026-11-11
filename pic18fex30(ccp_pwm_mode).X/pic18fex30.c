/*
 * File:   pic18fex30.c
 * Author: rohit
 *
 * Created on 1 August, 2025, 10:01 AM
 */


#include<pic18.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
void main(){ 
    TRISC=0x00;
    T2CON=0x07;
    PR2=255;
    while(1)
    {
        CCP1CON=0x0F;
        CCPR1L=0x39; // 25 percent
        __delay_ms(2000);
        CCP1CON=0x3F;
        CCPR1L=0x73; //50 percent duty  cycle
        __delay_ms(2000);
        CCP1CON=0x3F;
        CCPR1L=0X99;//75 percent duty cycle
    }
}
