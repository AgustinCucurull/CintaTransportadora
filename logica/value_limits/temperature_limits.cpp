#include "temperature_limits.h"

// -----------------------------------------------------------------------------

bool TemperatureLimits::IsWithinLimits(Data data) {
  return (static_cast<float> data.GetValue() > this->lower_limit) &&
         (static_cast<float> data.GetValue() < this->upper_limit);
}

// -----------------------------------------------------------------------------