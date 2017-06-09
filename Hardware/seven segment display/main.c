#include<avr/io.h>
#include<util/delay.h>

//1234567=abcdef

void main(){
int i;
int a[]={0b01000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0x00,0b10011000};

DDRB=0xff;
while(1){
for(i=0;i<9;i++){
PORTB=a[i];
_delay_ms(1000);
}
}
}