/*
 * File:   pic18fexdht11.c
 * Author: rohit
 *
 * Created on 2 October, 2025, 6:38 PM
 */


#include <xc.h>
#include<pic18.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
void string(char *s);
int dht11_read_data();
void main() {
    TRISC=0x82;
    T1CON=0x30;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=129;
    char value[10];
    int hum0,hum1,temp0,temp1,checksum;
    while(1){
        RC2=0;
        __delay_ms(18);
        
        TRISC=(0x82)|(1<<2);
        while(RC2==1);
        while(RC2==0);
        while(RC2==1);
        hum0=dht11_read_data();
        hum1=dht11_read_data();
        temp0=dht11_read_data();
        temp1=dht11_read_data();
        checksum=dht11_read_data();
        TRISC=0x82;  
        string("humidity:");
        sprintf(value,"%d",hum0);
        string(value);
        sprintf(value,".%d",hum1);
        string(value);
        string("\r\n");
        string("temperature:");
        sprintf(value,"%d",temp0);
        string(value);
        sprintf(value,".%d",temp1);
        string(value);
        string("\r\n");
        __delay_ms(2000);
    }
}
void string(char *s){
    while(*s){ 
        while(!TXIF);
        TXREG = *s++;   
    }
}
int dht11_read_data(){
    int a=0;
    for(int i=0;i<8;i++){
        while(RC2==0);
        __delay_us(30);
        if(RC2==1) a|=(1<<(7-i));
        else a&=~(1<<(7-i));
        while(RC2==1);
    }
    return a;
}