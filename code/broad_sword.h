#include "mele_weapon.h"
#include <list>

class BroadSword : MeleWeapon{
    
    std::list<GameLayer::GamePos> targetable(GameLayer *layer, GameLayer::GamePos origin);

    void attack(GameLayer *layer, GameLayer::GamePos origin, GameLayer::GamePos target);
};