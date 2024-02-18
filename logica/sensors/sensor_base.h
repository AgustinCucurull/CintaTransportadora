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
  Port port;
  Data data;
  
  std::string name;
  std::unique_ptr<IValueLimits> limits;
};

#endif