#include<avr/io.h>
#include<avr/interrupt.h>
#include"seven_segments.h"
#include"interrupts.h"

unsigned char timer_flag=0;

void TIMER1_INIT() {
    TCNT1 = 0;
    // CTC MODE
    TCCR1B |= (1 << WGM12);
    // PRESCALAR 1024
    TCCR1B |= (1 << CS10) | (1 << CS12);
    // CMP value
    OCR1A = 1000;
    TIMSK |= (1 << OCIE1A);
    TCCR1A = (1 << FOC1A);
}

ISR(TIMER1_COMPA_vect){
	//i-bit
	SREG |=(1<<7);
	timer_flag=1;
}


ISR(INT0_vect){
	//i-bit
	SREG |=(1<<7);
	//ON PRESSING PUSH BUTTON
   //RESET
	for(int i=0;i<6;i++){
		segment_clk[i]=0;
	}
	TCNT1 =0;
}

ISR(INT1_vect){
	//i-bit
	SREG |=(1<<7);
	//NO CLOCK SOURCE MODE TO <<PAUSE>>
	TCCR1B &= ~(1<<CS10) & ~(1<<CS11) & ~(1<<CS12);

}

ISR(INT2_vect){
	//i-bit
	SREG |=(1<<7);
	//INITIALIZE TIMER1 AGAIN TO <<RESUME>>
		TCCR1B |=(1<<CS10)|(1<<CS12);

}
void main(){
	//i-bit
	SREG |=(1<<7);
	Reset_Init();
	Pause_Init();
	Resume_Init();
	TIMER1_INIT();
	seven_segment_init();
	Dec_init();
    // Enable global interrupts
    sei();
	while(1){
		 display_segment();
         if(timer_flag==1){
        	 update_clk();
        	 timer_flag=0;
         }
	}

}
