#ifndef __STATE_RUNNING__
#define __STATE_RUNNING__

#include "state_base.h"

class Belt;

class StateRunning : public StateBase {  
public:
  StateRunning(Belt* context_) : StateBase(context_) {
    type = StateType::RUNNING;
    auxiliary_speed = context->GetSpeed();
  }

  ~StateRunning() = default;
  
  float CalculateSpeed() override;
  StateType GetType() const override;
};

#endif
