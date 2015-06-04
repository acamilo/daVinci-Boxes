#ifndef monitor_H
#define monitor_H

#include "leds.h"
void initTimer();

typedef enum {
	NONE=0,
	LOW,
	NOMINAL,
	HIGH

} rail_state;

typedef struct {
	unsigned long int upperLimit;		// upper bound of "good" voltage
	unsigned long int lowerlimit;		// lower bound of "good" voltage
} voltage_rail;

void checkRails();
void setLEDs();

#define F_CPU 1000000

// this line switches between master and slave
//#define master


// If LEDs populated backwards
#define swapleds


//12v
#define rail1_upper 155	 
#define rail1_lower 125	 

//24v
#ifdef ECM
    #define rail2_upper 435	 
    #define rail2_lower 387	 
#else
    #define rail2_upper 290	 
    #define rail2_lower 258	 
#endif


//12v
#define rail3_upper 155	 
#define rail3_lower 125	

#define rail_min 10

// Different from others. uses VCC as ref and measures ref to determine vcc.
// VCC = 1024 * (ref voltage / ADC)
//vcc/1024 = ref/adc
//1024/vcc = adc/ref

//ref * (1024/vcc) = adc
//(1024 * ref)/vcc = adc

// (1024×1.1)÷5.1 = 220.862745098
#define vlogic_upper 221

// (1024×1.1)÷4.9 = 229.87755102
#define vlogic_lower 230

#endif
