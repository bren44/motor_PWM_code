/*
 * 4_seeeduino_motor_pwm.c
 *
 *  Created on: 5 Mar 2017
 *      Author: brendanelmes
 */
#include <avr/io.h>
#include <util/delay.h>

void init_pwm(void);

int main(void)
{
        uint8_t duty = 50;		//initialize variable to hold duty cycle (43 -97)
	init_pwm();
	for(;;)
        {
            OCR0A = duty;
            OCR0B = duty;
            OCR2A = duty;
            OCR2B = duty;
        }
}

//function which sets the pwm mode, frequency and pins
void init_pwm(void)
{
	//set initial value for OCRs
	OCR0A = 6;
	OCR0B = 6;
	OCR2A = 6;
	OCR2B = 6;

	//set output pins for OCRs
        DDRB |= _BV(PB1);
        DDRB |= _BV(PB2);
        DDRB |= _BV(PB3);
        DDRD |= _BV(PD3);

	//set input pins for incoming instructions
        //DDRB &= ~_BV(PB1);
        //DDRB &= ~_BV(PB2);
        //DDRB &= ~_BV(PB3);
        //DDRD &= ~_BV(PD3);

	//set non-inverting mode fast PWM with top value 0xFF (not OCR)
	TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM00) | _BV(WGM01);
	TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM20) | _BV(WGM21);
        //select clock to give prescaler 256, giving a frequency of --Hz
        TCCR0B = _BV(CS02);
        TCCR2B = _BV(CS22) | _BV(CS21);
}
