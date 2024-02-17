#ifndef __SENSOR__
#define __SENSOR__

#include <string>
#include "../data.h"

class ISensor {
public:
  virtual ~ISensor() = default;
  virtual void UpdateData() = 0;
  
  virtual Data GetData() = 0;
  virtual std::string GetName() = 0;

  virtual void SetName(std::string&)
  virtual void SetLimits(IValueLimits) = 0;

  virtual bool IsValidValue() = 0;
};

#endif
