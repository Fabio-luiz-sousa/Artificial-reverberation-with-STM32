#include "Schoroeder_Reverb.h"


void CombFilterInit(CombFilter *comb, float sample_rate_hz, float time_delay, float delay_ms[4]){

	comb->time_delay = time_delay;
	comb->sample_rate_hz = sample_rate_hz;
	for (uint8_t n=0; n < 4 ; n++){

		comb->delay_samples_comb[n] = (uint32_t)(comb->sample_rate_hz*0.001f*delay_ms[n]);
		float delay_s = (float)comb->delay_samples_comb[n]/comb->sample_rate_hz;
		comb->gain_comb_filter[n] = powf(10.0f,-3.0f*delay_s/comb->time_delay);
	}

	for (uint8_t n=0; n < 4 ; n++){
			DelayInit(&comb->comDelay[n], comb->delay_samples_comb[n]);
		}

}

void AllPassFilterInit(AllPassFilter *allp,float sample_rate_hz, float delay_ms[2], float gain[2]){

	for (uint8_t n = 0; n < 2; n++){
		allp->delay_samples_allpass[n] = (uint32_t)(sample_rate_hz*0.001f*delay_ms[n]);
		allp->gain_allpass[n] = gain[n];
	}

	for (uint8_t n=0; n < 2 ; n++){

				DelayInit(&allp->allpDelay[n], allp->delay_samples_allpass[n]);
			}

}

float CombFilterUpdate(CombFilter *comb, float in, uint8_t index, Delay *dl){

	float delayed = DelayRead(dl);
	comb->out_comb = in + comb->gain_comb_filter[index]*delayed;
	DelayWrite(dl, comb->out_comb);

	return (comb->out_comb);
}

float AllPassFilterUpdate(AllPassFilter *allp, float in, Delay *dl, uint8_t index){

	float delayed = DelayRead(dl);
	allp->out_allp = -allp->gain_allpass[index] * in + delayed;

	DelayWrite(dl, (in + allp->gain_allpass[index] * allp->out_allp));

	return (allp->out_allp);
}

void CombFilterSetTimeDelay(CombFilter *comb, float value_control){

	comb->time_delay = 0.5f + value_control*2.5f;

	for (uint8_t n=0; n < 4 ; n++){

			float delay_s = (float)comb->delay_samples_comb[n]/comb->sample_rate_hz;
			comb->gain_comb_filter[n] = powf(10.0f,-3.0f*delay_s/comb->time_delay);
		}
}



