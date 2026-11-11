/*
 * File:   pic18fex32.c
 * Author: rohit
 *
 * Created on 4 August, 2025, 10:34 PM
 */


#include <pic18.h>
#include<stdio.h>
void send(char a);

void main() {
    TRISA=0xFF;
    TRISC=0x80;
    TXSTA=0x20;
    RCSTA=0x90;
    SPBRG=31;
    ADCON0=0x11;
    ADCON1=0x00;
    ADCON2=0xA6;
    int b,c,i=0;
    float x;
    char d[6];
    while(1){
        GO=1;
        while(GO==1);
        b=ADRESH;
        c=(b<<8)|ADRESL;
        x=c*(5.00/1023.00);
        sprintf(d,"%.2f\r\n",x);
        while(d[i]!='\0'){
            send(d[i]);
            i++;
        }
        i=0;
       // send('\r\t');
    }
    return;
}
 void send(char a){
    while(TXIF==0);
    TXREG=a;
}
