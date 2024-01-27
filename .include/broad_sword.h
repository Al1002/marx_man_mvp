#include ".include/mele_weapon.h"
#include <list>

class BroadSword : MeleWeapon{
    
    std::list<GamePos> targetable(GameLayer *layer, GamePos origin);

    void attack(GameLayer *layer, GamePos origin, GamePos target);
};