        


#ifndef _UART_H_
#define _UART_H_

void uartinit()
{
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x86;
	UBRRH=0x00;
	UBRRL=103;
	delayuart(1000);
}

void printchar(unsigned char uchar)
{
  UDR=uchar;
  while((UCSRA&0x40)==0x00);
  delayuart(1000);
}
 
void printstring(const unsigned char *ustring)
{
   while ( *ustring )
    {
	 printchar( *ustring++);
	
}	}

 
void printnum(unsigned int num)
{
    unsigned char paa=0, H=0,T=0,O=0;
	paa=num/1000;
	
	H=(num-(paa*1000))/100;
	T=(num -(paa*1000) -(H*100))/10;
	O=(num - (paa*1000) -(H*100) - (T*10));
	
	if(paa!=0)
	{printchar(paa+48);}
	printchar(H+48);
	
	printchar(T+48);
	
	printchar(O+48);
	
}
 
 
unsigned char dispdata()
{
  while((UCSRA&0x80)==0x00);
  return UDR;
}
 
void delayuart(unsigned int delaytime)
{
unsigned int dc;
	 for(dc=0;dc<=delaytime;dc++)
	 {
		 
		  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		  asm("nop");asm("nop");asm("nop");asm("nop");
	 }
}


#endif 
