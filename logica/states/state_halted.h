#ifndef __STATE_HALTED__
#define __STATE_HALTED__

#include "istate.h"

class Belt;

class StateHalted : public StateBase {
public:
  StateHalted(Belt *context_) : context(context_) {
    type = StateType::HALTED;
    auxiliary_speed = context->GetSpeed();
  }

  ~StateHalted() = default;

  float CalculateSpeed() override;
  StateType GetType() override;
};

#endif
