#include "game_layer.h"
#include <list>
#include <algorithm>
#include <stdexcept>

using std::list;
using std::find;

/**
 * @brief Class/interface for all mele-like objects. Mele weapons do not logically exist in the enviornment and as such take positional arguments. 
 * 
 */
class MeleWeapon{
    /**
     * @brief Attack function. A function representing a mele or otherwise tile-based attack. Takes a ref to the active game layer.
     * 
     * @param layer The game data layer (aka, place where the game state is stored)  
     * @param origin The origin of the attack
     * @param target The tile to be attacked/targeted
     */
    virtual void Attack(GameLayer *layer, GameLayer::GamePos origin, GameLayer::GamePos target) = 0;
    
    /**
     * @brief Returns a list of spaces the weapon can target.
     * 
     */
    //virtual void Targetable(GameLayer *layer, GameLayer::GamePos origin);
};


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
class BroadSword : MeleWeapon{
    
    list<GameLayer::GamePos> Targetable(GameLayer *layer, GameLayer::GamePos origin)
    {
        list<GameLayer::GamePos> targets;
        for(int x = -1; x <= 1; x++)
        {
            for(int y = -1; y <= 1; y++)
            {
                if(x == 0 && y == 0)
                    continue;
                GameLayer::GamePos target = GameLayer::GamePos(x,y);
                target = target + origin;
                if(layer->exists(target))
                {
                    targets.push_front(target);
                }
            }
        }
        return targets;
    }

    void Attack(GameLayer *layer, GameLayer::GamePos origin, GameLayer::GamePos target)
    {
        auto targetable = Targetable(layer, origin);
        if(!layer->exists(target))
        {
            throw new std::runtime_error("Out of bounds exception, attempting to target a cell that does not exist in the given layer!");
        }

        if(find(targetable.begin(), targetable.end(), target) != targetable.end()) // if target not found in targetable
        {
            throw new std::runtime_error("Invalid argument exception, attempting to target a cell that (BroadSword) cant target!");
        }
        
        list<GameLayer::GamePos> targeted;
        auto direction = target - origin;
        if(direction.x = 0) // if orthogonal...
        {
            for (int x = -1; x <= 1; x++) // draw 3 cell line (x direction)
            {
                targeted.push_front(target + GameLayer::GamePos(x,0));
            }
        }
        if(direction.y = 0) // if orthogonal...
        {
            for (int y = -1; y <= 1; y++) // draw 3 cell line (y direction)
            {
                targeted.push_front(target + GameLayer::GamePos(0,y));
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
};