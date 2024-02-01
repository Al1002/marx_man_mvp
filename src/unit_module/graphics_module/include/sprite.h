#pragma once
#include "visualizer.h"

class Sprite
{
public:
    virtual void draw(Visualizer *v) = 0;
};
