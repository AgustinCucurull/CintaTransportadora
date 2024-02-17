#include "temperature_limits.h"

// -----------------------------------------------------------------------------

bool TemperatureLimits::IsWithinLimits(Data data) {
  return (data.GetValue().analog > this->lower_limit) &&
         (data.GetValue().analog < this->upper_limit);
}

// -----------------------------------------------------------------------------