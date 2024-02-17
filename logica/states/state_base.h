#ifndef __STATE_BASE__
#define __STATE_BASE__

#include "../belt.h"
#include "istate.h"
//#include <cmath> // for std::abs

class StateBase : public IState {
protected:
  ~StateBase() = default;
  Belt *context;
  StateType type;
  float auxiliary_speed; // intermediate speeds when accelerating/decelerating

public:
  StateBase(Belt* c) : context(c) {}
};

#endif
