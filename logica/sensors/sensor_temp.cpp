#include <memory>
#include "sensor_temp.h"

// -----------------------------------------------------------------------------

void SensorTemperature::UpdateData() {
  this->data = this->board->GetData(this->port);
}

// -----------------------------------------------------------------------------
// Getters

Data SensorTemperature::GetData() const {
  return this->data;
}

Port SensorTemperature::GetPort() const {
  return this->port;
}

std::string SensorTemperature::GetName() const {
  return this->name;
}

// -----------------------------------------------------------------------------
// Setters

void SensorTemperature::SetPort(Port port_) {
  this->port = port_;
}

void SensorTemperature::SetData(Data data_) {
  this->data = data_;
}

void SensorTemperature::SetControlBoard(std::shared_ptr<IControlBoard> board_) {
  this->board = std::make_shared<IControlBoard>(board_);
}

void SensorTemperature::SetName(std::string &name_) {
  this->name = name_;
}

void SensorTemperature::SetLimits(std::unique_ptr<IValueLimits> &&limits_) {
  this->limits = std::move(limits_);
}

// -----------------------------------------------------------------------------

bool SensorTemperature::IsValidValue() const {
  return this->limits->IsWithinLimits(this->data);
}

// -----------------------------------------------------------------------------