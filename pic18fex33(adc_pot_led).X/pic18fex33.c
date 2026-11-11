/*
 * File:   pic18fex33.c
 * Author: rohit
 *
 * Created on 5 August, 2025, 9:49 AM
 */


#include <pic18.h>
void main() {
    TRISA=0xFF;
    TRISC=0x00;
    ADCON0=0x11;
    ADCON1=0x00;
    ADCON2=0xA6;
    int b,c;
    while(1){
        GO=1;
        while(GO==1);
        b=ADRESH;
        c=(b<<8)|ADRESL;
        if(c>=0&&c<200)
            PORTC=0x01;
        if(c>=200&&c<400)
            PORTC=0x02;
        if(c>=400&&c<600)
            PORTC=0x04;
        if(c>=600&&c<800)
            PORTC=0x08;
        if(c>=800&&c<1023)
            PORTC=0x10;
    }
    return;
}
