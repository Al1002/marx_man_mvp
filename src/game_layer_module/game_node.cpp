#include "game_node.h"

#include "game_layer.h"
#include "mele_weapon.h"
#include "unit_movement.h"
#include <stdexcept>


void GameNode::useMele(GamePos target)
{
    if(mele == NULL)
    {
        throw std::runtime_error("Null pointer exception, attempting to use mele that does not exist!");
    }
    mele->attack(layer, pos, target);
}

void GameNode::move(GamePos target)
{
    if(movement == NULL)
    {
        throw std::runtime_error("Null pointer exception, attempting to use mele that does not exist!");
    }
    movement->move(layer, pos, target);
}