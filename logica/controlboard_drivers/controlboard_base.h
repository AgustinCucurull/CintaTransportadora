#ifndef __CONTROLBOARD_BASE__
#define __CONTROLBOARD_BASE__

#include <vector>
#include <cstdint>
#include "icontrolboard.h"
#include "board_type.h"

class ControlBoardBase : public IControlBoard {
protected:
  std::string name;
  uint32_t id_vendor;
  uint32_t id_product;
  BoardType type;
  std::vector<Data> v_data;
public:
  ControlBoardBase(const std::string &name_, uint32_t vendor, uint32_t product)
                   : name(name_), id_vendor(vendor), id_product(product) {}
};

#endif