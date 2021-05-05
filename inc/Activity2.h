#ifndef __ACTIVITY2_H_
#define __ACTIVITY2_H_

#ifndef __AVR_ATmega328__
  #define __AVR_ATmega328__
#endif


#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#include<avr/io.h>
#include<util/delay.h>

void InitADC();

uint16_t ReadADC(uint8_t ch);


#endif