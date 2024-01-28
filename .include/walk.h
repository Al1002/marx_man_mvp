#include ".include/unit_movement.h"

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
                if (layer->exists(target))
                {
                    targets.push_front(target);
                }
            }
        }
        return targets;
    }

    void move(GameLayer *layer, GamePos origin, GamePos target)
    {
        auto targetable = this->reachable(layer, origin);
        if (!layer->exists(target))
        {
            throw new std::runtime_error("Out of bounds exception, attempting to reach a cell that does not exist in the given layer!");
        }

        if (find(targetable.begin(), targetable.end(), target) == targetable.end()) // if target not found in targetable, i.e. reached end
        {
            throw new std::runtime_error("Invalid argument exception, attempting to reach a cell that (walk) cant reach!");
        }

        layer->setCell(target, layer->getCell(origin));
        layer->setCell(origin, layer->getBlankCell());
    }
};