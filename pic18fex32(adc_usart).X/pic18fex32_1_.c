/*
 * File:   sample.c
 * Author: LENOVO
 *
 * Created on 17 April, 2025, 9:39 AM
 *makig a delay of 10 ms*/

#define F_CPU 8000000UL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
int result;
char buffer[5];
void transmit(const char *data){
    while(*data){
        while(!(UCSRA & (1<<UDRE)));
        UDR = *data++;
  
    }
}

void main(void) {
    DDRD |= (1<<PD1);
    DDRD &= ~(1<<PD0);
    PORTD = 0x00;
    DDRA = 0X00;
    PORTA = 0X00;
    UCSRA = 0X00;
    UCSRB = 0X18;
    UCSRC = 0X86;
    UBRRL = 51;
    ADMUX = 0X00;
    SFIOR = 0X00;
    ADCSRA = 0X86;
    transmit("ADC value\r\n\t");
    while(1){
        
        ADCSRA |=(1<<6);
        while((ADCSRA & (1<<6)));
        result = ADCL;
        result |= (ADCH<<8);
        sprintf(buffer,"%d",result);
        transmit(buffer);
        transmit("\r\n");
      
    }
 
  return;
}