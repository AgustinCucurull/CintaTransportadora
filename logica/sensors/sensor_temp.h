#ifndef __SENSOR_TEMPERATURE__
#define __SENSOR_TEMPERATURE__

#include "sensor_base.h"

class SensorTemperature : public SensorBase {
  SensorTemperature(ControlBoard board_, Port port_)
      : board(board_), port(port_) {}
  ~SensorTemperature() = default;

  void UpdateData() override;
  Data GetData() override;
  std::string GetName() override;
  void GetName(std::string &name_) override;
  void SetLimits(IValueLimits limits) override;
  bool IsValidValue() override;
};

#endif
