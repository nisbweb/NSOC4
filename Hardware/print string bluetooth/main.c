#include<avr/io.h>
#include<util/delay.h>
#include "usart.h"

void main()
{

usart_init();

while(1){
usart_string_transmit("NSOC 4.0\n\r");
_delay_ms(10);

}


}