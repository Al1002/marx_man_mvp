#pragma once
#include "game_pos.h"
class GameLayer;
class MeleWeapon;
class UnitMovement;

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
    UnitMovement *movement;
    void setLayer(GameLayer *layer);
    void useMele(GamePos target);
    void move(GamePos target);
};
#include "mele_weapon.h"