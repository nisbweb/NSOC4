#include<avr/io.h>
#include<util/delay.h>      //used for delay function

void main(void)
{
DDRC=0xFF;                //declaring PORTC as output
while(1)                  //infinite loop
{
PORTC=0xFF;             //making all pins of PORTC HIGH
_delay_ms(1000);        //delay of 1000 ms
PORTC=0x00;             //making all pins of PORTC LOW
_delay_ms(1000);         //delay of 1000 ms
}
}
