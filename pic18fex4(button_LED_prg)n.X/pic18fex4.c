/*
 * File:   pic18fex4.c
 * Author: rohit
 *
 * Created on 1 July, 2025, 10:19 AM
 */



#include<pic18.h>
void delay();

void main() {
    TRISC=0x0F;
    TRISD=0x00;
    PORTD=0x00;
    while(1){
        if(PORTCbits.RC0==1 ){
            PORTD=0xFF;
        }
        else if(PORTCbits.RC1==1){
            PORTD=0xAA;
        }
        else if(PORTCbits.RC2==1){
            PORTD=0x55;
        }
        else if(PORTCbits.RC3==1){
            int a=0x80;
             for(int i=0;i<8;i++){
                 LATD=a;
                 a=a>>1;
                 delay();
             }            
        } 
        else{
            PORTD=0x00;
        }
    }
   
}
void delay(){
    for(int i=0;i<200;i++){
        for(int j=0;j<100;j++);
    }
}
