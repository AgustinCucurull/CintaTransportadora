#include "data.h"

// -----------------------------------------------------------------------------
// Getters

Value Data::GetValue() {
  return this->value;
}

Port Data::GetSenderPort() {
  return this->sender_port;
}

// -----------------------------------------------------------------------------
// Setters

void Data::SetValue(Value v) {
  this->value = v;
}

void Data::SetSenderPort(Port p) {
  this->sender_port = p;
}

// -----------------------------------------------------------------------------
