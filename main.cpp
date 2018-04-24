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
  using logbox::log;
  const logbox::ConsoleDestination consoleDest ;
  log.addDestination(std::make_shared<logbox::ConsoleDestination>(consoleDest));
  log.info("some thing happened");
  return 0;
}
