#ifndef __CONTROL_BOARD__
#define __CONTROL_BOARD__

#include "../data.h"
#include "../port.h"

class IControlBoard {
public:
  virtual ~IControlBoard() = default;
  virtual UpdateData() = 0;
  virtual Data GetData(Port port) = 0;
  virtual WriteToPort(Data data, Port port) = 0;
};

#endif