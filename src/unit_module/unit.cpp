#include "game_layer.h"

class Unit
{
    GameLayer *layer;
    int key;

    GameNode getNode()
    {
        return layer->getNode(key);
    }
    void setNode(GameNode node)
    {
        layer->setNode(key, node);
    }
public:
    Unit(GameLayer *l, int x, int y)
    {
        layer = l;
        key = layer->spawnNewNode(x, y).getKey();
    }

    GamePos getPos()
    {
        return getNode().getPos();
    }
    
    void giveMele(MeleWeapon *mele)
    {
        auto node = getNode();
        node.mele = mele;
        setNode(node);
    }

    void giveMove(UnitMovement *move)
    {
        auto node = getNode();
        node.movement = move;
        setNode(node);
    }
    
    void useMele(GamePos pos)
    {
        auto node = getNode();
        node.useMele(pos);
    }
    
    void useMove(GamePos pos)
    {
        auto node = getNode();
        node.useMove(pos);
    }
};