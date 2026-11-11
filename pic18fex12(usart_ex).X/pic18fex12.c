/*
 * File:   pic18fex12.c
 * Author: rohit
 *
 * Created on 18 July, 2025, 10:00 AM
 */


#include <pic18.h>
void send(char a);
char recieve();
void main() {
    char b;
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
        send(b);
       
    }
}
void send(char a)
{
    while(TXIF==0);
    TXREG=b;
}
char recieve(){
    while(RCIF==0);
    return RCREG;
    
}