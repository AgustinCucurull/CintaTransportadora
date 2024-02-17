#include <iostream>
#include "../sensors/sensor_temp.h"
#include "../value_limits/temperature_limits.h"
#include "sensor_temperature_factory.h"

ISensor *
SensorTemperatureFactory::CreateSensor(std::string &name, Port port,
                                       std::shared_ptr<IControlBoard> board,
                                       float lower, float upper) {
  ISensor *new_sensor = new SensorTemperature();
  new_sensor->SetName(name);
  new_sensor->SetPort(port);
  new_sensor->SetControlBoard(board);
  new_sensor->SetLimits(std::make_unique<TemperatureLimits>(lower, upper));
  
  return new_sensor;
}

ISensor *
SensorTemperatureFactory::CreateSensor(std::string &name, Port port,
                                       std::shared_ptr<IControlBoard> board) {
  std::cerr
      << "Error: Tried to create a temperature sensor with no bound values."
      << std::endl;
  return nullptr;
}