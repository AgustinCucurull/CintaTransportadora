#ifndef __BELT__
#define __BELT__

#include <string>
#include <memory>
#include "./states/istate.h"
#include "./states/state_base.h"
#include "./states/state_type.h"
#include "port.h"

class Belt {
protected:
  Port port;
  std::string name;

  float length;
  float time;
  float objective_speed = 0;
  float current_speed = 0;

  bool alarm_active = false;
  std::unique_ptr<IState> state;

public:
  Belt(Port port_) : port(port_) { UpdateState(); }
  ~Belt() = default;

  void SetPort(Port port_);
  void SetName(std::string &name_);
  void SetLength(float length_);
  void SetObjectiveSpeed(float speed_);
  void SetTime(float time_);

  Port GetPort() const;
  std::string GetName() const;
  float GetLength() const;
  float GetSpeed() const;
  float GetObjectiveSpeed() const;
  float GetTime() const;

  void UpdateAlarmStatus(bool alarm);
  void UpdateState();
  void UpdateSpeed();
};

#endif
