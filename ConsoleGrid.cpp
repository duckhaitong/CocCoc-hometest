//
//  ConsoleGrid.cpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#include "ConsoleGrid.hpp"
#include "Robot.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

namespace CocCoc
{
using namespace std;

ConsoleGrid::ConsoleGrid() {}

ConsoleGrid::~ConsoleGrid() {}

void ConsoleGrid::initiateGrid(int size) {
    vector<vector<int> > vec(size, vector<int>(size, 0));
    this->grid = vec;
}

void ConsoleGrid::updateGrid(int x, int y)
{
    this->grid[x][y] = 1;
}

void ConsoleGrid::output() {
    for (auto const & row : this->grid) {
        for (auto const & ele : row) {
            std::cout << ele << " ";
        }
        std::cout << std::endl;
    }
}
}
