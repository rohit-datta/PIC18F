#include<xc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000

unsigned int value;
char buffer[25];
void display(char *ptr);
int count=1;

void main()
{
    TRISD=0X00;
    TRISC=0X04;
    T3CON=0X71;
    CCP1CON=0X05;
    TMR3L=0X00;
    TMR3H=0X00;
    TXSTA=0X24;
    RCSTA=0X90;
    BAUDCON=0X00;
    SPBRG=129;
            
    while(1)
    {
        if(CCP1IF==1)
        {
            value =  CCPR1L;
            value |= CCPR1H<<8;
            sprintf(buffer,"captured value %d: %u\r\n",count,value);
            display(buffer);
            count++;
            CCP1IF=0;
                
        }
    }    
}
void display(char *ptr) {
    while (*ptr != '\0') 
    {
       while(!TXIF);
        TXREG=*ptr; 
        ptr++;       
    }
}