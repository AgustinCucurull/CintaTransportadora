#include "controlboard_arduino.h"

void ControlBoardArduino::UpdateData() {
  return; // stubbed
}

Data ControlBoardArduino::GetData(Port port) const {
  for (auto &data : v_data) {
    if (data.GetPort() == port) {
      return data; // ensure port is valid before calling this
    }
  }
}

void ControlBoardArduino::WriteToPort(Data data, Port port) {
  return; // stubbed
}
