# EmbeddedLab5
## Lab5_1.c
This is the code for part 1. It toggles the red and green LEDs every 256ms. The WDT is put into timer mode and used as the timer to toggle the LEDs.
## Lab5_2.c
This is the code for part 2, the software PWM. It has a duty cycle of 10% and a period of 500ms. TimerA is used as the timer for the PWM and it uses the SMCLK with a divider of 8.
## Lab5_3.c
This is the code for part 3, the hardware PWM. It has a duty cycle of 20% and a period of 250ms. TimerA is used as the timer for the PWM and it uses the SMCLK with a divider of 8.
