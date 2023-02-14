//
//  Game.hpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <sstream>
#include <memory>
#include "Robot.hpp"
#include "ConsoleGrid.hpp"

namespace CocCoc
{
class Game {
public:
    Game(string input_file);
    vector<string> parseFileToCommands(string input_file);
    void Run();
    
private:
    string input_file_;
    std::unique_ptr<Robot> robot;
    std::unique_ptr<ConsoleGrid> console_grid;
};
}

#endif /* Game_hpp */
