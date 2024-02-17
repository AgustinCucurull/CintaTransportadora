#ifndef __SENSOR_BASE__
#define __SENSOR_BASE__

#include <string>
#include "../data.h"
#include "../port.h"
#include "../controlboard_drivers/control_board.h"
#include "../value_limits/val_limits.h"
#include "isensor.h"

class SensorBase : public ISensor {
protected:
  Port port;
  Data data;
  ControlBoard board;
  std::string name;
  ValueLimits limits;
};

#endif