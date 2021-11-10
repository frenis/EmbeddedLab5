#include <msp430.h> 

#define LED_GREEN BIT0
#define LED_RED BIT6

/**
 * main.c
 * Lab 5 Question 1
 */
void main(void)
{
	BCSCTL2 |= DIVS_3;
    WDTCTL = WDT_MDLY_32;
    IE1 |= WDTIE;

	P1DIR = 0x41;
	P1OUT = 0x01;   // green LED on first
	
	_enable_interrupts();

	while(1);
}

#pragma vector=WDT_VECTOR
__interrupt void WDT(void) {
    P1OUT ^= LED_GREEN|LED_RED;  //toggle LEDs
}
