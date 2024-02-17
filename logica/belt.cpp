#include <cmath>
#include "belt.h"

// auxiliary function
// (epsilon was chosen as the second LSD in my measurements, plus a margin, to
//  ensure that my readings eventually fall within this range)
template <float epsilon = 0.15f>
bool AreFloatsEqual(float a, float b) {
  return std::abs(a - b) < epsilon;
}

// -----------------------------------------------------------------------------
// Setters

void Belt::SetPort(Port port_) {
  this->port = port_;
}

void Belt::SetName(std::string name_) {
  this->name = name_;
}

void Belt::SetLength(float length_) {
  this->length = length_;
}

void Belt::SetObjectiveSpeed(float speed_) {
  this->objective_speed = speed_;
  this->time = this->length / this->speed;
}

void Belt::SetTime(float time_) {
  this->time = time_;
  this->objective_speed = this->length / this->time;
}

// -----------------------------------------------------------------------------
// Getters

std::string Belt::GetName() {
  return this->name;
}

float Belt::GetLength() {
  return this->length;
}

float Belt::GetSpeed() {
  return this->current_speed;
}

float Belt::GetObjectiveSpeed() {
  return this->objective_speed;
}

float Belt::GetTime() {
  return this->time;
}

// -----------------------------------------------------------------------------
// Update Functions

void Belt::UpdateAlarmStatus(bool alarm) {
  this->alarm_active = alarm;
}

// * Update the state according to the following rules:
// * 1. If the alarm is active, immediately transition to the "Alarm" state.
// *    Do not transition to any other state as long as the alarm is active.
// * 2. If the state is "Halted", but the objective (desired) speed is greater
// *    than zero, transtion to the state "Running".
// * 3. If the state is "Running", but the objective speed is zero, then
// *    transition to the state "Halted".
// * If these conditions are not met, the state remains unchanged.
void Belt::UpdateState() {
  if (this->alarm_active) {
    this->state = StateAlarm(this);
    return;
  }
  
  switch(this->state.GetType()) {
  case StateType::HALTED:
    if (this->objective_speed > 0.0f) {
      this->state = StateRunning(this);
    }
    break;
  case StateType::RUNNING:
    if (AreFloatsEqual(this->objective_speed, 0.0f)) {
      this->state = StateHalted(this);
    }
  }
}

void Belt::UpdateSpeed() {
  this->current_speed = this->state.CalculateSpeed();
}

// -----------------------------------------------------------------------------
