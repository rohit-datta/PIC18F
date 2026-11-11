/*
 * File:   pic18fex36.c
 * Author: rohit
 *
 * Created on 18 August, 2025, 10:13 AM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000
void servo_rotate_0(){
    unsigned int i;
    for(i=0;i<50;i++){
        RC0 = 1;
        __delay_us(800);
        RC0 = 0;
        __delay_us(19300);        
    }
}
void servo_rotate_90(){
    unsigned int i;
    for(i=0;i<50;i++){
        RC0 = 1;
        __delay_us(1600);
        RC0 = 0;
        __delay_us(18400);  
    }
}
void servo_rotate_180(){
    unsigned int i;
    for(i=0;i<50;i++){
        RC0 = 1;
        __delay_us(2100);
        RC0 = 0;
        __delay_us(17900);  
    }
}
void main(){
    TRISC = 0;
    servo_rotate_0();
    __delay_ms(500);
   servo_rotate_90();
    __delay_ms(500);
    servo_rotate_180();
    __delay_ms(500);
    
    while(1);
}


        
 