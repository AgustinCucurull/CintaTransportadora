#ifndef __TEMPERATURE_LIMITS__
#define __TEMPERATURE_LIMITS__

#include "../value_limits/ivalue_limits.h"

class TemperatureLimits : public IValueLimits {
  float lower_limit;
  float upper_limit;
public:
  TemperatureLimits(float lower, float upper) : lower_limit(lower), upper_limit(upper_limit) {}
  ~TemperatureLimits() = default;
  bool IsWithinLimits(Data data) override;
};

#endif