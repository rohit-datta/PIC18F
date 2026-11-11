/*
 * File:   pic18fex34.c
 * Author: rohit
 *
 * Created on 7 August, 2025, 10:30 AM
 */


#include <pic18.h>
void __interrupt() ISR(){
    if(INT0IF){
        RD7=~RD7;
        INT0IF=0;
    }   
}
void main() {
    TRISB=0xFF;
    TRISD=0x00;
    ADCON1=0x0F;
    GIE=1;
    PEIE=1;
    INT0IE=1;
    while(1);
}
