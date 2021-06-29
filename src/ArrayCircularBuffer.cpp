#include "ArrayCircularBuffer.h"

bool ArrayCircularBuffer::isEmpty()
{
  if (_contentLen)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void ArrayCircularBuffer::write(int data) {
 if (_contentLen == BUFFER_MAX)
  {
    return;
  }
  Serial.print("added ");
      Serial.println(data);

  _buffer[_writeIdx] = data;
  _writeIdx++;
  _contentLen++;
  if (_writeIdx == BUFFER_MAX)
  {
    _writeIdx = 0;
  }
}

int ArrayCircularBuffer::read() {
  if (_contentLen == 0)
  {
    return 0;
  }
  int readData = _buffer[_readIdx];
  _readIdx++;
  _contentLen--;
  if (_readIdx == BUFFER_MAX)
  {
    _readIdx = 0;
  }
  return readData;
}
