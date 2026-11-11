/*
 * File:   pic18fex1.c
 * Author: rohit
 *
 * Created on 27 June, 2025, 10:24 AM
 */


#include <xc.h>
#include<pic18.h>
void delay();

void main(void) {
    TRISB=0x00;
    while(1){
        int a=0x80;
        for(int i=0;i<8;i++){
            LATB=a;
            a=a>>1;
            delay();
        }
    }
}
void delay(){
    for(int i=0;i<200;i++){
        for(int j=0;j<100;j++);
    }
}
