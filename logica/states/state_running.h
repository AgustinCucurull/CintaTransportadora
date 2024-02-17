#ifndef __STATE_RUNNING__
#define __STATE_RUNNING__

#include "istate.h"

class Belt;

class StateRunning : public StateBase {  
public:
  StateRunning(Belt *context_) : context(context_) {
    type = StateType::RUNNING;
    auxiliary_speed = context->GetSpeed();
  }

  ~StateRunning() = default;
  
  float CalculateSpeed() override;
  StateType GetType() override;
};

#endif
