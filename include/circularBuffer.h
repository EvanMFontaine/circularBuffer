#ifndef __circularBuffer_h__
#define __circularBuffer_h__

template <typename T, int N>
class circularBuffer
{
private:
    /* data */
    T theBuffer[N];
    bool isFull_Flag = 0;
    int readIndex = 0;
    int writeIndex = 0;

public:
    float buffAverage = 0;
    /*
    Read Returns the next unread line of the buffer
    */
    bool readFromBuffer(T *data_element)
    {
        if (isBufferEmpty())
        {
            return false;
        }
        else
        {
            *data_element = theBuffer[readIndex];
            readIndex = (readIndex + 1) % N;
            isFull_Flag = 0;
            return true;
        }
    }
    /*
    Write Returns true if input added returns false if buffer is full
    */
    bool writeToBuffer(T data_element)
    {
        if (isBufferFull())
        {
            return false;
        }
        else
        {
            theBuffer[writeIndex] = data_element;
            writeIndex = (writeIndex + 1) % N;
            if (readIndex == writeIndex)
            {
                isFull_Flag = true;
            }
            return true;
        }
    }
    /*
    Returns true if buffer is full
    */
    int bufferAvailable() { return (readIndex - writeIndex); }
    bool isBufferEmpty()
    {
        if ((readIndex == writeIndex) && (isFull_Flag != 1))
        {
            return true;
        }
        else
            return false;
    }
    bool isBufferFull()
    {
        return isFull_Flag;
    }
    /*
    Set the user input buffAverage to the mean average all Remaining items in buffer
    */
    bool readBufferAverage(float *buffAverage)
    {
        if (isBufferEmpty())
        {
            return false; // buffer avarage remains the same and bool signals failure
        }
        T outPut = 0;
        T temp = 0;
        int counts = 0;
        while (readFromBuffer(&temp))
        {
            outPut = outPut + temp;
            counts++;
        }
        *buffAverage = (float)outPut / counts;
        return true;
    }

    // circularBuffer(/* args */);
    // ~circularBuffer();+
};

#endif
