//
//  main.cpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#include "Game.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./main input_file" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string input_file = argv[1];
    CocCoc::Game(input_file.c_str());
    
    return 0;
}
