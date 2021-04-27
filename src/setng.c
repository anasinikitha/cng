#ifndef __AVR_ATmega328__
  #define __AVR_ATmega328__
#endif
#include<avr/io.h>

int main(void)
{

DDRB|=(1<<PB0); //set this

DDRB&=~(1<<PD0);
DDRB&=~(1<<PD4);

PORTD|=(1<<PD0);
PORTD|=(1<<PD4);

    while(1)
    {
       if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD4)))
       {
           PORTB|=(1<<PB0);
          // _delay_ms(2000);
       }
       else
       {
           PORTB&=~(1<<PB0);
           //_delay_ms(2000);
       }
    }

    return 0;
}
