// Copyright 2020 Robotech URJC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/* Author: Fernando González fergonzaramos@yahoo.es */

#ifndef ICARUS_DRIVER__ICARUS_DRIVER_HPP_
#define ICARUS_DRIVER__ICARUS_DRIVER_HPP_

#include <string>
#include <ros/ros.h>

namespace icarus_driver
{
  class IcarusDriver
  {

  public:
    IcarusDriver();

    void setMode(std::string mode);
    void armDisarm(int arm);
    void takeoff(float lat, float lon, float alt);

  private:
    void initParams();
    void notifyAck(std::string msg);  // notify if last command wass succesfully or not

    ros::NodeHandle nh_;


    ros::Publisher ack_notifier_;
    std::string set_mode_srv_, arm_disarm_srv_, takeoff_srv_;
  };
};  //namespace icarus_driver

#endif  // ICARUS_DRIVER__ICARUS_DRIVER_HPP_