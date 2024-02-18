#include "state_running.h"

// -----------------------------------------------------------------------------
// Getters

StateType StateRunning::GetType() const {
  return this->type;
}

// -----------------------------------------------------------------------------
// State Operations

float StateRunning::CalculateSpeed() {
  if (this->auxiliary_speed < this->context->GetObjectiveSpeed()) {
    this->auxiliary_speed += 1.0f;
  }

  if (this->auxiliary_speed > this->context->GetObjectiveSpeed()) {
    this->auxiliary_speed = context->GetObjectiveSpeed();
  }

  return this->auxiliary_speed;
}

// -----------------------------------------------------------------------------

