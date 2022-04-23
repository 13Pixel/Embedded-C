#include <avr/io.h>
#include <stdio.h>

#include <util/delay.h>
#include <stdint.h>
#include "usart_printf.h"

#define F_CPU 16000000
#define BLINK_DELAY_MS 100

int main(void)
{
  usart_initialize();
  stdout = &uart_output;


  // Arduino digital pin 13 (pin 5 of PORTB) for output
  DDRB |= 0B100000; // PORTB5
  int x = 0;
  while (1)
  {
    // turn LED on
    PORTB |= 0B100000; // PORTB5
    //printf("labas: %d", x);
    x++;
    _delay_ms(BLINK_DELAY_MS);

    // turn LED off
    PORTB &= ~0B100000; // PORTB5
    _delay_ms(BLINK_DELAY_MS);
  }
}

void _putchar(char character) {}
