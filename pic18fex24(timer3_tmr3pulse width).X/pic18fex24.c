/*
 * File:   pic18fex24.c
 * Author: rohit
 *
 * Created on 28 July, 2025, 10:42 AM
 */


#include<pic18.h>
void main(){
    TRISD=0x00;
    T3CON=0xB1;
    while(1){
        TMR3=64598;
        while(TMR3IF==0);
        PORTD=!PORTD;
        TMR3IF=0;
    }
}
