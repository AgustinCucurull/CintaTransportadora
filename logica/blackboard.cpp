#include <algorithm>
#include "blackboard.h"

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
  this->control_board = std::make_shared<IControlBoard>(board);
}

// -----------------------------------------------------------------------------
// Data management

// * Iterate over all the sensors and pull the data from the control board.
// * Check if the values of the sensor are within the corresponding limits.
// * If the values are invalid, raise the alarm.
void BlackBoard::UpdateSensors() {
  bool alarm = false;
  for (auto &current_sensor : this->sensors) {
    current_sensor->SetData(this->ReadPort(current_sensor->GetPort()));
    alarm |= current_sensor->IsValidValue();
  }
  this->alarm_active = alarm;
}

// * Since this is a blackboard-inspired design, we update the vector of
// * subscribed elements.
void BlackBoard::UpdateBelts() {
  for (auto &current_belt : this->belts) {
    current_belt->UpdateAlarmStatus(this->alarm_active);
    current_belt->UpdateState();
    current_belt->UpdateSpeed();
  }
}

// * Iterate over the sensor vector, return "data" if "name" matches the 
// * sensor's name.
// * Technically, "name" is always a valid field (i.e. we track the names of all
// * the sensors' names outside this class in the GUI, and there's a 1:1
// * correspondence between them). However, we may want to consider a way to
// * handle the cases when "name" is not contained in the vector.
Data BlackBoard::ReadSensor(std::string &name) {
  for (auto current_sensor : this->sensors) {
    if (current_sensor->GetName() == name) {
      return current_sensor->GetData();
    }
  }
}

Data BlackBoard::ReadPort(Port port) {
  return this->control_board->GetData(port);
}

// * Write data to the control board
// * (i.e. the value that controls the speeds of the belts')
void BlackBoard::WritePort(Port port, Data data) {
  this->control_board->WriteToPort(data, port);
}

// -----------------------------------------------------------------------------
// Sensor and belt management

// * Add sensor to the vector.
void BlackBoard::AddSensor(ISensor* &sensor) {
  this->sensors.push_back(sensor);
}

// * Remove sensor from the vector if the field "name" matches with the internal
// * name.
void BlackBoard::RemoveSensor(std::string &name) {
  this->sensors.erase(std::remove_if(this->sensors.begin(), this->sensors.end(),
                                     [&](const ISensor* &sensor) {
                                       return sensor->GetName() == name;
                                     }),
                      this->sensors.end());
}

// * Add belt to the vector.
void BlackBoard::AddBelt(Belt* &belt) {
  this->belts.push_back(belt);
}

// * Remove belt from the vector if the field "name" matches with the internal
// * name.
void BlackBoard::RemoveBelt(std::string &name) {
  this->belts.erase(std::remove_if(this->belts.begin(), this->belts.end(),
                                     [&](const Belt* &belt) {
                                       return belt->GetName() == name;
                                     }),
                      this->belts.end());
}

// -----------------------------------------------------------------------------