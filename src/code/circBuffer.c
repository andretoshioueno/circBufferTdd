/*
 * CircularBuffer.c
 *
 *  Created on: 2 de mar de 2020
 *      Author: toshio
 */

#include "circBuffer.h"

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include "circBuffer_priv.h"

static uint32_t nextIndex(uint32_t capacity, uint32_t index)
{
    index++;
    if (index >= capacity) {
        index = 0;
    }

    return index;
}

bool circBufferIsEmpty(circBuffer_t *pbuf)
{
    if (pbuf->inIndex == (pbuf->outIndex)) {
        return true;
    } else {
        return false;
    }
}

bool circBufferIsFull(circBuffer_t *pbuf)
{
    if (((pbuf->inIndex + 1) % (pbuf->capacity)) == (pbuf->outIndex)) {
        return true;
    } else {
        return false;
    }
}

bool circBufferPut(circBuffer_t *pbuf, uint8_t data)
{
    if (circBufferIsFull(pbuf)) {
        return false;
    }

    pbuf->pData[pbuf->inIndex] = data;
    pbuf->inIndex = nextIndex(pbuf->capacity, pbuf->inIndex);

    return true;
}

bool circBufferGet(circBuffer_t *pbuf, uint8_t *pData)
{
    if (circBufferIsEmpty(pbuf)) {
        return false;
    }

    *pData = pbuf->pData[pbuf->outIndex];
    pbuf->outIndex = nextIndex(pbuf->capacity, pbuf->outIndex);

    return true;
}

uint32_t circBufferGetSize(circBuffer_t *pbuf)
{
    return pbuf->capacity - 1;
}
