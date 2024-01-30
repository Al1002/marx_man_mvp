#include "broad_sword.h"

#include <list>
#include <algorithm>
#include <stdexcept>

using std::find;
using std::list;

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
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (x == 0 && y == 0)
                continue;
            GamePos target = GamePos(x, y);
            target = target + origin;
            if (layer->isValid(target))
            {
                targets.push_front(target);
            }
        }
    }
    return targets;
}

void BroadSword::attack(GameLayer *layer, GamePos origin, GamePos target)
{


    list<GamePos> targeted;
    auto direction = target - origin;
    if (direction.x == 0) // if orthogonal...
    {
        for (int x = -1; x <= 1; x++) // draw 3 cell line (x direction)
        {
            targeted.push_front(target + GamePos(x, 0));
        }
    }
    if (direction.y == 0) // if orthogonal...
    {
        for (int y = -1; y <= 1; y++) // draw 3 cell line (y direction)
        {
            targeted.push_front(target + GamePos(0, y));
        }
    }

    // reduce hp for target cells by 1
    for (auto iter = targeted.begin(); iter != targeted.end(); ++iter)
    {
        if(!layer->exists(iter->x, iter->y))
            continue;
        auto cell = layer->getNode(iter->x, iter->y);
        cell.stats.hp--;
        layer->setNode(iter->x, iter->y, cell);
    }
}
