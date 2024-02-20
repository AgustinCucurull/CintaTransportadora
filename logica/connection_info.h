#ifndef __CONNECTION_INFO__
#define __CONNECTION_INFO__

#include <memory>
#include "./controlboard_drivers/icontrolboard.h"

class ConnectionInfo {
private:
  Port port;
  std::shared_ptr<IControlBoard> control_board;

public:
  ConnectionInfo(IControlBoard *board_ptr, Port port_)
                : control_board(std::make_shared<IControlBoard>(*board_ptr)),
                  port(port_) {}
  ~ConnectionInfo() = default;

  void SetPort(Port p);
  void SetControLBoard(IControlBoard* board_ptr);

  Port GetPort() const;
  std::shared_ptr<IControlBoard> GetControlBoard() const;
};

#endif