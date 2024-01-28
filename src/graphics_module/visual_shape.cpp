#include "visualizer.h"

VisualShape::VisualShape(Visual::Rect rect)
{
    this->rect = rect;
    this->type = Visual::RECT;
}

VisualShape::VisualShape(Visual::Line line)
{
    this->line = line;
    this->type = Visual::LINE;
}

VisualShape::VisualShape(Visual::Circle circle)
{
    this->circle = circle;
    this->type = Visual::CIRCLE;
}

void VisualShape::set_fullness(bool is_full)
{
    // This trick works because X and X_FILLED are exactly n and n+1, otherwise it wont work
    type = (Visual::ShapeType)(type + is_full);
    switch (type)
    {
    case Visual::RECT_FILLED:
    case Visual::CIRCLE_FILLED:
        break;
    default:
        type = (Visual::ShapeType)(type - is_full);
        break;
    }
}

VisualShape::~VisualShape()
{
    
}