#include <memory>
#include "sensor_temp.h"

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