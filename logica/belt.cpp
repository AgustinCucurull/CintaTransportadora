#include <cmath>
#include "belt.h"
#include "./states/state_alarm.h"
#include "./states/state_halted.h"
#include "./states/state_running.h"

// Auxiliary function.
// * Epsilon was chosen as the minimal value of the second LSD in my
// * measurements (0.1), plus a margin (+0.05), to ensure that my readings
// * eventually fall within this range.
bool AreFloatsEqual(float a, float b) {
  float epsilon = 0.15f;
  return std::abs(a - b) < epsilon;
}

// -----------------------------------------------------------------------------
// Setters

void Belt::SetPort(Port port_) {
  this->port = port_;
}

void Belt::SetName(std::string &name_) {
  this->name = name_;
}

void Belt::SetLength(float length_) {
  this->length = length_;
}

void Belt::SetObjectiveSpeed(float speed_) {
  this->objective_speed = speed_;
  this->time = this->length / speed_;
}

void Belt::SetTime(float time_) {
  this->time = time_;
  this->objective_speed = this->length / this->time;
}

// -----------------------------------------------------------------------------
// Getters

Port Belt::GetPort() const {
  return this->port;
}

std::string Belt::GetName() const {
  return this->name;
}

float Belt::GetLength() const {
  return this->length;
}

float Belt::GetSpeed() const {
  return this->current_speed;
}

float Belt::GetObjectiveSpeed() const {
  return this->objective_speed;
}

float Belt::GetTime() const {
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
  if (this->alarm_active && (this->state->GetType() != StateType::ALARM)) {
    this->state = std::make_unique<StateAlarm>(this);
    return;
  }
  
  switch(this->state->GetType()) {
  case StateType::HALTED:
    if (this->objective_speed > 0.0f) {
      this->state = std::make_unique<StateRunning>(this);
    }
    break;
  case StateType::RUNNING:
    if (AreFloatsEqual(this->objective_speed, 0.0f)) {
      this->state = std::make_unique<StateHalted>(this);
    }
    break;
  default:
    this->state = std::make_unique<StateHalted>(this);
  }
}

void Belt::UpdateSpeed() {
  this->current_speed = this->state->CalculateSpeed();
}

// -----------------------------------------------------------------------------
