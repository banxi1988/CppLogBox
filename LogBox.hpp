//
//  LobBox.hpp
//  LogBox
//
//  Created by Haizhen Lee on 2018/4/21.
//  Copyright © 2018 Haizhen Lee. All rights reserved.
//

#ifndef LobBox_hpp
#define LobBox_hpp

#include <memory>
#include <vector>
#include <thread>
#include "BaseDestination.hpp"
#include "LogLevel.hpp"

namespace logbox {
  using std::string;

  class LogBox{
  private:
    std::vector<std::shared_ptr<BaseDestination>> destinations;

    void dispatchSend(LogLevel level, std::string message, std::string filename, int lineNumber ) const{
      if(destinations.empty()){
        return;
      }
      auto threadId = currentThreadId();
      for(const auto& destPtr: destinations){
        auto dest = destPtr.get();
        dest->send(level, message, threadId, filename, "", "", lineNumber);
      }
    }
  public:
    bool addDestination(const std::shared_ptr<BaseDestination> ptr){
      destinations.push_back(ptr);
      return true;
    }

    void info(std::string message,string filename = __FILE__, int lineNumber = __LINE__) const{
      this->dispatchSend(LogLevel::info, message, filename, lineNumber);
    }
  };
//  LogBox logbox;
}

#endif /* LobBox_hpp */
