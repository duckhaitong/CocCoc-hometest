//
//  Robot.cpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#include "Robot.hpp"
#include <utility>
#include <iostream>
#include <cmath>
#define EPSILON 1e-9


namespace CocCoc
{
using namespace std;

Robot::Robot(int x, int y) : pos_x{std::move(x)}, pos_y{std::move(y)} {}

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
    setPos(x, y);
}

/**
 * check if minor-coordinate is on vertex of unit square,
 * equivalent to being an integer
 * @param minor the minor-coordinate
 * @return true if minor-coordinate is on vertex of unit square
 */
bool isVertex(double minor) {
    return abs(round(minor) - minor) < EPSILON;
}

void markSquare(int major, int minor, bool horizontal, std::unique_ptr<ConsoleGrid> &console_grid) {
    
    if (horizontal) // x is major axis
        console_grid->updateGrid(major, minor);
    else // y is major axis
        console_grid->updateGrid(minor, major);
}

/**
 * mark all the unit squares that line passes between start point and end point
 */
void markSquares(int start, int end, int start_minor, double slope, bool horizontal, std::unique_ptr<ConsoleGrid> &console_grid) {
    int advance = end > start ? 1 : -1;
    double cur_minor = start_minor + 0.5 + (0.5 * advance * slope);
    for (int cur_major = start + advance; cur_major != end; cur_major += advance)
    {
        int int_minor;
        if (isVertex(cur_minor)) {
            int_minor = (advance * slope) > 0 ? round(cur_minor) : round(cur_minor) - 1;
        } else {
            int_minor = static_cast<int>(floor(cur_minor));
        }
        markSquare(cur_major, int_minor, horizontal, console_grid);
        
        double new_minor = cur_minor + (advance * slope);
        if (floor(new_minor) != floor(cur_minor) && !isVertex(new_minor) && !isVertex(cur_minor))
             markSquare(cur_major, static_cast<int>(floor(new_minor)), horizontal, console_grid);
        
        cur_minor = new_minor;
    }
}

void Robot::lineTo(int x, int y, std::unique_ptr<ConsoleGrid> &console_grid) {
    auto [pos_x, pos_y] = getPos();
    markSquare(pos_x, pos_y, true, console_grid);
    
    if (pos_x == x && pos_y == y)
        return;
    
    markSquare(x, y, true, console_grid);
    
    if (abs(x - pos_x) >= abs(y - pos_y))
        markSquares(pos_x, x, pos_y, static_cast<double>((y - pos_y)) / static_cast<double>((x - pos_x)), true, console_grid);
    else
        markSquares(pos_y, y, pos_x, static_cast<double>((x - pos_x)) / static_cast<double>((y - pos_y)), false, console_grid);
    
    setPos(x, y);
    
}
}
