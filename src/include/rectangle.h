#pragma once
#include "sprite.h"

class SpriteRectangle : public Sprite
{
    Visual::Point pos;
    Visual::Color color;
    int width;
    int height;
public:
    SpriteRectangle(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    void draw(Visualizer *v) override;

    void setPos(Visual::Point pos);
};
