/*
 * File:   pic18fex20.c
 * Author: rohit
 *
 * Created on 25 July, 2025, 11:14 AM
 */


#include <pic18.h>
#include<string.h>
#include<stdio.h>

char send(char a);
void main(){
    ADCON1=0x0F;
    TXSTA=0x20;
    RCSTA=0x90;
    SPBRG=31;
    TRISC=0x80;
    TRISA=0x10;
    T0CON=0xF8;
    int b=0,i=0;
    char c[5];
    while(1){
        if(TMR0L!=b){
            sprintf(c,"%d",TMR0L);
            while(c[i]!='\0'){
                send(c[i]);
                i++;
            }
            i=0;
            b=TMR0L;
            send('\r');
        }
    }
}
char send(char a){
    while(TXIF==0);
    TXREG=a;
}
