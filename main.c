/*
 * Print_Seven_Segment.c
 *
 * Created: 4/16/2020 8:59:57 PM
 * Author : TINYMAHER
 */ 

// use button 0 for it to work

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define SEG_DDR DDRA
#define HIGH_NIPPLE 0xF0
#define SEG_CONTROL PORTB
#define SEG_CONTROL_DDR DDRB
#define SEG_PORT PORTA
#define E1  1
#define E2  2



ISR(INT0_vect){	
	
	SEG_PORT=0x10;
	_delay_ms(1000);
	SEG_PORT=SEG_PORT+10;
	if(SEG_PORT == 0x90){ SEG_PORT=0x10;}
}

int main(){

	//enable INT0 
	GICR|=(1<<INT0);
	//configure interrupt sense control Rising 
	MCUCR|=(1<<ISC01)|(1<<ISC00);			
	//enables global interrupt
	sei();

	SEG_DDR|=HIGH_NIPPLE;
	SEG_CONTROL_DDR|=(1<<E1)|(1<<E2);

	while(1){
		SEG_CONTROL|=(1<<E1)|(1<<E2);
		

	}
	return 0;
}