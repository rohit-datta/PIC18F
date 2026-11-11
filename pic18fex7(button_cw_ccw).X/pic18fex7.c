/*
 * File:   pic18fex7.c
 * Author: rohit
 *
 * Created on 3 July, 2025, 9:26 AM
 */


#include <pic18.h>
void delay();

void main() {
    TRISC=0xC0;
    while(1){
        if(PORTCbits.RC6==1){
            LATCbits.LC0=1;
            LATCbits.LC1=0;
            LATCbits.LC2=1;
            LATCbits.LC3=1;
            LATCbits.LC4=1;
            LATCbits.LC5=0;
            delay();
        }
        else if(PORTCbits.RC7==1){
            LATCbits.LC0=0;
            LATCbits.LC1=1;
            LATCbits.LC2=1;
            LATCbits.LC3=1;
            LATCbits.LC4=0;
            LATCbits.LC5=1;
            delay();
        }
        else
            LATC=0x00;
    }   
}
void delay(){
    for(int i=0;i<200;i++){
        for(int j=0;j<50;j++);
    }
}