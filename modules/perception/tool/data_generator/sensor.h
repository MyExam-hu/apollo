/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 **/

#ifndef MODULES_PERCEPTION_DATA_GENERATOR_SENSOR_H_
#define MODULES_PERCEPTION_DATA_GENERATOR_SENSOR_H_

#include <string>

#include "modules/perception/tool/data_generator/proto/config.pb.h"

namespace apollo {
namespace perception {
namespace data_generator {

class Sensor {
 public:
  explicit Sensor(const SensorConfig& config) : config_(config) {}
  virtual ~Sensor() = default;
  virtual SensorConfig::SensorId Id() const {
    return config_.id();
  }
  virtual const std::string& SensorFrameName() const {
    return config_.sensor_frame_name();
  }
  virtual bool Process() = 0;

 protected:
  SensorConfig config_;
};

}  // namespace data_generator
}  // namespace perception
}  // namespace apollo

#endif  // MODULES_PERCEPTION_DATA_GENERATOR_SENSOR_H_
