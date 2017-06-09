

#ifndef _ADC_H_
#define _ADC_H_						//This is the header for AVR Microcontroller.
#include<avr/io.h>
#include<util/delay.h>		//header file for genarating time delay
		//headerfile for interfacing LCD
#include<avr/interrupt.h>			//header file for using interrupt service routins


 void adc_init()
 {
  ADCSRA=0XE6;						//ADC enable, ADC interrupt enable, set prescaller to 64
  		
 }
 unsigned int getdata(unsigned char chno)	
  {
	unsigned int adcdata,adcdata1;
    ADMUX=0X40;						//right align the ADC result
    ADMUX|=chno;					//select the ADC channel
    //ADCSRA|=0X40;					//start ADC convertion
    _delay_ms(1);
adcdata1=ADCL;					//give some time delay to complit the aDC convertion
	adcdata=ADCH;
	
	adcdata1+=(adcdata<<8);
	return (adcdata1);
	
	
  }

#endif 