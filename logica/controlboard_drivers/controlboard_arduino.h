#ifndef __CONTROLBOARD_ARDUINO__
#define __CONTROLBOARD_ARDUINO__

#include "controlboard_base.h"

class ControlBoardArduino : public ControlBoardBase {
public:
  ControlBoardArduino() {}
  ~ControlBoardArduino() = default;
  void UpdateData() override;
  Data GetData(Port port) const override;
  void WriteToPort(Data data, Port port) override;
};

#endif