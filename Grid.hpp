//
//  Grid.hpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#ifndef Grid_hpp
#define Grid_hpp

namespace CocCoc
{
class Grid {
public:
    virtual ~Grid() {};
    virtual void initiateGrid(int size) = 0;
    virtual void updateGrid(int x, int y) = 0;
    virtual void output() = 0;
};

}

#endif /* Grid_hpp */
