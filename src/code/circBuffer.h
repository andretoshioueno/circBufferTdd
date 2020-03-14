/*
 * CircularBuffer.h
 *
 *  Created on: 2 de mar de 2020
 *      Author: toshio
 */

#ifndef CODE_CIRCBUFFER_H_
#define CODE_CIRCBUFFER_H_

#include <stdbool.h>
#include <stdint.h>
#include "circBuffer_priv.h"

#define MAX_BUFFER_SIZE			64

typedef struct circBuffer circBuffer_t;

bool circBufferGet(circBuffer_t *pbuf, uint8_t *pData);
bool circBufferPut(circBuffer_t *pbuf, uint8_t data);
uint32_t circBufferGetSize(circBuffer_t *pbuf);
bool circBufferIsEmpty(circBuffer_t *pbuf);
bool circBufferIsFull(circBuffer_t *pbuf);
bool circBufferInit(circBuffer_t *pbuf);

#define CIRCBUFFER_DECLARE(name, capacity)      \
        uint8_t name##_buffer[capacity+1];      \
        circBuffer_t name = {                   \
                name##_buffer,                  \
                0,                              \
                0,                              \
                capacity+1                      \
        }

#endif /* CODE_CIRCBUFFER_H_ */
