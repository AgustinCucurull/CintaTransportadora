#include "data.h"

// -----------------------------------------------------------------------------
// Getters

Value Data::GetValue() const {
  return this->value;
}

Port Data::GetPort() const {
  return this->port;
}

// -----------------------------------------------------------------------------
// Setters

void Data::SetValue(Value v) {
  this->value = v;
}

void Data::SetPort(Port p) {
  this->port = p;
}

// -----------------------------------------------------------------------------
