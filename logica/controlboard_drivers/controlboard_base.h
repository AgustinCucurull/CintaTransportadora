#ifndef __CONTROLBOARD_BASE__
#define __CONTROLBOARD_BASE__

#include <vector>
#include <cstdint>
#include "icontrolboard.h"

class ControlBoardBase : public IControlBoard {
protected:
  std::string name;
  uint32_t id_vendor;
  uint32_t id_product;
  std::vector<Data> v_data;
};

#endif