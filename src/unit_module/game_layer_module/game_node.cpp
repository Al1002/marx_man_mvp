#include "game_node.h"

#include "game_layer.h"
#include "mele_weapon.h"
#include "unit_movement.h"
#include <stdexcept>

GameNode::GameNode()
{
    id = 0;
    layer = NULL;
    mele = NULL;
    movement = NULL;
    pos = GamePos(-1, -1);
    stats.hp = 0;
}

// Same as .getKey()
int GameNode::getId() const
{
    return id;
}

// Same as .getId()
int GameNode::getKey() const
{
    return id;
}

GamePos GameNode::getPos() const
{
    return pos;
}

void GameNode::useMele(GamePos target)
{
    if (mele == NULL)
    {
        throw std::runtime_error("Null pointer exception, attempting to use mele that does not exist!");
    }
    mele->try_attack(layer, pos, target);
}

void GameNode::useMove(GamePos target)
{
    if (movement == NULL)
    {
        throw std::runtime_error("Null pointer exception, attempting to use mele that does not exist!");
    }
    movement->try_move(layer, pos, target);
}