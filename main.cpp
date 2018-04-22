//
//  main.cpp
//  LogBox
//
//  Created by Haizhen Lee on 2018/4/21.
//  Copyright © 2018 Haizhen Lee. All rights reserved.
//

#include <iostream>
#include "LogBox.hpp"
#include "ConsoleDestination.hpp"

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  const logbox::ConsoleDestination consoleDest;
  logbox::logbox.addDestination(consoleDest);
  logbox::logbox.info("some thing happened");
  return 0;
}
