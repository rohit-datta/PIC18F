/*
 * File:   pic18fex27.c
 * Author: rohit
 *
 * Created on 29 July, 2025, 1:59 PM
 */


#include <pic18.h>
#include<stdio.h>
void send(char a);
void main() {
    TXSTA=0x20;
    RCSTA=0x90;
    SPBRG=31;
    TRISC=0xBF;
    CCP1CON=0x04;
    T1CON=0x81;
    unsigned int i=0,b=0;
    char c[20];
    while(1){
        if(CCP1IF==1){
            b=(CCPR1H<<8)|CCPR1L;
            sprintf(c,"%u",b);
            while(c[i]!='\0'){
                send(c[i]);
                i++;
            }
            CCP1IF=0;
            i=0;
            send('\r\t');
        }
    }
    return;
}
void send(char a){
    while(TXIF==0);
    TXREG=a;
}