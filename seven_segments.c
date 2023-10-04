
#include"seven_segments.h"


void update_clk(){
	segment_clk[0]++;
	//seconds//
	if(segment_clk[0]==10){
		segment_clk[0]=0;
		segment_clk[1]++;
		if(segment_clk[1] == 6 && segment_clk[0] == 0){
			segment_clk[1]=0;
			segment_clk[2]++;
		}
	}
	//minutes//
	if(segment_clk[2]==10){
		segment_clk[2]=0;
		segment_clk[3]++;
		if(segment_clk[3] == 6 && segment_clk[2] == 0){
			segment_clk[3]=0;
			segment_clk[4]++;
		}
	}
	//hours//
	if(segment_clk[4]==10){
		segment_clk[4]=0;
		segment_clk[5]++;
		//MAX COUNT ON THE STOP WATCH//
		if(segment_clk[5] == 10 && segment_clk[4] == 0){
			for(int i=0;i<6;i++){
				segment_clk[i]=0;
			}
			//MAKE IT COUNT AGAIN FROM ZERO//
			TCNT1=0;
		}
	}
}
void display_segment(){
	//rotate on each segment of the six
	for(int i=0;i<6;i++){
		PORTA =(1<<i);
		PORTC = segment_clk[i];
		_delay_ms(3);
	}
}

void seven_segment_init(){
	   // 6 OUTPUT 2SECONDS-2MINUTES-2HOURS PINS
	   DDRA = 0X3F;
	   //ALL 6 COMMON ANODE
	   PORTA = 0X01;
}
void Dec_init(){
   DDRC =0X0F;//OUTPUT PINS
   PORTC =0;//initially =0
}
