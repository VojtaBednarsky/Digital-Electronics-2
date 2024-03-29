/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-09-27
 * Last update: 2019-07-16
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: Blink a LED with delay function.
 * TODO: Verify functionality of LED blinker.
 * NOTE: Macro _BV converts a bit number into a byte value (see AVR Libc
 * Reference Manual).
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>
#include <gpio.h>

/* Typedef -----------------------------------------------------------*/
/* ahoj Define ------------------------------------------------------------*/
#define LED_PIN     PB5
#define LED_PIN1    PB0
#define BLINK_DELAY 250
#define BUTTON      PD2
 
/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
  * Brief:  Main program. Blink a LED with delay function.
  * Input:  None
  * Return: None
  */
int main(void)
{
    /* Set output pin */

    /*DDRD &= ~_BV(BUTTON);*/
    GPIO_config_output(&DDRB, LED_PIN1);
    GPIO_config_output(&DDRB, LED_PIN);
    GPIO_config_input_pullup(&DDRD, &PORTD, BUTTON);

    /* Turn LED off */

    /*PORTD |= _BV(BUTTON);*/ 
     GPIO_write(&PORTB, LED_PIN1, 1);
     GPIO_write(&PORTB, LED_PIN, 0);

    /* Infinite loop */
  
    for (;;)
    {
      /* Invert LED and delay */
      //if (GPIO_read(&PIND, BUTTON) == 0)
      
      if(bit_is_clear(PIND, BUTTON))
      {
        GPIO_toggle(&PORTB, LED_PIN1);
        GPIO_toggle(&PORTB, LED_PIN);
        _delay_ms(BLINK_DELAY);
      }
    }

    return (0);
}

