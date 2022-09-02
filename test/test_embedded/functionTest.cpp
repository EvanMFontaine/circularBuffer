#include <Arduino.h>
#include <unity.h>
#include <circularBuffer.h>

using namespace std;

void setUp(void)
{
    // set stuff up here
}
void tearDown(void)
{
    // clean stuff up here
}

// @brief Test the int buffer
void testINT(void)
{
    circularBuffer<int, 10> intBuffer;
    intBuffer.writeToBuffer(5);
    int testInt = 0;
    intBuffer.readFromBuffer(&testInt);
    TEST_ASSERT_EQUAL(5, testInt);
}
void testINT_DEEP(void)
{
    circularBuffer<int, 10> intBuffer;
    if (!intBuffer.writeToBuffer(1))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 1");
    if (!intBuffer.writeToBuffer(2))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 2");
    if (!intBuffer.writeToBuffer(3))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 3");
    if (!intBuffer.writeToBuffer(4))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 4");
    if (!intBuffer.writeToBuffer(5))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 5");
    if (!intBuffer.writeToBuffer(6))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 6");

    int testInt[4];
    intBuffer.readFromBuffer(&testInt[1]);
    intBuffer.readFromBuffer(&testInt[2]);
    intBuffer.readFromBuffer(&testInt[3]);

    TEST_ASSERT_EQUAL(3, testInt[3]);
}
void testINT_AVG(void)
{
    circularBuffer<int, 10> intBuffer;
    if (!intBuffer.writeToBuffer(1))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 1");
    if (!intBuffer.writeToBuffer(2))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 2");
    if (!intBuffer.writeToBuffer(3))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 3");
    if (!intBuffer.writeToBuffer(4))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 4");
    if (!intBuffer.writeToBuffer(5))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 5");
    if (!intBuffer.writeToBuffer(6))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 6");
    float testfloat = 0;
    intBuffer.readBufferAverage(&testfloat);
    TEST_ASSERT_EQUAL_FLOAT(3.5, testfloat);
}

/// @brief Test the float buffer
void testFLOAT(void)
{
    circularBuffer<float, 10> floatBuffer;
    floatBuffer.writeToBuffer(6.0);
    float testFloat = 0;
    floatBuffer.readFromBuffer(&testFloat);
    TEST_ASSERT_EQUAL_FLOAT(6, testFloat);
}

void testFLOAT_DEEP(void)
{
    circularBuffer<float, 10> floatBuffer;
    if (!floatBuffer.writeToBuffer(1.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 1");
    if (!floatBuffer.writeToBuffer(2.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 2");
    if (!floatBuffer.writeToBuffer(3.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 3");
    if (!floatBuffer.writeToBuffer(4.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 4");
    if (!floatBuffer.writeToBuffer(5.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 5");
    if (!floatBuffer.writeToBuffer(6.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 6");
    float testFloat[4];
    floatBuffer.readFromBuffer(&testFloat[1]);
    floatBuffer.readFromBuffer(&testFloat[2]);
    floatBuffer.readFromBuffer(&testFloat[3]);

    TEST_ASSERT_EQUAL_FLOAT(3, testFloat[3]);
}
void testFLOAT_AVG(void)
{
    circularBuffer<float, 10> floatBuffer;
    if (!floatBuffer.writeToBuffer(1.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 1");
    if (!floatBuffer.writeToBuffer(2.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 2");
    if (!floatBuffer.writeToBuffer(3.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 3");
    if (!floatBuffer.writeToBuffer(4.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 4");
    if (!floatBuffer.writeToBuffer(5.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 5");
    if (!floatBuffer.writeToBuffer(6.0))
        TEST_ASSERT_FALSE_MESSAGE(1, "Buffer is full at 6");
    float testFloat = 0;
    floatBuffer.readBufferAverage(&testFloat);

    TEST_ASSERT_EQUAL_FLOAT(3.5, testFloat);
}

void setup()
{
    // Testing the timing class
    UNITY_BEGIN();
    RUN_TEST(testINT);
    RUN_TEST(testFLOAT);
    RUN_TEST(testINT_DEEP);
    RUN_TEST(testFLOAT_DEEP);
    RUN_TEST(testINT_AVG);
    RUN_TEST(testFLOAT_AVG);
    UNITY_END();

    // Testing the timer class
}

void loop()
{
}