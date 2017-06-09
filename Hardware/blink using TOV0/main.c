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
int cnt;

for(cnt=0;cnt<100;cnt++){
TCCR0=0x05;//Prescalar=1024. So Fosc is 16Mhz/1024; Tosc=1/Fosc
TCNT0;//laod beforehand as we need 


while((TIFR&0x01)==0);
TIFR=0x01;


}
}