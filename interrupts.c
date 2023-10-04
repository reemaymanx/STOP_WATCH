#include"interrupts.h"
//INT0
void Reset_Init(){
	//PUSH BUTTON INPUT PIN
	DDRD &=~(1<<2);
	//internal pull up;
	PORTD |= (1<<2);
	//enable INT0
	GICR|=(1<<INT0);
	//falling edge
	MCUCR |=(1<<ISC01);

}
//INT1
void Pause_Init(){
	DDRD &=~(1<<3);
	//EXTERNAL PULL DOWN
	PORTD &=~(1<<3);
	//ENABLE INT1
	GICR|=(1<<INT1);
	//RISING EDGE
	MCUCR |=(1<<ISC11)|(1<<ISC10);
}
//INT2
void Resume_Init(){
	DDRB &= ~(1<<2);
	//INTERNAL PULL UP
	PORTB |=(1<<2);
	//ENABLE INT2
	GICR|=(1<<INT2);
	//FALLING EDGE
	MCUCSR &= ~(1<<ISC2);
}

