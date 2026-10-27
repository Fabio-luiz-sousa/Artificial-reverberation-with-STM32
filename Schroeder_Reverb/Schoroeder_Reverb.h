/*
 * Schoroeder_Reverb.h
 *
 *  Created on: Sep 21, 2026
 *      Author: fabioluiz
 */

#ifndef SCHOROEDER_REVERB_H
#define SCHOROEDER_REVERB_H

#include "Delay.h"
#include "stdint.h"
#include "math.h"

typedef struct{

	uint32_t delay_samples_comb[4];
	float time_delay;
	float gain_comb_filter[4];
	float out_comb;
	float sample_rate_hz;
	Delay comDelay[4];

}CombFilter;

typedef struct{
	uint32_t delay_samples_allpass[2];
	float gain_allpass[2];
	float out_allp;
	Delay allpDelay[2];
}AllPassFilter;


void CombFilterInit(CombFilter *comb, float sample_rate_hz, float time_delay, float delay_ms[4]);
void AllPassFilterInit(AllPassFilter *allp,float sample_rate_hz, float delay_ms[2], float gain[2]);
float CombFilterUpdate(CombFilter *comb, float in,uint8_t index, Delay *dl);
float AllPassFilterUpdate(AllPassFilter *allp, float in, Delay *dl, uint8_t index);
void CombFilterSetTimeDelay(CombFilter *comb,float value_control);


#endif /* SCHOROEDER_REVERB_H_ */
