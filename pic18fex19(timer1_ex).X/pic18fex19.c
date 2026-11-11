/*
 * File:   pic18fex19.c
 * Author: rohit
 *
 * Created on 25 July, 2025, 10:58 AM
 */


#include <pic18.h>

void main(){
    T1CON=0xB1;
    TRISD=0x00;
    while(1){
        if(TMR1IF==1){
            PORTD=!PORTD;
            TMR1IF=0;
        }
    }
}
