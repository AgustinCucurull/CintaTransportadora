#include <memory>
#include "system_manager.h"
#include "./controlboard_drivers/board_type.h"
#include "./controlboard_drivers/controlboard_arduino.h"
#include "./sensors/sensor_type.h"
#include "./sensors/sensor_temp.h"
#include "./sensors/sensor_ir.h"

// -----------------------------------------------------------------------------

void SystemManager::AddBoardToSystem(std::string &name, uint32_t id_vendor, uint32_t id_product, BoardType type) {
  std::shared_ptr<IControlBoard> control_board;

  switch(type) {
  case BoardType::ARDUINO:
    control_board = std::make_unique<ControlBoardArduino>(name, id_vendor, id_product);
    break;
  }

  // blackboard_instance->AddBoard(control_board);
  blackboard_instance->SetControlBoard(control_board);
}

void SystemManager::AddBeltToSystem(std::string &name, Port port, float length, float speed) {
  blackboard_instance->AddBelt(std::make_unique<Belt>(name, port, length, speed));
}

void SystemManager::AddSensorToSystem(std::string &name, Port port, float lower_limit, float upper_limit, SensorType type) {
  std::unique_ptr<ISensor> sensor;

  switch(type) {
  case SensorType::TEMPERATURE:
    sensor = std::make_unique<SensorTemperature>(name, port, lower_limit, upper_limit);
    break;
  // case SensorType::PRESSURE:
  //   sensor = std::make_unique<SensorPressure>(name, port, lower_limit, upper_limit);
  //   break;
  }

  blackboard_instance->AddSensor(std::move(sensor));
}

void SystemManager::AddSensorToSystem(std::string &name, Port port, SensorType type) {
  std::unique_ptr<ISensor> sensor;
  
  switch(type) {
  case SensorType::IR:
    sensor = std::make_unique<SensorIR>(name, port);
    break;
  }

  blackboard_instance->AddSensor(std::move(sensor));
}

void SystemManager::EditBoard(std::string &name, uint32_t id_vendor, uint32_t id_product) {
  blackboard_instance->EditBoard(name, id_vendor, id_product);
}

void SystemManager::EditBoard(std::string &name, std::string &new_name, uint32_t id_vendor, uint32_t id_product) {
  blackboard_instance->EditBoard(name, new_name, id_vendor, id_product);
}

void SystemManager::EditBelt(std::string &name, Port port, float length, float speed) {
  blackboard_instance->EditBelt(name, port, length, speed);
}

void SystemManager::EditBelt(std::string &name, std::string &new_name, Port port, float length, float speed) {
  blackboard_instance->EditBelt(name, new_name, port, length, speed);
}

void SystemManager::EditSensor(std::string &name, Port port, float lower_limit, float upper_limit) {
  blackboard_instance->EditSensor(name, port, lower_limit, upper_limit);
}

void SystemManager::EditSensor(std::string &name, std::string &new_name, Port port, float lower_limit, float upper_limit) {
  blackboard_instance->EditSensor(name, new_name, port, lower_limit, upper_limit);
}

// -----------------------------------------------------------------------------

void SystemManager::RemoveBoardFromSystem(std::string &name) {
  return;
}

void SystemManager::RemoveSensorFromSystem(std::string &name) {
  blackboard_instance->RemoveSensor(name);
}

void SystemManager::RemoveBeltFromSystem(std::string &name) {
  blackboard_instance->RemoveBelt(name);
}

// -----------------------------------------------------------------------------