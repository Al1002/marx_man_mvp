#include "game_node.h"
#include "game_layer.h"
#include "mele_weapon.h"
void GameNode::useMele(GamePos target)
{
    mele->attack(layer, pos, target);
}