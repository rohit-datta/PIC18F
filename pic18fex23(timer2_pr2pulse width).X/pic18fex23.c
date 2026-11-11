/*
 * File:   pic18fex23.c
 * Author: rohit
 *
 * Created on 28 July, 2025, 10:05 AM
 */


#include<pic18.h>

void main(){
    TRISD=0x00;
    T2CON=0x7E;
    PR2=194;
    PORTD=0x00;
    while(1){
        if(TMR2IF==1){
        PORTD=!PORTD;
        TMR2IF=0;
    }
    }
}
