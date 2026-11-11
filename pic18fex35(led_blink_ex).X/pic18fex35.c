/*
 * File:   pic18fex35.c
 * Author: rohit
 *
 * Created on 8 August, 2025, 10:13 AM
 */

/*************************************************************************
                              HEADER FILES
**************************************************************************/
#include<pic18.h>    
 
/*************************************************************************
                          FUNCTION DECLARATIONS
**************************************************************************/
void Delay_Ms(int ms);
 
/*************************************************************************
                              MAIN FUNCTION
**************************************************************************/
void main()
{
 TRISB=0x00;              /* PORTB configured as o/p                     */
 while(1)
 {
  PORTB=0xFF;             /* Make port pins high to turn on LEDs         */
  Delay_Ms(500);          /* Delay fuction called for 500ms              */
  PORTB=0x00;             /* Make port pins low to turn off LEDs         */
  Delay_Ms(500);          /* Delay fuction called for 500ms              */ 
 }
}   
 
/*************************************************************************
* Function    : Delay_Ms                                                 *
*                                                                        *
* Description : Function for delay                                       *
*                                                                        *
* Parameter   : ms - delay in milliseconds                               *
**************************************************************************/
void Delay_Ms(int ms)
{
 int i,count;
 for(i=1; i<=ms; i++)
 {
  count = 498;
  while(count != 1)
  {
   count--;
  }
 }
}
