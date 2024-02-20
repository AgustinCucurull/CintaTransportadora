#include "controlboard_arduino.h"

// -----------------------------------------------------------------------------

void ControlBoardArduino::UpdateData() {
  return; // stubbed
}

// -----------------------------------------------------------------------------
// Getters

Data ControlBoardArduino::GetData(Port port) const {
  for (auto &data : v_data) {
    if (data.GetPort() == port) {
      return data; // ensure port is valid before calling this
    }
  }
}

std::string ControlBoardArduino::GetName() const {
  return this->name;
}

// -----------------------------------------------------------------------------
// Setters

void ControlBoardArduino::SetName(std::string &new_name) {
  this->name = new_name;
}

void ControlBoardArduino::SetIdVendor(uint32_t idvendor) {
  this->id_vendor = idvendor;
}

void ControlBoardArduino::SetIdProduct(uint32_t idproduct) {
  this->id_product = idproduct;
}

void ControlBoardArduino::WriteToPort(Data data, Port port) {
  return; // stubbed
}

// -----------------------------------------------------------------------------