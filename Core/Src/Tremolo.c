#include "tremolo.h"

void TremoloInit(Tremolo *trem, float depth, float lfoFrequency_Hz, float sampleRate_Hz){

	//Store tremolo depth
	Tremolo_SetDepth(trem,depth);

	// store sample rate and compute LFO parameters
	trem->sampleRate_Hz=sampleRate_Hz;
	Tremolo_SetLFO_Frequency(trem, lfoFrequency_Hz);

	// clear lfo counter and set lfo direction
	trem->lfoCount=0.0f;
	trem->lfodir=1.0f;


	//clear output
	trem->out=0.0f;
}

void Tremolo_SetDepth(Tremolo *trem,float depth){

	// check depth bounds

	if(depth < 0.0f){
		depth=0.0f;
	}else if (depth > 1.0f){
		depth = 1.0f;
	}

	trem->depth=depth;
}

void Tremolo_SetLFO_Frequency(Tremolo *trem, float lfoFrequency_Hz){

	// check lfo frequency bounds
	if (lfoFrequency_Hz <= 0.0f){
		lfoFrequency_Hz = 1.0f;
	} else if(lfoFrequency_Hz > 0.5f * trem->sampleRate_Hz){
		lfoFrequency_Hz =  0.5f * trem->sampleRate_Hz;
	}

	//compute counter limit based on desired lfo frequency (countLimit = (fs/flfo)/4)
	trem->lfoCountLimit = 0.25f*(trem->sampleRate_Hz/lfoFrequency_Hz);

	//ensure lfo counter is within new counter limit range
	if (trem->lfoCount > trem->lfoCountLimit){
		trem->lfoCount = trem->lfoCountLimit;
	}else if (trem->lfoCount < -trem->lfoCountLimit){
		trem->lfoCount = -trem->lfoCountLimit;
	}

}

float Tremolo_Update(Tremolo *trem,float inp){

	// modulate input signal: y[n] = x[n]*((1-d)+d*g[n])
	trem->out = inp*((1-trem->depth)+trem->depth*(trem->lfoCount/trem->lfoCountLimit));

	// if we've reached a maximum of triangle wave, count down
	if (trem->lfoCount >=trem->lfoCountLimit){
		trem->lfodir= -1.0f;
	}
	// if we've reached a minimum of triangle wave, count up
	else if(trem->lfoCount <= -trem->lfoCountLimit){
		trem->lfodir= +1.0f;
	}

	//increment lfo counter
	trem->lfoCount += trem->lfodir;

	return (trem->out);
}
