#pragma once
#include "game_layer.h"
#include "game_pos.h"
#include <list>

/**
 * @brief  Class/interface for all movement-like objects. These are objects that represent a unit's ability to move.
 *         Movement is performed in 'steps'.
 */
class UnitMovement
{
public:
    virtual void move(GameLayer *layer, GamePos origin, GamePos target) = 0;

    virtual std::list<GamePos> reachable(GameLayer *layer, GamePos origin) = 0;
};