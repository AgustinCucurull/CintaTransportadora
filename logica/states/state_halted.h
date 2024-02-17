#ifndef __STATE_HALTED__
#define __STATE_HALTED__

#include "state_base.h"

class Belt;

class StateHalted : public StateBase {
public:
  StateHalted(Belt* context_) : StateBase(context_) {
    type = StateType::HALTED;
    auxiliary_speed = context->GetSpeed();
  }

  ~StateHalted() = default;

  float CalculateSpeed() override;
  StateType GetType() const override;
};

#endif
