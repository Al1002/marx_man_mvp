#include "unit.h"
#include "game_layer.h"

GameNode Unit::getNode()
{
    return layer->getNode(key);
}
void Unit::setNode(GameNode node)
{
    layer->setNode(key, node);
}

Unit::Unit(GameLayer *l, int x, int y)
{
    layer = l;
    key = layer->spawnNewNode(x, y).getKey();
}

GamePos Unit::getPos()
{
    return getNode().getPos();
}

void Unit::giveMele(MeleWeapon *mele)
{
    auto node = getNode();
    node.mele = mele;
    setNode(node);
}

void Unit::giveMove(UnitMovement *move)
{
    auto node = getNode();
    node.movement = move;
    setNode(node);
}

void Unit::useMele(GamePos pos)
{
    auto node = getNode();
    node.useMele(pos);
}

void Unit::useMove(GamePos pos)
{
    auto node = getNode();
    node.useMove(pos);
}
