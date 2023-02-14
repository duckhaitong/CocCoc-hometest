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
#include <vector>

namespace CocCoc
{
ConsoleGrid::ConsoleGrid() {}

ConsoleGrid::~ConsoleGrid() {}

void ConsoleGrid::initiateGrid(int size) {
    std::vector<std::vector<int> > vec(size, std::vector<int>(size, 0));
    grid = vec;
}

void ConsoleGrid::updateGrid(int x, int y)
{
    grid[x][y] = 1;
}

void ConsoleGrid::output() {
    for (auto const & row : grid) {
        for (auto const & ele : row) {
            std::cout << ele << " ";
        }
        std::cout << std::endl;
    }
    
    auto size = grid.size();
    std::cout << std::endl;
    std::cout<<" ";
    int i = 0;
    for (int j = 0; j <= 4 * size; j++){
        if (j % 4 == 2)
            std::cout << i++;
        else
            std::cout << " ";
    }
    std::cout << std::endl;
    
    for (int i = 0; i <= 2 * size; i++){
        if (i % 2 != 0)
            std::cout << i / 2;
        for (int j = 0; j <= 2 * size; j++){
            if (i % 2 == 0)
            {
                if (j == 0)
                    std::cout << " ";
                if (j % 2 == 0)
                    std::cout << " ";
                else
                    std::cout << "---";
            } else {
                if ( j % 2 == 0)
                    std::cout << "|";
                else {
                    if (grid[i / 2][j / 2] == 1)
                        std::cout << " + ";
                    else
                        std::cout << "   ";
                }
            }
        }
        std::cout << std::endl;
    }
}
}
