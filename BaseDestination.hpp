//
//  BaseDestination.hpp
//  LogBox
//
//  Created by Haizhen Lee on 2018/4/21.
//  Copyright © 2018 Haizhen Lee. All rights reserved.
//

#ifndef BaseDestination_hpp
#define BaseDestination_hpp

#include <string>
#include <sstream>
#include "LogLevel.hpp"
#include "Utils.hpp"

namespace logbox{
  using std::string;

  class BaseDestination{
  public:
    string format = "%DHH:mm:ss.SSS%d [%L][%T][%t] %C.%F:%l - %M";

     virtual string send(LogLevel level, string message,string threadName, long threadId, string filename, string className, string methodName, int lineNumber) const{
      return this->formatMessage(this->format, level, message, threadName, threadId, filename, className, methodName, lineNumber);
    }

     string formatMessage(string format,LogLevel level,string message,string threadName, long threadId, string filename, string className, string methodName, int lineNumber) const{
      std::stringstream ss;
      auto phrases = split(this->format, '%');

      for(auto&& phrase : phrases){
        if(phrase.empty()){
          continue;
        }
        auto firstChar = phrase[0];
        auto remainPhrase = phrase.substr(1,phrase.size() -1);
        switch (firstChar) {
          case 'L':
            ss << to_string(level);
            break;
          case 'M':
            ss << message;
            break;
          case 'm':
            ss << message;
            break;
          case 'T':
            ss << threadName;
            break;
          case 't':
            ss << std::to_string(threadId);
            break;
          case 'N':
            ss << filename;
            break;
          case 'C':
            ss << className;
            break;
          case 'F':
            ss << methodName;
            break;
          case 'l':
            ss << std::to_string(lineNumber);
            break;
          case 'D':
            ss << formatDate(remainPhrase);
            remainPhrase = "";
            break;
          case 'd':
            break;
          default:
            remainPhrase = phrase;
            break;
        }
        ss << remainPhrase;
      }
      return ss.str();
    }
  };
}

#endif /* BaseDestination_hpp */
