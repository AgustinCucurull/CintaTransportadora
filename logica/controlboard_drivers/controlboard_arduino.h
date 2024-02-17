#ifndef __CONTROLBOARD_ARDUINO__
#define __CONTROLBOARD_ARDUINO__

#include "controlboard_base.h"

class ControlBoardArduino {
public:
  IControlBoard();
  ~IControlBoard() = default;
  UpdateData() override;
  Data GetData(Port port) override;
  WriteToPort(Data data, Port port) override;
};

#endif