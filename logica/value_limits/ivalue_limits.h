#ifndef __VALUE_LIMITS__
#define __VALUE_LIMITS__

#include "../data.h"

class IValueLimits {
public:
  virtual ~IValueLimits() = default;
  virtual bool IsWithinLimits(Data data) = 0;
};

#endif