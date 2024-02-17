#ifndef __SENSOR_IR_FACTORY__
#define __SENSOR_IR_FACTORY__

#include "sensor_factory.h"

class SensorIRFactory : public SensorFactory {
public:
  ~SensorIRFactory() = default;
  ISensor *CreateSensor(std::string &name, Port port,
                        std::shared_ptr<IControlBoard> board, float lower,
                        float upper) override;
  ISensor *CreateSensor(std::string &name, Port port,
                        std::shared_ptr<IControlBoard> board) override;
};

#endif