#pragma once
#include "sprite.h"

class RedRectangle : public Sprite
{
    Visual::Point pos;
public:
    void draw(Visualizer *v) override;

    void setPos(Visual::Point pos);
};
