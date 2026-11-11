/*
 * File:   pic18fex15.c
 * Author: rohit
 *
 * Created on 22 July, 2025, 11:03 AM
 */


#include <pic18.h>
void delay();
void cmd(char a);
void data(char b);
void send(char c);
char recieve();
void main(void) {
    char d;
    TRISC=0x80;
    TRISD=0x00;
    BRGH=0;
    BRG16=0;
    SYNC=0;
    SPEN=1;
    TXEN=1;
    CREN=1;
    //RCSTA=0x90;
    //TXSTA=0x20;
    SPBRG=31;
    cmd(0x06);
    cmd(0x01);
    cmd(0x0C);
    cmd(0x38);
    while(1){
        d=recieve();
        send(d);
        data(d);
    }
    return;
}
void delay(){
    for(int i=0;i<100;i++){
        for(int j=0;j<50;j++);
    }
}
void cmd(char a){ 
    LATCbits.LC4=0;
    LATD=a;
    LATCbits.LC5=1;
    delay();
    LATCbits.LC5=0;
}
void data(char b){
    LATCbits.LC4=1;
    if(b==0x08){
        cmd(0x10);
        LATCbits.LC4=1;
        LATD=0x20;
        LATCbits.LC5=1;
        delay();
        LATCbits.LC5=0;
        cmd(0x10);
    }
    else{
        LATD=b;
        LATCbits.LC5=1;
        delay();
        LATCbits.LC5=0;
    }
}
void send(char c)
{
    while(TXIF==0);
    TXREG=c;
}
char recieve(){
    while(RCIF==0);
    return RCREG;
    
}