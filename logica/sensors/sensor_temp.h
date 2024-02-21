#ifndef __SENSOR_TEMPERATURE__
#define __SENSOR_TEMPERATURE__

#include "sensor_base.h"

class SensorTemperature : public SensorBase {
public:
  SensorTemperature(std::string &name_, Port port_) : SensorBase(name_, port_)
                   { type = SensorType::TEMPERATURE; }
  SensorTemperature() { type = SensorType::TEMPERATURE; }
  ~SensorTemperature() = default;

  std::string GetName() const override;
  Data GetData() const override;
  Port GetPort() const override;
  SensorType GetType() const override;

  void SetName(std::string& name_) override;
  void SetPort(Port port_) override;
  void SetData(Data data_) override;
  void SetType(SensorType type_) override;
  void SetLimits(std::unique_ptr<IValueLimits>&& limits_) override;

  bool IsValidValue() const override;
};

#endif
