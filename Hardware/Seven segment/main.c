#include<avr/io.h>
 
#include<util/delay.h>
 
int ar[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
 
void main(void)
  {
     unsigned int i;
     DDRC=0XFF;
     while(1)
      {
         for(i=0;i<10;i++)
           {
             PORTA=ar[i];
             _delay_ms(300);
           }
      }      
  }