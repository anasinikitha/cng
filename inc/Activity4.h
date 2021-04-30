#ifndef __ACTIVITY4_H_
#define __ACTIVITY4_H_
/**
 * @file ACTIVITY1.h
 * @author Nikitha A ()
 * @brief Activity3 to see variation of temperature in CRO connected to AVR328 MCU GPIO Pin when heater button is presses
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __AVR_ATmega328__
  #define __AVR_ATmega328__
#endif

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#include<util/delay.h>

#include<avr/io.h>
/**
 * @brief Function for Initializing USART operation
 * 
 */
void USARTInit(uint16_t);

/**
 * @brief Function for USRAT write operation
 * 
 */
void USARTWriteData(uint16_t);

#endif
