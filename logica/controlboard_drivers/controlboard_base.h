#ifndef __CONTROLBOARD_BASE__
#define __CONTROLBOARD_BASE__

#include <vector>
#include "icontrolboard.h"

class ControlBoardBase : public IControlBoard {
protected:
  std::vector<Data> v_data;
};

#endif