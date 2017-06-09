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
int count;
for(count=0;count<100;count++){
TCCR0=0x05;
OCR0=156;
while((TIFR &0x02)==0);
TIFR=0x02;
TCNT0=0;
}

}