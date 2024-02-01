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

    int id;
    GamePos pos;
    GameLayer *layer;
    GameNode();
public:
    Stats stats;
    MeleWeapon *mele;
    UnitMovement *movement;
    int getId() const;
    int getKey() const;
    GamePos getPos() const;
    void useMele(GamePos target);
    void useMove(GamePos target);
    friend class GameLayer;
};