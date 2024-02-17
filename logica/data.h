#ifndef __DATA__
#define __DATA__

#include "port.h"

union Value {
  std::uint32_t digital;
  float analog;
}

class Data {
private:
  Value value;
  // Port sender_port;
  Port port;

public:
  Data() {}
  Data(Value v, Port p) : value(v), sender_port(p) {}
  ~Data() = default;

  Value GetValue();
  Port GetSenderPort();
  void SetValue(Value v);
  void SetSenderPort(Port p);
};

#endif