#ifndef __DATA__
#define __DATA__

#include "port.h"

union Value {
  std::uint32_t digital;
  float analog;
};

class Data {
private:
  Value value;
  Port port;

public:
  Data() {}
  Data(Value v, Port p) : value(v), port(p) {}
  ~Data() = default;

  Value GetValue() const;
  Port GetPort() const;
  void SetValue(Value v);
  void SetPort(Port p);
};

#endif