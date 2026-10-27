#include "Delay.h"

void DelayInit(Delay *dl,uint32_t delay){

	//comprimento do delay
	dl->length = delay;

	if (dl->length == 0){
	        dl->length = 1;
	}

	// envelopa o comprimento do delay
	if (dl->length > DELAY_MAXLENGTH){
		dl->length = DELAY_MAXLENGTH;
	}

	//limpa memoria do delay
	for( uint32_t n = 0; n < dl->length; n++){
		dl->memory[n] = 0.0f;
	}

	// limpa o index
	dl->index=0;
}

float DelayRead(Delay *dl)
{
	// lê a amostra atrasada no index atual
    return dl->memory[dl->index];
}

void DelayWrite(Delay *dl, float in)
{
	// escreve a nova amostra no index atual
    dl->memory[dl->index] = in;

    // incrementa o index
    dl->index++;

    if (dl->index >= dl->length)
    {
        dl->index -= dl->length;
    }
}
