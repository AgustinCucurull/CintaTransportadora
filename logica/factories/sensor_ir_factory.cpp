#include "../sensors/sensor_ir.h"
#include "sensor_ir_factory.h"
#include <iostream>

#include "sensor_ir_factory.h"

ISensor *SensorIRFactory::CreateSensor(std::string &name, Port port,
                                       std::shared_ptr<IControlBoard> board,
                                       float lower, float upper) {
  std::cerr
      << "Error: Tried to create a temperature sensor with no bound values."
      << std::endl;
  return nullptr;
}

ISensor *SensorIRFactory::CreateSensor(std::string &name, Port port,
                                       std::shared_ptr<IControlBoard> board) {
  ISensor *new_sensor = new SensorIR();
  new_sensor->SetName(name);
  new_sensor->SetPort(port);
  new_sensor->SetControlBoard(board);
  new_sensor->SetLimits(nullptr);
  
  return new_sensor;
}