/*
 * trafic_light.c
 *
 * Created: 24/05/2020 6:14:11 AM
 *  Author: M
 */ 


#include "seven_seg.h"
#include "Timer0.h"
uint8_t sec=20;
uint8_t led_color=0;
int main(void)
{
	SETBIT(DDRC,0);
	SETBIT(DDRC,1);
	SETBIT(PORTC,0);
	CLRBIT(PORTC,1);
	timer_normal_init();
	seven_seg_init();
	sei();
	while(1)
    {
        seven_seg_update(sec);
		if (led_color==0){
			SETBIT(PORTC,1);
			CLRBIT(PORTC,0);
			}
		else if (led_color==1){
			SETBIT(PORTC,0);
			CLRBIT(PORTC,1);
			}
    }
}
ISR(TIMER0_OVF_vect){
	static uint8_t counter=0;
	counter++;
	if(counter==62){
		if (sec!=0){
		sec--;
		}
		else if (sec==0){
			TOGBIT(led_color,0);
			sec=20;
			}		
	counter=0;	
	}
}