#include "unit_movement.h"

#include <list>
#include <algorithm>
#include <stdexcept>

using std::find;
using std::list;

class Walk : public UnitMovement
{
    std::list<GamePos> reachable(GameLayer *layer, GamePos origin)
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
                if (layer->isValid(target) && !layer->exists(target))
                {
                    targets.push_front(target);
                }
            }
        }
        return targets;
    }

    void move(GameLayer *layer, GamePos origin, GamePos target)
    {
        layer->setNode(target, layer->getNode(origin));
    }
};
