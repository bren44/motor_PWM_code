/*
 * MotorPWM.c
 *
 *  Created on: 3 Mar 2017
 *      Author: brendanelmes
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void init_pwm(void);

int main(void) {
	uint8_t duty = 12;
	init_pwm();
	for(;;){
		OCR0A = 47;
		_delay_ms(10000);
		for (duty = 47; duty < 93; duty += 1) { //increase duty cycle from 0-100%
		      OCR0A = duty;
		      _delay_ms(100);
			}
		  for (duty = 93; duty >= 47; duty -= 1) { //decrease duty cycle from 100% to 0%
		      OCR0A = duty;
		      _delay_ms(100);
		  }
	}
}

void init_pwm(void)
{
	  DDRB |= _BV(PB3); 								//Set Pin B3 as output
	  TCCR0A = _BV(COM0A1) |_BV(WGM00) | _BV(WGM01);	//Set non-inverting PWM mode set fast PWM with top value = OCRA
	  TCCR0B = _BV(CS02);				//Set Clock select to give prescaler 256
}
