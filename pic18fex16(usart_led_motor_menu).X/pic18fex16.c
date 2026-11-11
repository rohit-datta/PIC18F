/*
 * File:   pic18fex16.c
 * Author: rohit
 *
 * Created on 23 July, 2025, 9:24 AM
 */


#include <pic18.h>
void send(char a);
char recieve();
void display(char *p);

void main(void) {
    char b;
    char c[]="anti-clockwise";
    char d[]="clockwise";
    char e[]="LED";
    char f[]="invalid-option";
    ADCON1=0x0F;
    TRISA=0X00;
    TRISC=0x80;
    RCSTA=0x90;
    TXSTA=0x20;
    SPBRG=31;
    while(1){
        b=recieve();
        if(b=='a'){
            PORTA=0x05;
            display(d);
        }
        else if(b=='c'){
            PORTA=0x06;
            display(c);
        }
        else if(b=='l'){
            PORTA=0x08;
            display(e);
        }
        else{
            display(f);
            PORTA=0x00;
        }
    }
    return;
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
void display(char *p){
    while(*p!='\0'){
        send(*p);
        p++;
    }
    send(0x0D);
}