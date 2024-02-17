#ifndef __SENSOR_FACTORY__
#define __SENSOR_FACTORY__

#include <memory>
#include "../controlboard_drivers/icontrolboard.h"
#include "../sensors/isensor.h"
#include "../value_limits/ivalue_limits.h"

class SensorFactory {
public:
  ~SensorFactory() = default;
  // Sensors with limits (viz. temperature, preassure)
  virtual ISensor *CreateSensor(std::string &name, Port port,
                                std::shared_ptr<IControlBoard> board,
                                float lower, float upper) = 0;
  // Digital Sensors (IR)
  virtual ISensor *CreateSensor(std::string &name, Port port,
                                std::shared_ptr<IControlBoard> board) = 0;
};

#endif
