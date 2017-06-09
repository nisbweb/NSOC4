#include<avr/io.h>
#include<util/delay.h>
#include "uart.h"

void main(){
	
	uartinit();
	
	while(1){
	printnum(10);
printstring("\n\r");
_delay_ms(10);
}

}		