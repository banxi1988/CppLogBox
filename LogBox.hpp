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
#include "BaseDestination.hpp"
#include "LogLevel.hpp"

namespace logbox {
  using namespace std;
  
  class LogBox{
  private:
    vector<BaseDestination> destinations;

    void dispatchSend(LogLevel level, string message, string filename, int lineNumber ) const{
      if(destinations.empty()){
        return;
      }
      for(const auto& dest: destinations){
        dest.send(level, message, "", 0, filename, "", "", lineNumber);
      }
    }
  public:
    bool addDestination(const BaseDestination& destination){
      destinations.push_back(destination);
      return true;
    }

    void info(string message,string filename = __FILE__, int lineNumber = __LINE__) const{
      this->dispatchSend(LogLevel::info, message, filename, lineNumber);
    }
  };
  LogBox logbox;
}

#endif /* LobBox_hpp */
