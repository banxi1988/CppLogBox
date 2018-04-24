//
//  Utils.hpp
//  LogBox
//
//  Created by Haizhen Lee on 2018/4/21.
//  Copyright © 2018 Haizhen Lee. All rights reserved.
//

#pragma once

#ifndef Utils_hpp
#define Utils_hpp

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <thread>


namespace logbox{

  std::vector<std::string> split(std::string str, char sep);

  std::string  formatDate(std::string dateFormat);

  /**
   * 将类似 H:m:s 这样的格式字符串转成 %H:%m:%s 即在每一个字母前面加上 %号。
   **/
  inline std::string normalizeDateFormat(const std::string& dateFormat){
    char  buffer  [80];
    int bufferIndex = 0;
    for( int i = 0;i < dateFormat.length() && bufferIndex < 78; i++){
      char ch = dateFormat.at(i);
      if(isalpha(ch)){
        buffer[bufferIndex] = '%';
        bufferIndex++;
      }
      buffer[bufferIndex] = ch;
      bufferIndex++;
    }
    buffer[bufferIndex] = '\0';
    return std::string(buffer);
  }

  inline uint64_t currentThreadId(){
    std::stringstream ss;
    ss << std::this_thread::get_id();
    return std::stoll(ss.str());
  }

  inline std::string basename(const std::string& filepath){
    auto parts = split(filepath, '/');
    return parts[parts.size() - 1];
  }
}
#endif /* Utils_hpp */
