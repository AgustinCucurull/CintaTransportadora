#include "port.h"

// -----------------------------------------------------------------------------
// Getters

std::string Port::GetCode() {
  return this->code;
}

uint8_t Port::GetAddress() {
  return this->address;
}

// -----------------------------------------------------------------------------
// Setters

void Port::SetCode(st::string code_) {
  this->code = code_;
}

void SetAddress(uint8_t address_) {
  this->address = address_;
}

// -----------------------------------------------------------------------------