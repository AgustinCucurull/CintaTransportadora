#include "log.h"
#include <algorithm>
#include "blackboard.h"
#include "./value_limits/temperature_limits.h"
#include "./controlboard_drivers/board_type.h"
#include "./controlboard_drivers/controlboard_arduino.h"

// BlackBoard* BlackBoard::instance = nullptr;
BlackBoard* BlackBoard::instance = nullptr;

// -----------------------------------------------------------------------------
// Getters

// * Blackboard is a singleton, therefore, we want to always return the same
// * instance (or create it, in case it doesn't exist).
BlackBoard *BlackBoard::GetInstance() {
  if (instance == nullptr) {
    instance = new BlackBoard;
  }
  return instance;
}

// -----------------------------------------------------------------------------
// Setters

// * Set the control board to be used with the system (Arduino, PLC, etc.)
void BlackBoard::SetControlBoard(std::shared_ptr<IControlBoard> board) {
  switch(board->GetType()) {
  case BoardType::ARDUINO:
    this->control_board = std::make_shared<ControlBoardArduino>(board);
    _LOG("Control board \"%s\" was added to the system.", board->GetName().c_str());
    break;
  }
}

// -----------------------------------------------------------------------------
// Data management

// * Iterate over all the sensors and pull the data from the control board.
// * Check if the values of the sensor are within the corresponding limits.
// * If the values are invalid, raise the alarm.
void BlackBoard::UpdateSensors() {
  _LOG("Updating sensors.");
  bool alarm = false;
  for (auto &current_sensor : this->sensors) {
    _LOG("Sensor [%s] was: %f", current_sensor->GetData().GetValue().analog);
    current_sensor->SetData(this->ReadPort(current_sensor->GetPort()));
    _LOG("Sensor [%s] is now: %f.", current_sensor->GetData().GetValue().analog);
    alarm |= current_sensor->IsValidValue();
  }
  this->alarm_active = alarm;
}

// * Since this is a blackboard-inspired design, we update the vector of
// * subscribed elements.
void BlackBoard::UpdateBelts() {
  _LOG("Updating belts.");
  for (auto &current_belt : this->belts) {
    _LOG("Belt [%s] was: %f", current_belt->GetSpeed());
    current_belt->UpdateAlarmStatus(this->alarm_active);
    current_belt->UpdateState();
    current_belt->UpdateSpeed();
    _LOG("Belt [%s] is now: %f.", current_belt->GetSpeed());

    Data packet = Data(current_belt->GetSpeed(), current_belt->GetPort());
    _LOG("Sending data packet to the control board.");
    this->WritePort(packet.GetPort(), packet);
  }
}

// * Iterate over the sensor vector, return "data" if "name" matches the 
// * sensor's name.
// * Technically, "name" is always a valid field (i.e. we track the names of all
// * the sensors' names outside this class in the GUI, and there's a 1:1
// * correspondence between them). However, we may want to consider a way to
// * handle the cases when "name" is not contained in the vector.
// * TODO (ESuez): This should be implemented with std::unordered_map for performance reasons
Data BlackBoard::ReadSensor(const std::string &name) {
  _LOG("Reading sensors (looking for \"%s\").", name.c_str());
  for (auto& current_sensor : this->sensors) {
    _LOG("Current Sensor: %s", current_sensor->GetName().c_str());
    if (current_sensor->GetName() == name) {
      return current_sensor->GetData();
    }
  }

  // Silence compiler error
  _LOGERR("Couldn't find sensor \"%s\" within the system!");
  return Data(1u, Port());
}

float BlackBoard::ReadBelt(const std::string &name) {
  _LOG("Reading belts (looking for \"%s\").", name.c_str());
  for (auto &belt : this->belts) {
    _LOG("Current belt: %s", belt->GetName());
    if (belt->GetName() == name) {
      return belt->GetSpeed();
    }
  }

  // Silence compiler error
  _LOGERR("Couldn't find belt \"%s\" within the system!");
  return 0.0f;
}

Data BlackBoard::ReadPort(Port port) {
  return this->control_board->GetData(port);
}

// * Write data to the control board
// * (i.e. the value that controls the speeds of the belts)
void BlackBoard::WritePort(Port port, Data data) {
  this->control_board->WriteToPort(data, port);
}

// -----------------------------------------------------------------------------
// Sensor and belt management

// void BlackBoard::AddBoard(std::shared_ptr<IControlBoard> board) {
//   this->control_boards.emplace_back(board)
// }

// * Add sensor to the vector.
void BlackBoard::AddSensor(std::unique_ptr<ISensor> sensor) {
  _LOG("Emplacing sensor \"%s\" at the end of the vector.", sensor->GetName().c_str());
  this->sensors.emplace_back(std::move(sensor));
}

// void BlackBoard::AddSensor(std::unique_ptr<ISensor>&& sensor) {
//   this->sensors.push_back(sensor);
// }


// * Add belt to the vector.
void BlackBoard::AddBelt(std::unique_ptr<Belt> belt) {
  _LOG("Emplacing belt \"%s\" at the end of the vector.", belt->GetName().c_str());
  this->belts.emplace_back(std::move(belt));
}

void BlackBoard::EditBoard(std::string &name, uint32_t id_vendor, uint32_t id_product) {
  // for (auto& control_board : this->control_boards) {
     if (control_board->GetName() == name) {
       control_board->SetIdVendor(id_vendor);
       control_board->SetIdProduct(id_product);
       return;
     }
  // }
}

