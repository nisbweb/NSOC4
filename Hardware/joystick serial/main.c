#include<avr/io.h>
#include<util/delay.h>
#include"adc.h"
#include"uart.h"
void main()
{
uartinit();
adc_init();
while(1)
{
int x=getdata(0x00);
int y=getdata(0x01);
printnum(x);
printchar('\t');
printnum(y);
printstring("\n\r");
_delay_ms(100);
}
}