//
//  Robot.cpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#include "Robot.hpp"
#include <utility>
#include <iostream>
#include <math.h>


namespace CocCoc
{
using namespace std;

Robot::Robot(int x, int y) : pos_x{x}, pos_y{y} {}

Robot::~Robot() {
    
}

std::pair<int, int> Robot::getPos() {
    std::pair<int, int> position = std::make_pair(pos_x, pos_y);
    return position;
}

void Robot::setPos(int x, int y) {
    pos_x = x;
    pos_y = y;
}

void Robot::moveTo(int x, int y, std::unique_ptr<ConsoleGrid> &console_grid) {
    this->setPos(x, y);
}

void fillPixel(int major, int minor, bool horizontal, std::unique_ptr<ConsoleGrid> &console_grid) {
    
    if (horizontal) // x is major axis
        console_grid->updateGrid(major, minor);
    else // y is major axis
        console_grid->updateGrid(minor, major);
}

void fillPixels(int start, int end, int start_minor, double slope, bool horizontal, std::unique_ptr<ConsoleGrid> &console_grid) {
    int advance = end > start ? 1 : -1;
    double cur_minor = start_minor + 0.5 + (0.5 * advance * slope);
    for (int cur_major = start + advance; cur_major != end; cur_major += advance)
    {
        fillPixel(cur_major, (int)floor(cur_minor), horizontal, console_grid);
        
        double new_minor = cur_minor + (advance * slope);
        if (floor(new_minor) != floor(cur_minor) && slope != 1)
            fillPixel(cur_major, (int)floor(new_minor), horizontal, console_grid);
        
        cur_minor = new_minor;
    }
}

void Robot::lineTo(int x, int y, std::unique_ptr<ConsoleGrid> &console_grid) {
    auto [pos_x, pos_y] = this->getPos();
    fillPixel(pos_x, pos_y, true, console_grid);
    
    if (pos_x == x && pos_y == y)
        return;
    
    fillPixel(x, y, true, console_grid);
    
    if (abs(x - pos_x) >= abs(y - pos_y))
        fillPixels(pos_x, x, pos_y, (double)(y - pos_y) / (double)(x - pos_x), true, console_grid);
    else
        fillPixels(pos_y, y, pos_x, (double)(x - pos_x) / (double)(y - pos_y), false, console_grid);
    
    this->setPos(x, y);
    
}
}
