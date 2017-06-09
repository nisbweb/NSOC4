#include<avr/io.h>
#include<util/delay.h>
#include "adc.h"

void main()
{
int x,y;
adc_init();	//ADC initialisation
DDRD=0xff;	//PORT B as output
while(1)
{
x=getdata(0x00);
y=getdata(0x01);

if(x>516)
	PORTD=0x04;	//left	
if(x<516)
	PORTD=0x02;	//right
 if(y<529)
	PORTD=0x06;	//forward
if(y>529)
	PORTD=0x09;	//backward
else
	PORTD=0x00;	//hault

}
}