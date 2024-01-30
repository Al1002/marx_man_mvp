#pragma once
#include "visualizer.h"

class Sprite
{
public:
    virtual void draw(Visualizer *v, Visual::Point p) = 0;
};
