#ifndef __CONTROL_BOARD__
#define __CONTROL_BOARD__

#include <string>
#include <cstdint>
#include "../data.h"
#include "../port.h"
#include "board_type.h"

class IControlBoard {
public:
  virtual ~IControlBoard() = default;
  virtual void UpdateData() = 0;

  virtual Data GetData(Port port) const = 0;
  virtual std::string GetName() const = 0;
  virtual BoardType GetType() const = 0;
  virtual uint32_t GetIdVendor() const = 0;
  virtual uint32_t GetIdProduct() const = 0;

  virtual void SetName(std::string &new_name) = 0;
  virtual void SetIdVendor(uint32_t idvendor) = 0;
  virtual void SetIdProduct(uint32_t idvendor) = 0;
  
  virtual void WriteToPort(Data data, Port port) = 0;
};

#endif