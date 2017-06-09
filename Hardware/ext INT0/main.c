#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

ISR(INT0_vect){
int i;

for(i=0;i<4;i++){
PORTB=0x01;
_delay_ms(10);
PORTB=0x00;
_delay_ms(10);

}


}



void main(){
DDRD=0x01;
PORTD=0b00000100;//pull up as interrupt is also a reg
DDRB=0x01;//making LED o/p
MCUCR=0x01;//triggering
GICR=0x40;//enable int0/1/2
sei();//global interrupt enable


while(1){
PORTB=0x00;
_delay_ms(100);
PORTB=0x01;
_delay_ms(100);

}


}