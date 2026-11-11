/*
 * File:   pic18fex37.c
 * Author: rohit
 *
 * Created on 18 August, 2025, 10:50 AM
 */


#include<pic18.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
void send(char a);
unsigned int count;
unsigned int count1;
float e;
int x=0;
void __interrupt() ISR(){
    if(INT0IF==1){
        x=!x;
        if(x==1){
           LATCbits.LC2=1;
           TMR3ON=1;
           while(!TMR3IF);// 
           LATCbits.LC2=0;
           TMR3IF=0;
           TMR3ON=0;
        }
        else{
            LATCbits.LC2=1;
            __delay_us(1000);
            LATCbits.LC2=0;
            __delay_us(20000);            
        }
        INT0IF=0;
    }
}
void main(){
    TXSTA=0x20;
    RCSTA=0x90;
    SPBRG=31;
    TRISA=0xFF;
    TRISC=0x01;
    TRISB=0xFF;
    GIE=1;
    PEIE=1;
    INT0IE=1;
    ADCON0=0x01;
    ADCON1=0x07;
    ADCON2=0xA6;
    T1CON=0xB1;
    T3CON=0xB0;
    unsigned int b,c,i=0,g;
    float d;
    char f[10];
    while(1){
        GO=1;
        while(GO==1);
        b=ADRESH;
        c=(b<<8)|ADRESL;
        d=(long)c * 180 / 1023;
        e=(long)c/1023.0+1; 
        count=65536-(625*e);
        count1=625*(20-e); 
        TMR3=count;
        sprintf(f,"%.2f",d);
        if(TMR1IF==1){
            g=g+105;
            TMR1IF=0;
        }
        if(g>=1000){
            while(f[i]!='\0'){
                send(f[i]);
                i++;
            }
            g=0;
            i=0;
            send('\r');
        }   
    } 
}
void send(char a){
    while(TXIF==0);
    TXREG=a;
}