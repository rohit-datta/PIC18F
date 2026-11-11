/*
 * File:   pic18fex31.c
 * Author: rohit
 *
 * Created on 1 August, 2025, 10:47 AM
 */


#include<pic18.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
void main(){ 
    TRISC=0x00;
    T2CON=0x07;
    PR2=255;
    CCP1CON=0x0F;
    CCPR1L=0x00;
    while(1)
    {
        for(int i=0;i<910;i++){
            CCP1CON=(CCP1CON&(0x0F))|((i&(0x03))<<4);
            CCPR1L=i>>2;
            __delay_ms(5);
        }
    }
}