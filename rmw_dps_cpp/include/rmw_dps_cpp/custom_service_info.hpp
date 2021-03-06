// Copyright 2018 Intel Corporation All rights reserved.
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

#ifndef RMW_DPS_CPP__CUSTOM_SERVICE_INFO_HPP_
#define RMW_DPS_CPP__CUSTOM_SERVICE_INFO_HPP_

#include <dps/dps.h>

#include <map>
#include <string>

#include "rmw_dps_cpp/Listener.hpp"

inline bool
operator<(const rmw_request_id_t & lhs, const rmw_request_id_t & rhs)
{
  return memcmp(&lhs, &rhs, sizeof(rmw_request_id_t)) < 0;
}

typedef struct CustomServiceInfo
{
  void * request_type_support_;
  void * response_type_support_;
  DPS_Subscription * request_subscription_;
  Listener * listener_;
  std::map<rmw_request_id_t, Publication> requests_;
  DPS_Node * node_;
  const char * typesupport_identifier_;
  std::string discovery_name_;
} CustomServiceInfo;

#endif  // RMW_DPS_CPP__CUSTOM_SERVICE_INFO_HPP_
