#include"Activity3.h"
 
 void InitPwm()
 {
      TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
      TCCR0B|=(1<<CS01)|(1<<CS00);
      //DDRD|=(1<<PB0);
      OCR0A=255;
 }
