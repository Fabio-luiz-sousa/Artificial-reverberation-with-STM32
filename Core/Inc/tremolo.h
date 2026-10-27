#ifndef TREMOLO_H
#define TREMOLO_H

#include "stdint.h"
#include "math.h"

typedef struct {

	//Tremolo depth
	float depth;

	// Low frequancy oscillator (LFO) parameters
	float lfodir;
	float lfoCount;
	float lfoCountLimit;

	//Effect sample rate (Hz)
	float sampleRate_Hz;

	//Effect output
	float out;
} Tremolo;

void TremoloInit(Tremolo *trem, float depth, float lfoFrequency_Hz, float sampleRate_Hz);
void Tremolo_SetDepth(Tremolo *trem,float depth);
void Tremolo_SetLFO_Frequency(Tremolo *trem, float lfoFrequency_Hz);
float Tremolo_Update(Tremolo *trem,float inp);

#endif
