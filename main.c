/**
 * @file main.c
 * @author NIKITHA
 * @brief Activity1 LED is ON only when Heater is ON and Occupancy of Person is Detected
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#include"Activity1.h"
#include"Activity2.h"
#include"Activity3.h"
#include"Activity4.h"


/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void)
{
	/* Configure LED Pin */
	DDRB |= (1 << DDB0);
}

void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}


int main(void)
{
    InitADC();
    uint16_t temp;

DDRB&=~(1<<PD0);
DDRB&=~(1<<PD4);

PORTD|=(1<<PD0);
PORTD|=(1<<PD4);


	peripheral_init();

    while(1)
    {
       if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD4)))
       {
           
           change_led_state(LED_ON);
           temp= ReadADC(0);
		   delay_ms(LED_ON_TIME);
           delay_ms(200);

           USARTWriteData(temp);

           if(0b0000000000000000 <= temp  && temp <= 0b0000000011001000)
           {
               OCR0A=51; //20%
               delay_ms(200);
           }
           else if (0b0000000011001001 <= temp && temp <= 0b0000000111110100)
           {
                OCR0A=102; //40%
               delay_ms(200);
           }
           else if(0b0000000111110101 <= temp && temp <= 0b0000001010111100)
           {
               OCR0A=179; //70%
               delay_ms(200);
           }
           else 
           {
               OCR0A=243; //95%
               delay_ms(200);
           }

       }
       else
       {
           change_led_state(LED_OFF);
		   delay_ms(LED_OFF_TIME);	
       }
    }

    return 0;
}
