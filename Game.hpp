//
//  Game.hpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#ifndef Game_hpp
#define Game_hpp

#include "Robot.hpp"
#include "ConsoleGrid.hpp"
#include <string>

namespace CocCoc
{
class Game {
public:
    Game(std::string input_file);
    std::vector<std::string> parseFileToCommands(std::string input_file);
    void Run();
    
private:
    std::string input_file_;
    std::unique_ptr<Robot> robot;
    std::unique_ptr<ConsoleGrid> console_grid;
};
}

#endif /* Game_hpp */
