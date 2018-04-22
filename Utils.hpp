//
//  Utils.hpp
//  LogBox
//
//  Created by Haizhen Lee on 2018/4/21.
//  Copyright © 2018 Haizhen Lee. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

namespace logbox{
  using namespace std;
  vector<string> split(string str, char sep){
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while(getline(tokenStream, token, sep)){
      tokens.push_back(token);
    }
    return tokens;
  }

  string  formatDate(string dateFormat){
    auto now = time(nullptr);
    auto tm = *localtime(&now);
    stringstream ss;
    ss <<  put_time(&tm, dateFormat.c_str());
    return  ss.str();
  }
}
#endif /* Utils_hpp */
