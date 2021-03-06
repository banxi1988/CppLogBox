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
    ConsoleDestination(){}

    virtual string send(LogLevel level, string message, uint64_t threadId, string filename, string className, string methodName, int lineNumber) const override{
//      std::cout << "ConsoleDestionation send is called" << std::endl;
      auto msg = BaseDestination::send(level, message,threadId, filename, className, methodName, lineNumber);
      std::cout << msg << std::endl;
      return msg;
    }
  };
}


#endif /* ConsoleDestination_hpp */
