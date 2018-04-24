//
//  Utils.cpp
//  LogBox
//
//  Created by Haizhen Lee on 2018/4/21.
//  Copyright © 2018 Haizhen Lee. All rights reserved.
//

#include "Utils.hpp"

namespace logbox{
  using std::vector;
  using std::stringstream;
  using std::string;

  vector<string> split(string str, char sep){
    vector<string> tokens;
    string token;
    std::istringstream tokenStream(str);
    while(getline(tokenStream, token, sep)){
      tokens.push_back(token);
    }
    return tokens;
  }

  string  formatDate(string dateFormat){
    auto now = time(nullptr);
    auto tm = *localtime(&now);
    stringstream ss;
    ss <<  std::put_time(&tm, dateFormat.c_str());
    return  ss.str();
  }
}
