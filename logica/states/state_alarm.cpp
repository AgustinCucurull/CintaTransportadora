#include "state_alarm.h"

// -----------------------------------------------------------------------------
// Getters

StateType StateAlarm::GetType() {
  return this->type;
}

// -----------------------------------------------------------------------------
// State Operations

float StateAlarm::CalculateSpeed() {
  if (this->auxiliary_speed > 0.0f) {
    this->auxiliary_speed -= 1.0f;
  }

  if (this->auxiliary_speed < 0.0f) {
    this->auxiliary_speed = 0.0f;
  }

  return this->auxiliary_speed;
}

// -----------------------------------------------------------------------------
