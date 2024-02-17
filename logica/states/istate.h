#ifndef __STATE__
#define __STATE__

#include "state_type.h"

class IState {
public:
  virtual ~IState() = default;
  virtual float CalculateSpeed() = 0;
  virtual StateType GetType() const = 0;
};

#endif
