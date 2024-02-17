#ifndef __CONTROL_BOARD__
#define __CONTROL_BOARD__

#include "../data.h"
#include "../port.h"

class IControlBoard {
public:
  virtual ~IControlBoard() = default;
  virtual void UpdateData() = 0;
  virtual Data GetData(Port port) const = 0;
  virtual void WriteToPort(Data data, Port port) = 0;
};

#endif