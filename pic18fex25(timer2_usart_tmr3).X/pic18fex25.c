/*
 * File:   pic18fex25.c
 * Author: rohit
 *
 * Created on 28 July, 2025, 4:29 PM
 */

#include<pic18.h>
#include<stdio.h>
void send(char a);
void main(){
    TXSTA=0x20;
    RCSTA=0x90;
    SPBRG=31;
    TRISC=0x01;
    T3CON=0x87;
    unsigned int i=0,b=0;
    char c[10];
    while(1){
        if(TMR3!=b){
            b=TMR3;
            sprintf(c,"%u",b);
            while(c[i]!='\0'){
                send(c[i]);
                i++;
            }
            i=0;
            send('\r');
        }
    }
}
void send(char a){
    while(TXIF==0);
    TXREG=a;
}