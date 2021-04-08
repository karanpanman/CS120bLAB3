/*	Author: Karan Bhogal
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #1
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;	
	unsigned char cntavail = 0x00;
	unsigned int i;
    /* Insert your solution below */
    while (1) {
	cntavail = 0;
	tmpA = PINA;
	tmpB = PINB;

	for ( i = 0; i < 8; i++ ){
		if ( (tmpA & 0x01 ) == 1  ){
			cntavail = cntavail + 1;
		}
		tmpA = tmpA >> 1;		
	}
	
	for ( i = 0; i < 8; i++ ){
                if ( (tmpB & 0x01 ) == 1  ){
                        cntavail = cntavail + 1;
                }
                tmpB = tmpB >> 1;
        }			
	
	PORTC = cntavail;
    }
    return 1;
}
