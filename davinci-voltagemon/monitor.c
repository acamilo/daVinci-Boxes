/*
 * ATtiny13 LED Flasher
 * File: main.c
 */

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h> 
#include "monitor.h"
#include "leds.h"
#include "adc.h"

led_state logic,rail1,rail2,rail3;

int main(void)
{
    const int msecsDelayPost = 10;
    initADC();
    initLEDs();
    initTimer();


    while (1) {
	checkRails();
	
	//setLED(1, YELLOW);
	setLEDs();

	 _delay_ms(10);

    }

    return 0;
}

void checkRails(){
		/*
		if (getVCCVolts() > v24_upper) { set_1_YEL(); }
		else if (getVCCVolts() < v24_lower) { set_1_RED(); }
		else { set_1_GRN();	}
		*/
		
		unsigned long int voltage = getAdc(0);
		voltage = getAdc(0);
		if (voltage >= rail1_upper) { rail1  = HIGH; }
		else if ((voltage <rail1_upper) && (voltage >= rail1_lower)) { rail1=NOMINAL; }
		else if ((voltage < rail1_lower) && (voltage >= rail_min )) { rail1= LOW; }
		else { rail1 = NONE;	}

		voltage = getAdc(1);
		if (voltage >= rail2_upper) { rail2  = HIGH; }
		else if ((voltage <rail2_upper) && (voltage >= rail2_lower)) { rail2=NOMINAL; }
		else if ((voltage < rail2_lower) && (voltage >= rail_min )) { rail2= LOW; }
		else { rail2 = NONE;	}
#ifdef master
		voltage = getAdc(2);
		if (voltage >= rail3_upper) { rail3  = HIGH; }
		else if ((voltage <rail3_upper) && (voltage >= rail3_lower)) { rail3=NOMINAL; }
		else if ((voltage < rail3_lower) && (voltage >= rail_min )) { rail3= LOW; }
		else { rail3 = NONE;	}
#endif
}

void setLEDs(){

/*
	switch(logic){
		case NONE: setLED(0,RED);break;
		case LOW: setLED(0,RED);break;
		case NOMINAL: setLED(0,GREEN);break;
		case HIGH: setLED(0,YELLOW);break;
	}
*/
	switch(rail1){
		case NONE: setLED(0,RED);break;
		case LOW: setLED(0,RED);break;
		case NOMINAL: setLED(0,GREEN);break;
		case HIGH: setLED(0,YELLOW);break;
	}

// force 1,0 off
//set_0_undir();
//set_1_undir();
	switch(rail2){
		case NONE: setLED(1,RED);break;
		case LOW: setLED(1,RED);break;
		case NOMINAL: setLED(1,GREEN);break;
		case HIGH: setLED(1,YELLOW);break;
	}
#ifdef master
	switch(rail3){
		case NONE: setLED(2,RED);break;
		case LOW: setLED(2,RED);break;
		case NOMINAL: setLED(2,GREEN);break;
		case HIGH: setLED(2,YELLOW);break;
	}
#endif

#ifdef master
#else
	set_2_undir();
#endif
set_3_undir();
}



void initTimer(){

TCCR1A = 0x00; 
TCCR1B |= _BV(CS10) | _BV(CS11)  | _BV(CS13); 

TIMSK = _BV(OCIE1A); 

OCR1A = 5; 


   sei();
}

int state=0;
ISR(TIMER1_COMPA_vect) {
	/*if (state & logic==NONE) {set_0_undir();}
	else {set_0_dir();}*/

	if (state & rail1==NONE) {set_0_undir();}
	else {set_0_dir();}

	if (state & rail2==NONE) {set_1_undir();}
	else {set_1_dir();}
#ifdef master
	if (state & rail3==NONE) {set_2_undir();}
	else {set_2_dir();}
#endif
	state = ~state;
}

