#ifndef __SENSOR__
#define __SENSOR__

#include <string>
#include "sensor_type.h"
#include "../data.h"
#include "../value_limits/ivalue_limits.h"

class ISensor {
public:
  virtual ~ISensor() = default;

  virtual std::string GetName() const = 0;
  virtual Data GetData() const = 0;
  virtual Port GetPort() const = 0;
  virtual SensorType GetType() const = 0;

  virtual void SetName(std::string&) = 0;
  virtual void SetPort(Port) = 0;
  virtual void SetData(Data) = 0;
  virtual void SetType(SensorType) = 0;
  virtual void SetLimits(std::unique_ptr<IValueLimits>&&) = 0;

  virtual bool IsValidValue() const = 0;
};

#endif
