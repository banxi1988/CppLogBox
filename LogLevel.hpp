//
//  LogLevel.hpp
//  LogBox
//
//  Created by Haizhen Lee on 2018/4/21.
//  Copyright © 2018 Haizhen Lee. All rights reserved.
//

#ifndef LogLevel_hpp
#define LogLevel_hpp
#include<string>

namespace logbox{
  enum class LogLevel{
    verbose,
    debug,
    info,
    warn,
    error
  };

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

#endif /* LogLevel_hpp */
