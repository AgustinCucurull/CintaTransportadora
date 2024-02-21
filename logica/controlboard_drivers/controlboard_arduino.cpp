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

  // Silence compile error
  return Data(1u, Port());
}

std::string ControlBoardArduino::GetName() const {
  return this->name;
}

BoardType ControlBoardArduino::GetType() const {
  return this->type;
}

uint32_t ControlBoardArduino::GetIdVendor() const {
  return this->id_vendor;
}
uint32_t ControlBoardArduino::GetIdProduct() const {
  return this->id_product;
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