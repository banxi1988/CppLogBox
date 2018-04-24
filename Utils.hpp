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


namespace logbox{

  std::vector<std::string> split(std::string str, char sep);

  std::string  formatDate(std::string dateFormat);
}
#endif /* Utils_hpp */
