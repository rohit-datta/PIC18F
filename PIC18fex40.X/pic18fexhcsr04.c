/*
 * File:   pic18fexhcsr04.c
 * Author: rohit
 *
 * Created on 2 October, 2025, 6:37 PM
 */


#include <xc.h>
#include<pic18.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
void string(char *s);

void main() {
    TRISC=0x82;
    T1CON=0x30;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=129;
    char arr[20];
    float a,b;
    while(1){
        RC0=1;
        __delay_us(10);
        RC0=0;
        while(RC1==0);
        TMR1=0;
        TMR1ON=1;
        while(RC1==1);
        TMR1ON=0;
        a=(float)(TMR1)*(1.6)*(1.0e-6);
        b=(float)(a*34000)/2;
        sprintf(arr,"%.3f\r",b);
        string(arr);
    }
}
void string(char *s){
    while(*s){ 
        while(!TXIF);
        TXREG = *s++;   
    }
}

