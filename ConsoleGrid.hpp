//
//  ConsoleGrid.hpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#ifndef ConsoleGrid_hpp
#define ConsoleGrid_hpp

#include "Grid.hpp"
#include <vector>

namespace CocCoc
{
class ConsoleGrid : public Grid {
public:
    ConsoleGrid();
    ~ConsoleGrid();
    
    void initiateGrid(int size);
    void updateGrid(int x, int y);
    void output();
    
private:
    std::vector<std::vector<int> > grid;
};

}

#endif /* ConsoleGrid_hpp */
