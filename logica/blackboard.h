#ifndef __BLACKBOARD__
#define __BLACKBOARD__

#include <vector>
#include <memory>
#include <string>
#include "./sensors/isensor.h"
#include "./controlboard_drivers/icontrolboard.h"
#include "belt.h"

class BlackBoard {
private:
  BlackBoard() {} // Prevent the constructor from being called with new
                  // externally

  static BlackBoard *instance;
  std::shared_ptr<IControlBoard> control_board;
  bool alarm_active = false;

  std::vector<ISensor*> sensors;
  std::vector<Belt*> belts;

public:
  // Not clonable
  BlackBoard(BlackBoard &other) = delete;

  // Not assignable
  void operator=(const BlackBoard &) = delete;

  // Delete instance and vectors upon destruction
  ~BlackBoard() {
    if (instance != nullptr) {
      for (auto &sensor : this->sensors) {
        delete sensor;
        sensor = nullptr;
      }
      this->sensors.clear();

      for (auto &belt : this->belts) {
        delete belt;
        belt = nullptr;
      }
      this->belts.clear();

      delete instance;
      instance = nullptr;
    }
  }

  static BlackBoard *GetInstance();
  void SetControlBoard(std::shared_ptr<IControlBoard> board);

  void UpdateSensors();
  void UpdateBelts();

  Data ReadSensor(std::string &name);
  Data ReadPort(Port port);
  void WritePort(Port port, Data data);

  void AddSensor(ISensor* &sensor);
  void AddBelt(Belt* &belt);

  void RemoveSensor(std::string &name);
  void RemoveBelt(std::string &name);
};

// Definition of the static member variable outside the class
BlackBoard* BlackBoard::instance = nullptr;

#endif
