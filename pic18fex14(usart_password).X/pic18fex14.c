/*
 * File:   pic18fex14.c
 * Author: rohit
 *
 * Created on 21 July, 2025, 10:43 AM
 */


#include <pic18.h>
#include <string.h>
void send(char a);
char recieve();
void main() {
    char b;
    int i=0,j,k=0;
    char a[]="1234";
    char c[5];
    char e[]="correct password";
    char d[]="incorect password"; 
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
        while(i<4){
            b=recieve();
            c[i]=b;
            i++;
        }
        if(strcmp(a,c)==0){
            while(e[k]!='\0'){
                send(e[k]);
                k++;
            }
            b=recieve();
            send(b);
        }
        else{
            i=0;j=0;
            while(d[j]!='\0'){
                send(d[j]);
                j++;
            }
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
    return RCREG;
    
}