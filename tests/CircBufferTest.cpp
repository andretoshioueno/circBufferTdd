#include "CppUTest/TestHarness.h"
#include <stdio.h>
#include <stdint.h>

extern "C"
{
#include "circBuffer.h"
}

static void fillItUp(circBuffer_t *pQueue)
{
	uint32_t size = circBufferGetSize(pQueue);

	for (uint32_t i=0; i<size; i++) {
		circBufferPut(pQueue, 0x55);
	}
}

TEST_GROUP(CircularBuffer)
{
	CIRCBUFFER_DECLARE(stQueue, MAX_BUFFER_SIZE);
	CIRCBUFFER_DECLARE(stQueue1, MAX_BUFFER_SIZE);
	CIRCBUFFER_DECLARE(stQueue2, MAX_BUFFER_SIZE);

    void setup()
    {

    }

    void teardown()
    {
    }
};

TEST(CircularBuffer, is_empty_after_creation)
{
    CHECK_TRUE(circBufferIsEmpty(&stQueue));
}

TEST(CircularBuffer, is_not_full_after_creation)
{
    CHECK_FALSE(circBufferIsFull(&stQueue));
}

TEST(CircularBuffer, is_not_empty_after_put)
{
	CHECK_TRUE(circBufferPut(&stQueue, 42));
    CHECK_FALSE(circBufferIsEmpty(&stQueue));
}

TEST(CircularBuffer, is_empty_after_put_then_get)
{
	uint8_t data;
	CHECK_TRUE(circBufferPut(&stQueue, 42));
	CHECK_TRUE(circBufferGet(&stQueue, &data));
	CHECK_TRUE(circBufferIsEmpty(&stQueue));
}

TEST(CircularBuffer, get_data_equals_put)
{
    uint8_t data;
	CHECK_TRUE(circBufferPut(&stQueue, 42));
	CHECK_TRUE(circBufferGet(&stQueue, &data));
	CHECK_TRUE(data == 42);
}

TEST(CircularBuffer, report_capacity)
{
    LONGS_EQUAL(MAX_BUFFER_SIZE, circBufferGetSize(&stQueue));
}

TEST(CircularBuffer, fill_buffer)
{
	fillItUp(&stQueue);
	CHECK_TRUE(circBufferIsFull(&stQueue));
}

TEST(CircularBuffer, put_return_false_when_full)
{
	fillItUp(&stQueue);
	CHECK_FALSE(circBufferPut(&stQueue, 0x55));
}

TEST(CircularBuffer, get_return_false_when_empty)
{
	uint8_t data;
	CHECK_FALSE(circBufferGet(&stQueue, &data));
}

TEST(CircularBuffer, fill_buffer_then_empty)
{
	fillItUp(&stQueue);
	CHECK_TRUE(circBufferIsFull(&stQueue));

	uint8_t data;
	uint32_t size = circBufferGetSize(&stQueue);

	for (uint32_t i=0; i<size; i++) {
		CHECK_TRUE(circBufferGet(&stQueue, &data));
	}

	CHECK_TRUE(circBufferIsEmpty(&stQueue));
}

TEST(CircularBuffer, put_and_get_with_wraparound)
{
	uint8_t data;
	uint32_t size = circBufferGetSize(&stQueue);
	size *= 2;

	for (uint32_t i=0; i<size; i++) {
	    CHECK_TRUE(circBufferPut(&stQueue, 0x11));
	    CHECK_TRUE(circBufferGet(&stQueue, &data));
	    CHECK_TRUE(data == 0x11);

		CHECK_TRUE(circBufferPut(&stQueue, 0x22));
		CHECK_TRUE(circBufferGet(&stQueue, &data));
        CHECK_TRUE(data == 0x22);

		CHECK_TRUE(circBufferPut(&stQueue, 0x33));
		CHECK_TRUE(circBufferGet(&stQueue, &data));
		CHECK_TRUE(data == 0x33);
	}
}


