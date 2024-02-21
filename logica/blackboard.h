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
  //std::vector<std::shared_ptr<IControlBoard>> control_boards;
  bool alarm_active = false;

  std::vector<std::unique_ptr<ISensor>> sensors;
  std::vector<std::unique_ptr<Belt>> belts;

public:
  // Not clonable
  BlackBoard(BlackBoard &other) = delete;

  // Not assignable
  void operator=(const BlackBoard &) = delete;

  // Delete instance
  ~BlackBoard() {
    delete instance;
    instance = nullptr;
  }

  static BlackBoard *GetInstance();
  void SetControlBoard(std::shared_ptr<IControlBoard> board);

  //std::shared_ptr<IControlBoard> GetBoard(std::string &name);
  void UpdateSensors();
  void UpdateBelts();
  
  Data ReadSensor(const std::string &name);
  float ReadBelt(const std::string &name);
  Data ReadPort(Port port);
  void WritePort(Port port, Data data);

  void AddBoard(std::shared_ptr<IControlBoard> board);
  void AddSensor(std::unique_ptr<ISensor> sensor);
  void AddBelt(std::unique_ptr<Belt> belt);

  void EditBoard(std::string &name, uint32_t id_vendor, uint32_t id_product);
  void EditBoard(std::string &name, std::string &new_name, uint32_t id_vendor, uint32_t id_product);
  void EditBelt(std::string &name, Port port, float length, float speed);
  void EditBelt(std::string &name, std::string &new_name, Port port, float length, float speed);
  void EditSensor(std::string &name, Port port, float lower_limit, float upper_limit);
  void EditSensor(std::string &name, std::string &new_name, Port port, float lower_limit, float upper_limit);

  void RemoveBoard();
  void RemoveSensor(std::string &name);
  void RemoveBelt(std::string &name);

  #ifdef _DEBUG_
    void PrintBoard() const;
    void PrintSensors() const;
    void PrintBelts() const;
  #endif
};

#endif
