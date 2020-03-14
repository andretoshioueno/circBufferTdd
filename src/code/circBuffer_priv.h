/*
 * circBuffer_priv.h
 *
 *  Created on: 4 de mar de 2020
 *      Author: toshio
 */

#ifndef CODE_CIRCBUFFER_PRIV_H_
#define CODE_CIRCBUFFER_PRIV_H_

#include <stdint.h>

struct circBuffer{
	uint8_t *pData;
	uint32_t inIndex;
	uint32_t outIndex;
	uint32_t capacity;
} circBuffer;

#endif /* CODE_CIRCBUFFER_PRIV_H_ */
