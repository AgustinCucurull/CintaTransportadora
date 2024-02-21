#ifndef __PORT__
#define __PORT__

#include <cstdint> // For uint8_t
#include <string>

class Port {
private:
  std::string code; // Analog: "A1", Digital: "1", etc.
  uint8_t address; // 0x45, registers, etc.

public:
  Port() {}
  Port(std::string code_, uint8_t address_) : code(code_), address(address_) {}
  ~Port() = default;

  bool operator==(const Port& other) const {
    return this->code == other.code && this->address == other.address;
  }

  std::string GetCode();
  uint8_t GetAddress();

  void SetCode(std::string code_);
  void SetAddress(uint8_t address_);
};

#endif