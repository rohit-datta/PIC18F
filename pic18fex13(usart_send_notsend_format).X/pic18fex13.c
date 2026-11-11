/*
 * File:   pic18fex13.c
 * Author: rohit
 *
 * Created on 21 July, 2025, 10:14 AM
 */


#include <pic18.h>
#include<stdbool.h>
void send(char a);
char recieve();
void main() {
    char b;
    bool i;
    TRISC=0x80;
    BRGH=0;
    BRG16=0;
    SYNC=0;
    SPEN=1;
    TXEN=1;
    CREN=1;
    //RCSTA=0x90;
    //TXSTA=0x20;
    SPBRG=31;
    
    while(1){
        b=recieve();
        if(b=='*')i=true;
        if(b=='#')i=false;
        if(i==true)send(b);
    }
}
void send(char a)
{
    while(TXIF==0);
    TXREG=a;
}
char recieve(){
    while(RCIF==0);
    return RCREG;
    
}