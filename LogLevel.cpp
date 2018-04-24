//
//  LogLevel.cpp
//  LogBox
//
//  Created by Haizhen Lee on 2018/4/21.
//  Copyright © 2018 Haizhen Lee. All rights reserved.
//

#include "LogLevel.hpp"

namespace logbox {
  std::string to_string(const LogLevel level){
    switch (level) {
      case LogLevel::verbose: return "verbose";
      case LogLevel::debug: return "debug";
      case LogLevel::info: return "info";
      case LogLevel::warn: return "warn";
      case LogLevel::error: return "error";
    }
  }
}
