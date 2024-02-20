#include "connection_info.h"

void ConnectionInfo::SetPort(Port p) {
  this->port = p;
}

void ConnectionInfo::SetControLBoard(IControlBoard *board_ptr) {
  this->control_board = std::make_shared<IControlBoard>(*board_ptr);
}

Port ConnectionInfo::GetPort() const {
  return this->port;
}

std::shared_ptr<IControlBoard> ConnectionInfo::GetControlBoard() const {
  return this->control_board;
}
