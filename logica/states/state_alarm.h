#ifndef __STATE_ALARM__
#define __STATE_ALARM__

#include "state_base.h"
#include "../port.h"

class Belt;

class StateAlarm : public StateBase {
public:
  StateAlarm(Belt* context_) : StateBase(context_) {
    type = StateType::ALARM;
    auxiliary_speed = context->GetSpeed();
  }

  ~StateAlarm() = default;
  
  float CalculateSpeed() override;
  StateType GetType() const override;
};

#endif
