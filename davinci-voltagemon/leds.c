#include "leds.h"
#include <avr/io.h>

void setLED(int led, led_state color){
	switch(led){
		case 0:
			switch(color){
				case OFF: set_0_OFF(); break;
				case RED: set_0_RED();break;
				case GREEN: set_0_GRN(); break;
				case YELLOW: set_0_YEL(); break;
			}
		break;
		case 1:
			switch(color){
				case OFF: set_1_OFF(); break;
				case RED: set_1_RED();break;
				case GREEN: set_1_GRN(); break;
				case YELLOW: set_1_YEL(); break;
			}

		break;
		case 2:
			switch(color){
				case OFF: set_2_OFF(); break;
				case RED: set_2_RED();break;
				case GREEN: set_2_GRN(); break;
				case YELLOW: set_2_YEL(); break;
			}
		break;
		case 3:
			switch(color){
				case OFF: set_3_OFF(); break;
				case RED: set_3_RED();break;
				case GREEN: set_3_GRN(); break;
				case YELLOW: set_3_YEL(); break;
			}
		break;
		default: break;
	
	}
	
}


void initLEDs(){
    set_1_dir();set_2_dir();set_3_dir();set_0_dir();
    set_1_RED();set_2_RED();set_3_RED();set_0_RED();
}
