#include <msp430.h> 

#define BUTTON1 BIT1

/**
 * main.c
 * Lab 5 Question 3
 */
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop WDT

    P1DIR |= BIT6;             // P1.6 to output
    P1SEL |= BIT6;             // P1.6 to TA0.1
    P1SEL2 &= ~BIT6;             // P1.6 to TA0.1
    P1REN |=  BUTTON1;         // Enables resistor
    P1OUT |=  BUTTON1;         // Pull-up Resistor
    P1IE  |=  BUTTON1;         // Enables interrupt
    P1IES |= ~BUTTON1;         // Falling edge select
    P1IFG &= ~BUTTON1;         // Clears any flags

    TA0CTL = TASSEL_2 + MC_1+ID_3;//+TACLR;
    TA0CCR0 = 31249; // Set maximum count value (PWM Period
    TA0CCR1 = 6250; // initialise counter compare value
    TA0CCTL1 = OUTMOD_7;        // PWM set to reset

    _enable_interrupts(); // Enter LPM0
	
}

#pragma vector=PORT1_VECTOR         // Button interrupt
__interrupt void Port_1(void) {
    P1OUT ^=BIT6;
    P1IFG &= ~BUTTON1;
}
