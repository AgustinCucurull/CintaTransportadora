#include "state_halted.h"

// -----------------------------------------------------------------------------
// Getters

StateType StateHalted::GetType() const {
  return this->type;
}

// -----------------------------------------------------------------------------
// State Operations

float StateHalted::CalculateSpeed() {
  if (this->auxiliary_speed > 0.0f) {
    this->auxiliary_speed -= 1.0f;
  }

  if (this->auxiliary_speed < 0.0f) {
    this->auxiliary_speed = 0.0f;
  }

  return this->auxiliary_speed;
}

// -----------------------------------------------------------------------------
