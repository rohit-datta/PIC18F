/*
 * File:   sample.c
 * Author: LENOVO
 *
 * Created on 2 February, 2025, 5:52 PM
 */


#include <xc.h>
#include <stdbool.h>
#include <stdio.h>
#define _XTAL_FREQ 20000000
bool servo_state=false;
unsigned long adc_val;
int i=0;
float angle;
char arr[20];
void string(char *s);
void  __interrupt() ISR(){
    if(INTCONbits.INT0IF == 1){
        servo_state =~ servo_state;
        RC1=servo_state;
        INTCONbits.INT0IF = 0;
    }
    if(PIR1bits.TMR1IF==1){
        TMR1L = 0X08;
        TMR1H = 0XCF;
        RC0=1;
        PIR1bits.TMR1IF=0;
        
    }
    if(PIR1bits.CCP1IF==1){
        RC0=0;
        PIR1bits.CCP1IF=0;
        
    }
     
}

void main(){
    TRISA = 0X01;
    TRISC = 0X80;
    TRISB = 0X01;
    ADCON1 = 0X0E;
    ADCON2 = 0xA6;
    ADCON0 = 0x01;
    T0CON = 0Xc7;
    T1CON = 0X31;
    CCP1CON = 0X0a;
    TXSTA = 0X24;
    RCSTA = 0X90;
    SPBRG =129;
    TMR1L = 0X08;
    TMR1H = 0XCF;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.INT0IE = 1;
    PIE1bits.TMR1IE=1;
    PIE1bits.CCP1IE=1;
    RC0=1;
    while(1){
      if(servo_state==true){
          ADCON0bits.GODONE=1;
          while(ADCON0bits.GODONE);
          adc_val=ADRESL;
          adc_val |=(ADRESH<<8);
         unsigned long S_DV = 53622 + (adc_val * 631) / 1023;
          CCPR1L = (S_DV & 0xff);
          CCPR1H = ((S_DV>>8)&0xff);
          angle = (float)(((unsigned long)S_DV-53622)*180)/631;
          
          if(INTCONbits.TMR0IF==1){
          i++;
          if(i==30){
              sprintf(arr,"%0.3f\r",angle);
          string(arr);
          i=0;
          }
        INTCONbits.TMR0IF=0;
        
    }
      } 
      else{
          string("servo off\r");
       
             CCPR1L = (53622 & 0xff);
          CCPR1H = ((53622>>8)&0xff);
      }

  
}
}
    
void string(char *s){
    while(*s){ 
        while(!TXIF);
        TXREG = *s++;
       
       
    }
}

        
 
