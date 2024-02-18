#ifndef __SENSOR__
#define __SENSOR__

#include <string>
#include "../data.h"
#include "../value_limits/ivalue_limits.h"

class ISensor {
public:
  virtual ~ISensor() = default;
  
  virtual Data GetData() const = 0;
  virtual Port GetPort() const = 0;
  virtual std::string GetName() const = 0;

  virtual void SetPort(Port) = 0;
  virtual void SetData(Data) = 0;
  virtual void SetName(std::string&) = 0;
  virtual void SetLimits(std::unique_ptr<IValueLimits>&&) = 0;

  virtual bool IsValidValue() const = 0;
};

#endif
