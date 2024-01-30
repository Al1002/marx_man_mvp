#include "game_pos.h"

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

GamePos GamePos::operator-(GamePos const &other)
{
    return GamePos(this->x - other.x, this->y - other.y);
}

GamePos GamePos::operator+(GamePos const &other)
{
    return GamePos(this->x + other.x, this->y + other.y);
}

bool GamePos::operator==(GamePos const &other)
{
    return this->x == other.x && this->y == other.y;
}