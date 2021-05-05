#include"Activity1.h"
#include"Activity2.h"
#include"Activity3.h"
#include"Activity4.h"

void peripheral_init(void)
{
	/* Configure LED Pin */
	 DDRB |= (1 << DDB0);
     DDRD&=~(1<<PD0);
     DDRD&=~(1<<PD4);
	 DDRD&=~(1<<PD6);

     PORTD|=(1<<PD0);
     PORTD|=(1<<PD4);

	 InitADC();//Initialise ADC
     InitPwm();//Initialization for PWM output
	 USARTInit(103);//USART Initiation

}



void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}


/**
 * @brief Main function where the code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 */
int main(void)
{
	/* Initialize Peripherals */
	peripheral_init();

	for(;;)
	{
        if(!(PIND &(1<<PD0)) && !(PIND &(1<<PD4)))
        {
			uint16_t temp;
          change_led_state(LED_ON);
		  delay_ms(LED_ON_TIME);
		  temp= ReadADC(0);
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
