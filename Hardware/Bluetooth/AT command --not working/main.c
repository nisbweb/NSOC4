#include<avr/io.h>
#include<util/delay.h>
#include "uart.h"
#include "hc06.h"

void main(){
int i;
char hc_06_buffer1[3];
usart_init();

usart_string_transmit("AT");
	for(unsigned char i=0; i<2;i++)
	{
		hc_06_buffer1[i]=usart_data_receive();
	}
	hc_06_buffer1[2]=0;
	if(!(strcmp(hc_06_buffer1,"OK")))
	{
		usart_string_transmit("OK");
	}
	else
	{
		usart_string_transmit("NOT");
	}

}