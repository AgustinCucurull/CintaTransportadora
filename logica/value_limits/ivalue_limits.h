#ifndef __VALUE_LIMITS__
#define __VALUE_LIMITS__

#include "../data.h"

class IValueLimits {
public:
  virtual ~Limtis() = default;
  virtual bool IsWithinLimits(Value value) = 0;
};

#endif