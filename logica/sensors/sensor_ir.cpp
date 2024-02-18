#include <memory>
#include "sensor_ir.h"

// -----------------------------------------------------------------------------
// Getters

Data SensorIR::GetData() const {
  return this->data;
}

std::string SensorIR::GetName() const {
  return this->name;
}

// -----------------------------------------------------------------------------
// Setters

void SensorIR::SetPort(Port port_) {
  this->port = port_;
}

void SensorIR::SetData(Data data_) {
  this->data = data_;
}

void SensorIR::SetName(std::string &name_) {
  this->name = name_;
}

void SensorIR::SetLimits(std::unique_ptr<IValueLimits> &&limits_) {
  this->limits = std::move(limits_);
}

// -----------------------------------------------------------------------------

bool SensorIR::IsValidValue() const {
  return true;
}

// -----------------------------------------------------------------------------