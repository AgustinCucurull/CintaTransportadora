#ifndef __SENSOR_IR__
#define __SENSOR_IR__

#include <string>
#include "sensor_base.h"
#include "../data.h"

class SensorIR : public SensorBase {
public:
  SensorIR(std::string &name_, Port port_) : SensorBase(name_, port_) {}
  ~SensorIR() = default;

  Data GetData() const override;
  Port GetPort() const override;
  std::string GetName() const override;
  
  void SetPort(Port port_) override;
  void SetData(Data data_) override;
  void SetName(std::string& name_) override;
  void SetLimits(std::unique_ptr<IValueLimits> &&limits_) override;

  bool IsValidValue() const override;
};

#endif
