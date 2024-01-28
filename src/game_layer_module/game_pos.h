#pragma once

/**
 * @brief Class representing a position somewhere on the board, with fields `x` and `y`
 *
 */
class GamePos
{
public:
    int x;
    int y;

    GamePos();

    GamePos(int x, int y);

    GamePos operator-(GamePos const &other);

    GamePos operator+(GamePos const &other);

    bool operator==(GamePos const &other);
};