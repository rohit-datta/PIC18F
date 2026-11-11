/*
 * File:   pic18fex29.c
 * Author: rohit
 *
 * Created on 30 July, 2025, 10:41 AM
 */


#include <pic18.h>

void main() {
    TRISC=0x00;
    T1CON=0x81;
    CCP1CON=0x0B;
    CCPR1H=0x27;
    CCPR1L=0x10;
    while(1){
        if(CCP1IF==1){
            CCP1=!CCP1;
            CCP1IF=0;
        }
    }
    return;
}
