/*
 * File:   pic18fex8.c
 * Author: rohit
 *
 * Created on 4 July, 2025, 9:29 AM
 */


#include <pic18.h>
void cmd(char a);
void data(char b);
void delay();
void main() {
    int i=0,j=0;
    char c[]="rohit datta";
    char d[]="GET";
    TRISC=0x00;
    TRISD=0x00;
    cmd(0x06);
    cmd(0x01);
    cmd(0x0C);
    cmd(0x80);
    cmd(0x38);
    while(c[i]!='\0'){
        data(c[i]);
        i++;
    }
    cmd(0xC0);
    while(d[j]!='\0'){
        data(d[j]);
        j++;        
    }
    while(1);
}
void cmd(char a){
    LATCbits.LC0=0;
    LATD=a;
    LATCbits.LC1=1;
    delay();
    LATCbits.LC1=0;
}
void data(char b){
    LATCbits.LC0=1;
    LATD=b;
    LATCbits.LC1=1;
    delay();
    LATCbits.LC1=0;
}
void delay(){
    for(int i=0;i<100;i++){
        for(int j=0;j<50;j++);
    }
}