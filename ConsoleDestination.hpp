//
//  ConsoleDestination.hpp
//  LogBox
//
//  Created by Haizhen Lee on 2018/4/22.
//  Copyright © 2018 Haizhen Lee. All rights reserved.
//

#ifndef ConsoleDestination_hpp
#define ConsoleDestination_hpp

#include <iostream>
#include "BaseDestination.hpp"

namespace logbox {
  class ConsoleDestination : public BaseDestination{

  public:
    virtual string send(LogLevel level, string message,string threadName, long threadId, string filename, string className, string methodName, int lineNumber) const override{
      auto msg = BaseDestination::send(level, message, threadName, threadId, filename, className, methodName, lineNumber);
      std::cout << msg << std::endl;
      return msg;
    }
  };
}


#endif /* ConsoleDestination_hpp */
