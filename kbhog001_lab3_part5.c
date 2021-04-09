/*	Author: Karan Bhogal
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRD = 0x000; PORTD = 0xFFF;
	DDRB = 0xFFE; PORTB = 0x001;
	unsigned char tmpD = 0x000;
	unsigned char tmpB = 0x00;


    /* Insert your solution below */
    while (1) {
	tmpD = PIND;
	tmpB = 0x000;
	tmpD = tmpD << 1;
	tmpD = tmpD | PINB;

	if ( (PIND & 0x080) == 0x080){
		tmpB = tmpB | 0x002;
	}
	else if ( tmpD >= 70){
		tmpB = tmpB | 0x002;
	}
	else if (tmpD > 5){
		tmpB = tmpB | 0x004;
	}

	PORTB = tmpB;
    }
    return 1;
}
