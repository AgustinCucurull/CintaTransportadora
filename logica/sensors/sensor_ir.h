#ifndef __SENSOR_IR__
#define __SENSOR_IR__

#include "sensor_base.h"

class SensorIR : public SensorBase {
  ~SensorIR() = default;
  void UpdateData() override;
  Data GetData() override;
  std::string GetName() override;
  void SetLimits(IValueLimits) override;
  bool IsValidValue() override;
}

#endif
