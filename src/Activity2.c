#include"Activity2.h"

void InitADC()
{
 ADMUX=(1<<REFS0);
 ADCSRA=(1<<ADEN)|(7<<ADPS0);
}


uint16_t ReadADC(uint8_t ch)
{
    
 ADMUX&=0xf8;
 ch=ch&0b00000111;
 ADMUX|=ch;
 ADCSRA|=(1<<ADSC);

 // Wait for conversion to complete
 while(!(ADCSRA & (1<<ADIF)));

 ADCSRA|=(1<<ADIF);

 return (ADC);
}