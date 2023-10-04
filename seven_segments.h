/*
 * seven_segments.h
 *
 *  Created on: Sep 14, 2023
 *      Author: DELL
 */

#ifndef SEVEN_SEGMENTS_H_
#define SEVEN_SEGMENTS_H_
#include<avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

char segment_clk[6];
/*
 * segment_clk[0] and segment_clk[1] for seconds
 * segment_clk[2] and segment_clk[3] for minutes
 * segment_clk[4] and segment_clk[5] for hours
 */
void update_clk();
void display_segment();
void seven_segment_init();
void Dec_init();



#endif /* SEVEN_SEGMENTS_H_ */
