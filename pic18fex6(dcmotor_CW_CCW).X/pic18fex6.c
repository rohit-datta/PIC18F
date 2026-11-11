/*
 * File:   pic18f4580.c
 * Author: rohit
 *
 * Created on 2 July, 2025, 10:17 AM
 */


#include <pic18.h>
#define _XTAL_FREQ 20000000
void delay();

void main() {
    TRISC=0x00;
    while(1){
        LATC=0x06;
       __delay_ms(3000);
        LATC=0x05;
        __delay_ms(3000);     
       // LATC=0x00;
    }
}
void delay(){
    for(int i=0;i<200;i++){
        for(int j=0;j<50;j++);
    }
}
