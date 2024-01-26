#include "game_layer.h"
#include "mele_weapon.h"

typedef GameLayer::GameNode GameNode; // just uncovers the name for this translation unit, doesnt work with methods :/
typedef GameLayer::GamePos GamePos;

void GameLayer::GameNode::useMele(GamePos target)
{
    mele->attack(layer, pos, target);
}