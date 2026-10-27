#ifndef DELAY_H
#define DELAY_H

#include "stdint.h"
#include "math.h"

#define DELAY_MAXLENGTH 10000

typedef struct{

	//tamanho da linha de atraso
	uint32_t length;
	uint32_t index;
	// ponteiro que armazena as amostras atrasadas
	float *memory;
}Delay;

void DelayInit(Delay *dl,uint32_t delay);
float DelayRead(Delay *dl);
void DelayWrite(Delay *dl, float in);

#endif
