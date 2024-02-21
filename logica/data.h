#ifndef __DATA__
#define __DATA__

#include "port.h"

union Value {
  std::uint32_t digital;
  float analog;

  Value() : digital(0) {}
  Value(std::uint32_t val) : digital(val) {}
  Value(float val) : analog(val) {}
};

class Data {
private:
  Value value;
  Port port;

public: 
  Data() {}
  Data(std::uint32_t v, Port p) : value(v), port(p) {}
  Data(float v, Port p) : value(v), port(p) {}
  ~Data() = default;

  Value GetValue() const;
  Port GetPort() const;
  void SetValue(Value v);
  void SetPort(Port p);
};

#endif