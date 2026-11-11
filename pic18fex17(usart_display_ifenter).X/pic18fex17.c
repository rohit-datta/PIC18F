/*
 * File:   pic18fex17.c
 * Author: rohit
 *
 * Created on 24 July, 2025, 10:18 AM
 */


#include<pic18.h>
char recieve();
void send(char a);
void display(char *p);
int i=0;
void main(){
    char b[10];
    RCSTA=0x90;
    TXSTA=0x20;
    TRISC=0X80;
    SPBRG=31;
    while(1){
        b[i]=recieve();
        if(b[i-1]=='\r'){
            display(b);
        }
    }
}
void send(char a)
{
    while(TXIF==0);
    TXREG=a;
}
char recieve(){
    while(RCIF==0);
    i++;
    return RCREG;

}
void display(char *p){
    while(*p!='\r'){
        send(*p);
        p++;
    }
    send('\r');
    i=0;
}