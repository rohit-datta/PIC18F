/*
 * File:   pic18fex22.c
 * Author: rohit
 *
 * Created on 28 July, 2025, 10:27 AM
 */


#include<pic18.h>
void main(){
    TRISD=0x00;
    T1CON=0xB1;
    TMR1=0xE796;
    while(1){
        if(TMR1IF==1){
        PORTD=!PORTD;
        TMR1IF=0;
        TMR1=0xE796;
    }
    }
}
