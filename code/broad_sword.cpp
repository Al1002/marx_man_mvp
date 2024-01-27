#include "broad_sword.h"

#include <list>
#include <algorithm>
#include <stdexcept>

using std::list;
using std::find;

/*
targetable:

###
#@#
###

attacks:
  >
 @#
  >

or 
 >#
 @>


*/

    
    list<GamePos> BroadSword::targetable(GameLayer *layer, GamePos origin)
    {
        list<GamePos> targets;
        for(int x = -1; x <= 1; x++)
        {
            for(int y = -1; y <= 1; y++)
            {
                if(x == 0 && y == 0)
                    continue;
                GamePos target = GamePos(x,y);
                target = target + origin;
                if(layer->exists(target))
                {
                    targets.push_front(target);
                }
            }
        }
        return targets;
    }

    void BroadSword::attack(GameLayer *layer, GamePos origin, GamePos target)
    {
        auto targetable = this->targetable(layer, origin);
        if(!layer->exists(target))
        {
            throw new std::runtime_error("Out of bounds exception, attempting to target a cell that does not exist in the given layer!");
        }

        if(find(targetable.begin(), targetable.end(), target) == targetable.end()) // if target not found in targetable, i.e. reached end
        {
            throw new std::runtime_error("Invalid argument exception, attempting to target a cell that (BroadSword) cant target!");
        }
        
        list<GamePos> targeted;
        auto direction = target - origin;
        if(direction.x == 0) // if orthogonal...
        {
            for (int x = -1; x <= 1; x++) // draw 3 cell line (x direction)
            {
                targeted.push_front(target + GamePos(x,0));
            }
        }
        if(direction.y == 0) // if orthogonal...
        {
            for (int y = -1; y <= 1; y++) // draw 3 cell line (y direction)
            {
                targeted.push_front(target + GamePos(0,y));
            }
        }

        //reduce hp for target cells by 1
        for(auto iter = targeted.begin(); iter != targeted.end(); iter++)
        {
            auto cell = layer->getCell(iter->x, iter->y);
            cell.stats.hp--;
            layer->setCell(iter->x, iter->y, cell);
        }
    }
