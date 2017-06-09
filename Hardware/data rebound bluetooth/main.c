#include<avr/io.h>
#include<util/delay.h>
#include "usart.h"
#include "hc06.h"

void main(){
char a;
usart_init();
while(1){
a=hc_06_bluetooth_receive_byte();

hc_06_bluetooth_transmit_byte(a);

}

}