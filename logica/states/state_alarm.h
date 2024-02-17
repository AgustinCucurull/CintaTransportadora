#ifndef __STATE_ALARM__
#define __STATE_ALARM__

#include "istate.h"

class Belt;

class StateAlarm : public StateBase {
public:
  StateAlarm(Belt *context_) : context(context_) {
    type = StateType::ALARM;
    auxiliary_speed = context->GetSpeed();
  }

  ~StateAlarm() = default;
  
  float CalculateSpeed() override;
  StateType GetType() override;
};

#endif
