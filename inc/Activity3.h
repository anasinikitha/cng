#ifndef __ACTIVITY3_H_
#define __ACTIVITY3_H_
/**
 * @file ACTIVITY1.h
 * @author Nikitha A ()
 * @brief Activity3 to see variation of temperature in CRO connected to AVR328 MCU GPIO Pin when heater button is presses
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __AVR_ATmega328__
  #define __AVR_ATmega328__
#endif

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#include<avr/io.h>
#include<util/delay.h>

 


void InitPwm();

#endif