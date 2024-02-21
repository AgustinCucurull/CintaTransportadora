#include <iostream>
#include <string>

#include "./controlboard_drivers/board_type.h"
#include "./controlboard_drivers/controlboard_arduino.h"
#include "belt.h"
#include "blackboard.h"
#include "system_manager.h"
#include "port.h"

enum class ProgramState {
  SENSOR_WINDOW,
  BELT_WINDOW,
  MAIN_WINDOW,
  QUIT
};

int main() {
  BlackBoard* blackboard = BlackBoard::GetInstance(); // Get the singleton instance
  SystemManager manager(blackboard);

  std::string boardname = "Placa Arduino";
  std::string sensor1 = "SensorIR";
  std::string sensor2 = "SensorTE";
  std::string belt1 = "Cinta 1";
  std::string belt2 = "Cinta 2";
  
  std::cout << "Agregando placa al sistema" << std::endl;
  manager.AddBoardToSystem(boardname, 1, 2, BoardType::ARDUINO);
  std::cout << "Agregando sensor1 al sistema" << std::endl;
  manager.AddSensorToSystem(sensor1, Port(std::string("0"), 0x1), SensorType::IR);
  std::cout << "Agregando sensor2 al sistema" << std::endl;
  manager.AddSensorToSystem(sensor2, Port(std::string("1"), 0x2), float(0.0f), float(100.0f), SensorType::TEMPERATURE);
  std::cout << "Agregando cinta1 al sistema" << std::endl;
  manager.AddBeltToSystem(belt1, Port(std::string("2"), 0x3), float(20.0f), float(2.0f));
  std::cout << "Agregando cinta2 al sistema" << std::endl;
  manager.AddBeltToSystem(belt2, Port(std::string("3"), 0x4), float(10.0f), float(1.0f));

  std::cout << "Se han agregado todas las piezas al sistema." << std::endl;

  #if _DEBUG_
    blackboard->PrintBoard();
    blackboard->PrintSensors();
    blackboard->PrintBelts();
  #endif

  std::cout << "Data del primer sensor: "
            << manager.GetSensorData(sensor1, Port(std::string("0"), 0x1)).GetValue().digital << std::endl;

  std::cout << "Data del segundo sensor: "
            << manager.GetSensorData(sensor2, Port(std::string("1"), 0x2)).GetValue().analog << std::endl;

  std::cout << "Eliminando el segundo sensor." << std::endl;
  manager.RemoveSensorFromSystem(sensor2);

  std::cout << "Eliminando la primera cinta." << std::endl;
  manager.RemoveBeltFromSystem(belt1);

  #if _DEBUG_
    blackboard->PrintBoard();
    blackboard->PrintSensors();
    blackboard->PrintBelts();
  #endif

  return 0;
}