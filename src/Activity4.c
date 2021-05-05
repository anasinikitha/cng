#include"Activity4.h"

void USARTWriteData(uint16_t data)
{
 //wait until transmitter is ready
while(!(UCSR0A & (1<<UDRE0)))
 {
   //DO NOTHING
  }
  // NOW WRITE DATA TO USART BUFFER
  UDR0=data;
}
void USARTInit(uint16_t ubrr_value)
{
 //set Baud rate
 UBRR0L= ubrr_value;
 UBRR0H=(ubrr_value>>8)&(0x00ff);
UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

//ENABLE RECEIVER AND TRANSMITTER
 UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}