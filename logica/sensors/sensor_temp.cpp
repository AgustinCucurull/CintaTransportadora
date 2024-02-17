#include "sensor_temp.h"

void SensorTemperature::UpdateData() {
  this->board.GetData(this->port);
}

Data SensorTemperature::GetData() {
  return this->data;
}

void GetName(std::string &name_) {
  this->name = name_;
}

std::string SensorTemperature::GetName() {
  return this->name;
}

void SensorTemperature::SetLimits(IValueLimits limits) {
  // Initialize like this: sensor.SetLimits(limits(low, high))
  // (with the appropriate casting, in this case, floats)
  this->limits = limits;
}
bool SensorTemperature::IsValidValue() {
  return this->limits.IsWithinLimits(this->data);
}