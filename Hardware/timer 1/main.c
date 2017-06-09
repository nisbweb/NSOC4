#include<avr/io.h>


void delay();

void main(){
DDRB=0x01;

while(1){

PORTB=0x00;
delay();
PORTB=0x01;
delay();
}


}


void delay(){


TCNT1H=0xc2;
TCNT1L=0xf7;
TCCR1B=0x05;
while((TIFR&0x04)==0);
TIFR=0x04;



}