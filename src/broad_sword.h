#include ".include/mele_weapon.h"


class BroadSword : public MeleWeapon{
    
    std::list<GamePos> targetable(GameLayer *layer, GamePos origin);

    void attack(GameLayer *layer, GamePos origin, GamePos target);
};