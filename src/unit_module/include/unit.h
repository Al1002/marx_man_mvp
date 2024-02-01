#pragma once
#include "game_layer.h"

class Unit
{
    GameLayer *layer;
    int key;

    GameNode getNode();
    void setNode(GameNode node);
public:
    Unit(GameLayer *l, int x, int y);

    GamePos getPos();
    
    void giveMele(MeleWeapon *mele);

    void giveMove(UnitMovement *move);
    
    void useMele(GamePos pos);
    
    void useMove(GamePos pos);
};