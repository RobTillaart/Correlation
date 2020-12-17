#pragma once
//
//    FILE: Correlation.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.2
// PURPOSE: Calculate Correlation from a small dataset.
// HISTORY: See Correlation.cpp
//

#include "Arduino.h"

// CORRELATION_SIZE should not exceed 250
// 
#ifndef CORRELATION_SIZE
#define CORRELATION_SIZE 20
#endif

class Correlation
{
public:
  Correlation();
  
  // returns true if the value is added to internal array.
  // returns false when internal array is full.
  bool    add(float x, float y);

  uint8_t count() { return _count; };
  uint8_t size()  { return CORRELATION_SIZE; };
  void    clear();

  // in running mode, adding new values will replace old ones
  // this constantly adapts the regression params A and B.
  void    setRunningCorrelation(bool rc) { _runningMode = rc; };

  // worker, to calculate the correlation params. 
  // MUST be called before getting the params A, B, R, Rsquare, Esquare, 
  //                                          avgX and avgY
  // returns false if contains no elements ==> count() == 0
  bool    calculate();

  // Y = A + B * X
  float   getA()       { return _a; };
  float   getB()       { return _b; };

  // returns R == correlation coefficient
  float   getR()       { return sqrt(_rSquare); };
  float   getRsquare() { return _rSquare; };
  
  // returns sum of the errors squared
  float   getEsquare() { return _sumErrorSquare; };

  // get the average values of the datasets (as it is available)
  float   getAvgX()    { return _avgX; };
  float   getAvgY()    { return _avgX; };
  
  // based on the dataset get the estimated values for X and Y
  // library does not return confidence interval for these. 
  float   getEstimateY(float x);
  float   getEstimateX(float y);

private:
  uint8_t _idx = 0;
  uint8_t _count = 0;
  bool    _runningMode = false;
  bool    _needRecalculate = true;

  float   _x[CORRELATION_SIZE];
  float   _y[CORRELATION_SIZE];

  float   _avgX;
  float   _avgY;
  float   _a;
  float   _b;
  float   _rSquare;
  float   _sumErrorSquare;
};

// -- END OF FILE --
