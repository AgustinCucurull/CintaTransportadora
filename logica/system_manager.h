#ifndef __SYSTEM_MANAGER__
#define __SYSTEM_MANAGER__

#include <string>
#include "port.h"
#include "blackboard.h"
#include "./sensors/sensor_type.h"

class SystemManager {
private:
  BlackBoard *blackboard_instance;
public:
  SystemManager(BlackBoard *blackboard_) { blackboard_instance = blackboard_->GetInstance(); }
  ~SystemManager() = default;

  // Create objects and add them to the blackboard
  void AddBoardToSystem(std::string &name, uint32_t id_vendor, uint32_t id_product, BoardType type);
  void AddBeltToSystem(std::string &name, Port port, float length, float speed);
  void AddSensorToSystem(std::string &name, Port port, float lower_limit, float upper_limit, SensorType type);
  void AddSensorToSystem(std::string &name, Port port, SensorType type);

  // Edit object characteristics
  void EditBoard(std::string &name, uint32_t id_vendor, uint32_t id_product);
  void EditBoard(std::string &name, std::string &new_name, uint32_t id_vendor, uint32_t id_product);
  void EditBelt(std::string &name, Port port, float length, float speed);
  void EditBelt(std::string &name, std::string &new_name, Port port, float length, float speed);
  void EditSensor(std::string &name, Port port, float lower_limit, float upper_limit);
  void EditSensor(std::string &name, std::string &new_name, Port port, float lower_limit, float upper_limit);

  // Remove objects from the blackboard (and delete them)
  void RemoveBoardFromSystem(std::string &name);
  void RemoveSensorFromSystem(std::string &name);
  void RemoveBeltFromSystem(std::string &name);
};

#endif
