#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "RoboCAR.h"


void Timer0_Init();
void Timer1_PWM_Init();


#endif


/*	 if(psd_dist < 30) {

    	Left_turn();
    	 _delay_ms(450);
  	  
  		Forward();
     	_delay_ms(600);

    	Right_turn();
     	_delay_ms(450);
 
	  	Forward();
	  	_delay_ms(800);
 
	 	Right_turn();
	  	_delay_ms(390);
	  
    	Forward();
		_delay_ms(670);

		Left_turn();
 		_delay_ms(350);


 }*/
