#include "game_layer.h"

typedef GameLayer::GamePos GamePos; // just uncovers the name for this translation unit, doesnt work with methods :/

GamePos::GamePos()
{
    x = 0;
    y = 0;
}

GamePos::GamePos(int x, int y)
{
    this->x = x;
    this->y = y;
}

GamePos GameLayer::GamePos::operator-(GamePos const &other)
{
    return GamePos(this->x - other.x, this->y - other.y);
}

GamePos GameLayer::GamePos::operator+(GamePos const &other)
{
    return GamePos(this->x + other.x, this->y + other.y);
}

bool GameLayer::GamePos::operator==(GamePos const &other)
{
    return this->x == other.x && this->y == other.y;
}