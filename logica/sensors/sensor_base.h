#ifndef __SENSOR_BASE__
#define __SENSOR_BASE__

#include <string>
#include <memory>
#include "../data.h"
#include "../port.h"
#include "../controlboard_drivers/icontrolboard.h"
#include "../value_limits/ivalue_limits.h"
#include "isensor.h"

class SensorBase : public ISensor {
protected:
  std::string name;
  Port port;
  Data data;
  SensorType type;
  std::unique_ptr<IValueLimits> limits;
public:
  SensorBase(const std::string &name_, Port port_) : name(name_), port(port_) {}
  SensorBase() {}
};

#endif