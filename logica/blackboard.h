#ifndef __BLACKBOARD__
#define __BLACKBOARD__

#include <vector>
#include <string>
#include "./sensors/isensor.h"
#include "belt.h"

class BlackBoard {
private:
  BlackBoard() {} // Prevent the constructor from being called with new
                  // externally

  static BlackBoard *instance = nullptr;
  ControlBoard *control_board = nullptr;
  bool alarm_active = false;

  std::vector<ISensor*> sensors;
  std::vector<Belt*> belts;

public:
  // Not clonable
  Singleton(Singleton &other) = delete;

  // Not assignable
  void operator=(const Singleton &) = delete;

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
  void SetControlBoard(ControlBoard* &board);

  void UpdateSensors();
  void UpdateBelts();

  Data ReadSensor(std::string &name);
  void WriteToBoard(Data data, Port port);

  void AddSensor(ISensor* &sensor);
  void AddBelt(Belt* &belt);

  void RemoveSensor(std::string &name);
  void RemoveBelt(std::string &name);
};

#endif
