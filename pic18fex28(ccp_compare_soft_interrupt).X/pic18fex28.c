/*
 * File:   pic18fex28.c
 * Author: rohit
 *
 * Created on 30 July, 2025, 10:12 AM
 */


#include <pic18.h>

void main() {
    TRISC=0x00;
    T1CON=0x81;
    CCP1CON=0x0A;//CCP1CON=0x02 HARDWARE ITSELF IS TAKING CARE OF TOGGLING WE DONT NEED TO WRITE IT IN WHILE IF USED THIS
    CCPR1=56500;
    while(1){
        if(CCP1IF==1){
            CCP1=!CCP1;
            CCP1IF=0;
        }
    }
    return;
}
