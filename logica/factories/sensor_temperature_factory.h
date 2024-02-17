#ifndef __SENSOR_TEMPERATURE_FACTORY__
#define __SENSOR_TEMPERATURE_FACTORY__

#include "sensor_factory.h"

class SensorTemperatureFactory : public SensorFactory {
public:
  ~SensorTemperatureFactory() = default;
  ISensor *CreateSensor(std::string &name, Port port,
                        std::shared_ptr<IControlBoard> board, float lower,
                        float upper) override;
  ISensor *CreateSensor(std::string &name, Port port,
                        std::shared_ptr<IControlBoard> board) override;
};

#endif