#ifndef __CONTROLBOARD_ARDUINO__
#define __CONTROLBOARD_ARDUINO__

#include "controlboard_base.h"

class ControlBoardArduino : public ControlBoardBase {
public:
  ControlBoardArduino(std::string &name_, uint32_t vendor, uint32_t product)
                      : ControlBoardBase(name_, vendor, product) {}
  ~ControlBoardArduino() = default;

  void UpdateData() override;

  Data GetData(Port port) const override;
  std::string GetName() const override;

  void SetName(std::string &new_name) override;
  void SetIdVendor(uint32_t idvendor) override;
  void SetIdProduct(uint32_t idproduct) override;

  void WriteToPort(Data data, Port port) override;
};

#endif