#ifndef __CONTROLBOARD_ARDUINO__
#define __CONTROLBOARD_ARDUINO__

#include <memory>
#include "controlboard_base.h"

class ControlBoardArduino : public ControlBoardBase {
public:
  ControlBoardArduino(std::string &name_, uint32_t vendor, uint32_t product)
                      : ControlBoardBase(name_, vendor, product)
                      { type = BoardType::ARDUINO; }

  ControlBoardArduino(std::shared_ptr<IControlBoard> controlboard_ptr)
                      : ControlBoardBase(controlboard_ptr->GetName(),
                        controlboard_ptr->GetIdVendor(),
                        controlboard_ptr->GetIdProduct())
                      { type = BoardType::ARDUINO; }

  ~ControlBoardArduino() = default;

  void UpdateData() override;

  Data GetData(Port port) const override;
  std::string GetName() const override;
  BoardType GetType() const override;
  uint32_t GetIdVendor() const override;
  uint32_t GetIdProduct() const override;

  void SetName(std::string &new_name) override;
  void SetIdVendor(uint32_t idvendor) override;
  void SetIdProduct(uint32_t idproduct) override;

  void WriteToPort(Data data, Port port) override;
};

#endif