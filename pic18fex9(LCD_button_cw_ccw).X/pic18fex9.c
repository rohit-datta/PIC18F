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
    char c[]="cw";
    char d[]="ccw";
    TRISC=0xC0;
    TRISD=0x00;
    TRISB=0x00;
    ADCON1=0x06;
    cmd(0x06);
    cmd(0x01);
    cmd(0x0C);
    cmd(0x80);
    cmd(0x38);
    while(1){
        if(PORTCbits.RC6==1){
            int i=0;
            cmd(0x80);
            LATCbits.LC0=1;
            LATCbits.LC1=0;
            LATCbits.LC2=1;
            LATCbits.LC3=1;
            LATCbits.LC4=1;
            LATCbits.LC5=0;
            while(c[i]!='\0'){
                data(c[i]);
                i++;
            }
            delay();
        }
        else if(PORTCbits.RC7==1){
            int j=0;
            cmd(0x80);
            LATCbits.LC0=0;
            LATCbits.LC1=1;
            LATCbits.LC2=1;
            LATCbits.LC3=1;
            LATCbits.LC4=0;
            LATCbits.LC5=1;
            while(d[j]!='\0'){
                data(d[j]);
                j++;
            }
            delay();
        }
        else{
            LATC=0x00;
            cmd(0x01);
        }
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
}