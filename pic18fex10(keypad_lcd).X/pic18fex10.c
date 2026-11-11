/*
 * File:   pic18fex7.c
 * Author: rohit
 *
 * Created on 3 July, 2025, 9:26 AM
 */


#include <pic18.h>
void delay();
void cmd(char a);
void data(char b);
void main() {
    TRISC=0xF0;
    TRISD=0x00;
    TRISB=0x00;
    ADCON1=0x06;
    cmd(0x06);
    cmd(0x01);
    cmd(0x0C);
    cmd(0x38);
    while(1){
        PORTC=0x0E;
        if(RC4==0)data('1');
        if(RC5==0)data('2');
        if(RC6==0)data('3');
        if(RC7==0)data('A');
        PORTC=0x0D;
        if(RC4==0)data('4');
        if(RC5==0)data('5');
        if(RC6==0)data('6');
        if(RC7==0)data('B');        
        PORTC=0x0B;
        if(RC4==0)data('7');
        if(RC5==0)data('8');
        if(RC6==0)data('9');
        if(RC7==0)data('C');
        PORTC=0x07;
        if(RC4==0)data('*');
        if(RC5==0)data('0');
        if(RC6==0)data('#');
        if(RC7==0)data('D');        
    }
}
void delay(){
    for(int i=0;i<100;i++){
        for(int j=0;j<50;j++);
    }
}
void cmd(char a){
    LATBbits.LB0=0;
    LATD=a;
    LATBbits.LB4=1;
    delay();
    LATBbits.LB4=0;
}
void data(char b){
    LATBbits.LB0=1;
    LATD=b;
    LATBbits.LB4=1;
    delay();
    LATBbits.LB4=0;
    while(RC4==0);
    while(RC5==0);
    while(RC6==0);
    while(RC7==0);
}