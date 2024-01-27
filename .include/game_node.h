#pragma once
#include "game_pos.h"
class GameLayer;
class MeleWeapon;

/**
 * @brief A class representing the stats of our entitie(s)
 *
 */
class Stats
{
public:
    int hp;
};

class GameNode
{
public:
    int id;
    GameLayer *layer;
    GamePos pos;
    Stats stats;
    MeleWeapon *mele;
    void setLayer(GameLayer *layer);
    void useMele(GamePos target);
};
#include "mele_weapon.h"