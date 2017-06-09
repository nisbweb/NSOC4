#include<avr/io.h>
#include<util/delay.h>
#include "adc.h"
#include <stdio.h>
#include <stdlib.h>

void cmd(unsigned char);
void data(unsigned char);

void main(){
char c[10];
int i=1000,j;
DDRB=0xff;
DDRD=0xff;


cmd(0x0C);
cmd(0x01);
cmd(0x80);
cmd(0x38);


adc_init();


while(1){
i=getdata(0x01);
itoa(i,c,10);
for(j=0;j<4;j++)
{
data(c[j]);

}
_delay_ms(50);
cmd(0x01);

}

}


void cmd(unsigned char a){
PORTB=a;
PORTD=0x04;
_delay_ms(1);
PORTD=0x00;
_delay_ms(1);



}

void data(unsigned char a){
PORTB=a;
PORTD=0x05;//making en and rs as 1
_delay_ms(1);
PORTD=0x00;
_delay_ms(1);


}