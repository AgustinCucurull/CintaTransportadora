#ifndef __SENSOR_TEMPERATURE__
#define __SENSOR_TEMPERATURE__

#include "sensor_base.h"

class SensorTemperature : public SensorBase {
  ~SensorTemperature() = default;

  Data GetData() const override;
  Port GetPort() const override;
  std::string GetName() const override;

  void SetPort(Port port_) override;
  void SetData(Data data_) override;
  void SetName(std::string& name_) override;
  void SetLimits(std::unique_ptr<IValueLimits>&& limits_) override;

  bool IsValidValue() const override;
};

#endif
