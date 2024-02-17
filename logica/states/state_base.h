#ifndef __STATE_BASE__
#define __STATE_BASE__

#include "../belt.h"
#include "istate.h"
//#include <cmath> // for std::abs

class StateBase : public ISensor {
protected:
  Belt *context;
  StateType type;
  float auxiliary_speed; // intermediate speeds when accelerating/decelerating

  // static float epsilon = 0.1f;
  // bool CompareEqualFloats(float &a, float &b) {
  //   return std::abs(a - b) < epsilon;
  // }
};

#endif
