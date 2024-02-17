#ifndef __STATE__
#define __STATE__

#include "state_type.h"

class IState {
public:
  virtual ~State() = default;
  virtual float CalculateSpeed() = 0;
  virtual StateType GetType() = 0;
};

#endif
