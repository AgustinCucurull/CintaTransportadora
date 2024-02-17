#include <iostream>

#include "./controlboard_drivers/controlboard_arduino.h"
#include "blackboard.h"

enum class ProgramState {
  SENSOR_WINDOW,
  BELT_WINDOW,
  MAIN_WINDOW,
  QUIT
};

void ReadAndUpdateData(BlackBoard *blackboard, ProgramState &program_state) {
  bool updating = true;

  do {
    // if event "AddSensor"
    // program_state = ProgramState::SENSOR_WINDOW;
    // updating = false;
    // break;

    // if event "AddBelt"
    // program_state = ProgramState::SENSOR_WINDOW;
    // updating = false;
    // break;

    blackboard->UpdateSensors();
    blackboard->UpdateBelts();
  } while (updating);
}

void AddSensor(BlackBoard *blackboard, ProgramState program_state) {
  ISensor sensor = new SensorTemperature();
  //Get name
  sensor->SetName(name);
}

int main(int argc, char const *argv[]) {
  ControlBoard *board_arduino = new ControlBoardArduino;
  // Initialize board_arduino
  // (...)

  BlackBoard blackboard;
  blackboard.SetControlBoard(board_arduino);
  // Add sensors and belts to the blackboard
  // (...)

  ProgramState program_state = ProgramState::MAIN_WINDOW;
  bool running = true;

  do {
    switch(program_state) {
    case ProgramState::MAIN_WINDOW;
      ReadAndUpdateData(&blackboard, program_state);
      break;
    case ProgramState::SENSOR_WINDOW:
      AddSensor(&blackboard, program_state);
      break;
    case ProgramState::BELT_WINDOW:
      AddBelt(&blackboard, program_state);
      break;
    case ProgramState::QUIT:
      running = false;
    }
  } while (running)

  // Clean memory etc.

  return 0;
}