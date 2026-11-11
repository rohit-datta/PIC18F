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
    int a=0x01;
    while(1){
        if(a!=0x00){
           PORTB=a;
           a=a<<1;
           delay();
        }
        else{
            a=0x01;
        }
    }
}
void delay(){
    for(int i=0;i<200;i++){
        for(int j=0;j<100;j++);
    }
}
