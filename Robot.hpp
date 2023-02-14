//
//  Robot.hpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#ifndef Robot_hpp
#define Robot_hpp

#include "ConsoleGrid.hpp"

namespace CocCoc
{
class Robot {
public:
    Robot(int x, int y);
    ~Robot();
    void moveTo(int x, int y, std::unique_ptr<ConsoleGrid> &console_grid);
    void lineTo(int x, int y, std::unique_ptr<ConsoleGrid> &console_grid);
    void setPos(int x, int y);
    std::pair<int, int> getPos();
    
private:
    int pos_x;
    int pos_y;
};
}

#endif /* Robot_hpp */
