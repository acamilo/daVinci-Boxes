#ifndef leds_H
#define leds_H

#ifndef swapleds
	#define LED0_GRN		(1<<PA4)
	#define LED0_GRN_DIR	(1<<DDA4)
	#define LED0_RED		(1<<PA5)
	#define LED0_RED_DIR	(1<<DDA5)

	#define LED1_GRN		(1<<PA6)
	#define LED1_GRN_DIR	(1<<DDA6)
	#define LED1_RED		(1<<PA7)
	#define LED1_RED_DIR	(1<<DDA7)

	#define LED2_GRN		(1<<PB3)
	#define LED2_GRN_DIR	(1<<DDB3)
	#define LED2_RED		(1<<PB4)
	#define LED2_RED_DIR	(1<<DDB4)

	#define LED3_GRN		(1<<PB5)
	#define LED3_GRN_DIR	(1<<DDB5)
	#define LED3_RED		(1<<PB6)
	#define LED3_RED_DIR	(1<<DDB6)
#else
	#define LED0_RED		(1<<PA4)
	#define LED0_RED_DIR	(1<<DDA4)
	#define LED0_GRN		(1<<PA5)
	#define LED0_GRN_DIR	(1<<DDA5)

	#define LED1_RED		(1<<PA6)
	#define LED1_RED_DIR	(1<<DDA6)
	#define LED1_GRN		(1<<PA7)
	#define LED1_GRN_DIR	(1<<DDA7)

	#define LED2_RED		(1<<PB3)
	#define LED2_RED_DIR	(1<<DDB3)
	#define LED2_GRN		(1<<PB4)
	#define LED2_GRN_DIR	(1<<DDB4)

	#define LED3_RED		(1<<PB5)
	#define LED3_RED_DIR	(1<<DDB5)
	#define LED3_GRN		(1<<PB6)
	#define LED3_GRN_DIR	(1<<DDB6)
#endif

#define set_0_OFF()		{PORTA &= ~(LED0_GRN+LED0_RED);}
#define set_0_dir()		{DDRA |= LED0_GRN_DIR+LED0_RED_DIR;}
#define set_0_undir()		{DDRA &= ~(LED0_GRN_DIR+LED0_RED_DIR);}
#define set_0_RED()		{PORTA &= ~(LED0_GRN+LED0_RED); PORTA |= LED0_RED;}
#define set_0_GRN()		{PORTA &= ~(LED0_GRN+LED0_RED); PORTA |= LED0_GRN;}
#define set_0_YEL()		{PORTA &= ~(LED0_GRN+LED0_RED); PORTA |= LED0_GRN+LED0_RED;}

#define set_1_OFF()		{PORTA &= ~(LED1_GRN+LED1_RED);}
#define set_1_dir()		{DDRA |= LED1_GRN_DIR+LED1_RED_DIR;}
#define set_1_undir()		{DDRA &= ~(LED1_GRN_DIR+LED1_RED_DIR);}
#define set_1_RED()		{PORTA &= ~(LED1_GRN+LED1_RED); PORTA |= LED1_RED;}
#define set_1_GRN()		{PORTA &= ~(LED1_GRN+LED1_RED); PORTA |= LED1_GRN;}
#define set_1_YEL()		{PORTA &= ~(LED1_GRN+LED1_RED); PORTA |= LED1_GRN+LED1_RED;}

#define set_2_OFF()		{PORTB &= ~(LED2_GRN+LED2_RED);}
#define set_2_dir()		{DDRB |= LED2_GRN_DIR+LED2_RED_DIR;}
#define set_2_undir()		{DDRB &= ~(LED2_GRN_DIR+LED2_RED_DIR);}
#define set_2_RED()		{PORTB &= ~(LED2_GRN+LED2_RED); PORTB |= LED2_RED;}
#define set_2_GRN()		{PORTB &= ~(LED2_GRN+LED2_RED); PORTB |= LED2_GRN;}
#define set_2_YEL()		{PORTB &= ~(LED2_GRN+LED2_RED); PORTB |= LED2_GRN+LED2_RED;}

#define set_3_OFF()		{PORTB &= ~(LED3_GRN+LED3_RED);}
#define set_3_dir()		{DDRB |= LED3_GRN_DIR+LED3_RED_DIR;}
#define set_3_undir()		{DDRB &= ~(LED3_GRN_DIR+LED3_RED_DIR);}
#define set_3_RED()		{PORTB &= ~(LED3_GRN+LED3_RED); PORTB |= LED3_RED;}
#define set_3_GRN()		{PORTB &= ~(LED3_GRN+LED3_GRN); PORTB |= LED3_GRN;}
#define set_3_YEL()		{PORTB &= ~(LED3_GRN+LED3_GRN); PORTB |= LED3_GRN+LED3_RED;}

typedef enum {
	OFF=0,
	GREEN,
	RED,
	YELLOW,
} led_state;

void setLED(int led, led_state color);
void initLEDs();
#endif