void BlackBoard::EditBoard(std::string &name, std::string &new_name, uint32_t id_vendor, uint32_t id_product) {
  // for (auto& controlboard : this->control_boards) {
    if (control_board->GetName() == name) {
      control_board->SetIdVendor(id_vendor);
      control_board->SetIdProduct(id_product);
      control_board->SetName(new_name);
      
      return;
     }
  // }
}

void BlackBoard::EditBelt(std::string &name, Port port, float length, float speed) {
  for (auto& belt : this->belts) {
    if (belt->GetName() == name) {
      belt->SetPort(port);
      belt->SetLength(length);
      belt->SetObjectiveSpeed(speed);
    }
  }
}

void BlackBoard::EditBelt(std::string &name, std::string &new_name, Port port, float length, float speed) {
  for (auto& belt : this->belts) {
    if (belt->GetName() == name) {
      belt->SetPort(port);
      belt->SetLength(length);
      belt->SetObjectiveSpeed(speed);
      belt->SetName(new_name);

      return;
    }
  }
}

void BlackBoard::EditSensor(std::string &name, Port port, float lower_limit, float upper_limit) {
  for (auto& sensor : this->sensors) {
    if (sensor->GetName() == name) {
      sensor->SetPort(port);
      switch (sensor->GetType()) {
      case SensorType::IR:
        return;
      case SensorType::TEMPERATURE:
        sensor->SetLimits(std::make_unique<TemperatureLimits>(lower_limit, upper_limit));
        break;
      }

      return;
    }
  }
}

void BlackBoard::EditSensor(std::string &name, std::string &new_name, Port port, float lower_limit, float upper_limit) {
  for (auto& sensor : this->sensors) {
    if (sensor->GetName() == name) {
      sensor->SetPort(port);
      sensor->SetName(new_name);

      switch (sensor->GetType()) {
      case SensorType::IR:
        break;
      case SensorType::TEMPERATURE:
        sensor->SetLimits(std::make_unique<TemperatureLimits>(lower_limit, upper_limit));
        break;
      }

      return;
    }
  }
}

// void BlackBoard::AddBelt(std::unique_ptr<Belt>&& belt) {
//   this->belts.push_back(belt);
// }

void BlackBoard::RemoveBoard() {
  _LOG("Removing the control board from the system");
  this->control_board.reset();
}

// * Remove sensor from the vector if the field "name" matches with the internal
// * name.
void BlackBoard::RemoveSensor(std::string &name) {
  _LOG("Removing the sensor \"%s\" from the system.", name.c_str());
  this->sensors.erase(std::remove_if(this->sensors.begin(), this->sensors.end(),
                                     [&](const std::unique_ptr<ISensor>& sensor) {
                                       return sensor->GetName() == name;
                                     }),
                      this->sensors.end());
}

// * Remove belt from the vector if the field "name" matches with the internal
// * name.
void BlackBoard::RemoveBelt(std::string &name) {
  _LOG("Removing the belt \"%s\" from the system.", name.c_str());
  this->belts.erase(std::remove_if(this->belts.begin(), this->belts.end(),
                                     [&](const std::unique_ptr<Belt>& belt) {
                                       return belt->GetName() == name;
                                     }),
                      this->belts.end());
}

// -----------------------------------------------------------------------------

#ifdef _DEBUG_
  void BlackBoard::PrintBoard() const {
    _LOG("Printing boards in the system.");
    if (this->control_board != nullptr) {
      std::cout << "Board \"" << this->control_board->GetName() << "\":" << std::endl;
      std::cout << "\tID vendor: " << this->control_board->GetIdVendor() << std::endl;
      std::cout << "\tID product: " << this->control_board->GetIdProduct() << std::endl;
      std::cout << std::endl;
    } else {
      std::cout << "No blackboard attached to the system." << std::endl;
    }
  }

  void BlackBoard::PrintSensors() const {
    _LOG("Printing the sensors in the system.");
    for (auto& sensor : this->sensors) {
      std::cout << "Sensor \"" << sensor->GetName() << "\":" << std::endl;
      std::cout << "\tPort: "
               << sensor->GetPort().GetCode() << " (0x"
               << sensor->GetPort().GetAddress() << ")" << std::endl;
      std::cout << "\tValue: [D: "
               << sensor->GetData().GetValue().digital << ", A: "
               << sensor->GetData().GetValue().analog << "]" << std::endl;
      std::cout << std::endl;
    }
  }

  void BlackBoard::PrintBelts() const {
    _LOG("Printing the belts in the system.");
    for (auto& belt : this->belts) {
      std::cout << "Belt \"" << belt->GetName() << "\":" << std::endl;
      std::cout << "\tPort: "
               << belt->GetPort().GetCode() << " (0x"
               << belt->GetPort().GetAddress() << ")" << std::endl;
      std::cout << "\tLength: " << belt->GetLength() << " cm" << std::endl;
      std::cout << "\tCurrent Speed: " << belt->GetSpeed() << " cm/s" << std::endl;
      std::cout << "\tObjectiveSpeed Speed: " << belt->GetObjectiveSpeed() << " cm/s" << std::endl;
      std::cout << "\tTime: " << belt->GetObjectiveSpeed() << "s" << std::endl;
      std::cout << std::endl;
    }
  }
#endif

// -----------------------------------------------------------------------------