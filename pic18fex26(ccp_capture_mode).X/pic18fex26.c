/*
 * File:   pic18fex26.c
 * Author: rohit
 *
 * Created on 29 July, 2025, 10:47 AM
 */


#include <xc.h>

void main() {
    TRISC=0xFF;
    CCP1CON=0x04;
    T1CON=0x81;
    while(1);
    return;
     
}
