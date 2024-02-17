#include "state_running.h"

// -----------------------------------------------------------------------------
// Getters

StateType StateRunning::GetType() {
  return this->type;
}

// -----------------------------------------------------------------------------
// State Operationsn

float StateRunning::CalculateSpeed() {
  if (this->auxiliary_speed < context->objective_speed) {
    this->auxiliary_speed += 1.0f;
  }

  if (this->auxiliary_speed > context->objective_speed) {
    this->auxiliary_speed = context->objective_speed;
  }

  return this->auxiliary_speed;
}

// -----------------------------------------------------------------------------

