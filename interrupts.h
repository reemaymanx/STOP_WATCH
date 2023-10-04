/*
 * interrupts.h
 *
 *  Created on: Sep 14, 2023
 *      Author: DELL
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include<avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


void Reset_Init();
void Pause_Init();
void Resume_Init();



#endif /* INTERRUPTS_H_ */
