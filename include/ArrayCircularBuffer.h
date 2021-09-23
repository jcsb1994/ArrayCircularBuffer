//***********************************************************************************
// Copyright 2021 jcsb1994
// Written by jcsb1994
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//***********************************************************************************
//
// Description:
//    This file contains a high level interface for a buzzer. It lets the
//    user create melodies and feed them into the object without blocking operations.
//    The instance steps every ISR. step delay is specified in the ctor.
//    a melody is initialized with setMelody(). the tone will ring, when stepping
//    is complete, melody is cleared
//    https://github.com/espressif/arduino-esp32/issues/1720
//
// Implementation:
//    Implemented with Arduino.h and tone() to control note frequencies
//    On the ESP32, reimplemented with the ledcWriteTone() function
//
//***********************************************************************************

#ifndef ARRAY_CIRCULAR_BUFFER_H
#define ARRAY_CIRCULAR_BUFFER_H

#include <stdint.h>
#include <string.h>
#include "Arduino.h"

#define BUFFER_MAX 5

class ArrayCircularBuffer
{
public:
  ArrayCircularBuffer(/* args */) {
    for (int i = 0 ; i < BUFFER_MAX; i ++) {
      _buffer[i] = 0;
    }
  }
  
  ~ArrayCircularBuffer() {}

/***************************************************************************/
/*!
    @brief  Read the next info in the buffer
    @param  none
    @return The next data in the buffer, or 0 if nothing in the buffer
  */
/***************************************************************************/
  int read();

  /***************************************************************************/
/*!
    @brief  Push a new info in the buffer
    @param  data Data to be stored in the buffer
    @return none
  */
/***************************************************************************/
  void write(int data);

/***************************************************************************/
/*!
    @brief  Check if the buffer is empty
    @param  none
    @return True if there is no data in the buffer, false otherwise
  */
/***************************************************************************/
  bool isEmpty();

private:
  int _buffer[BUFFER_MAX];
  int _writeIdx = 0;
  int _readIdx = 0;
  int _contentLen = 0;
};


#endif

