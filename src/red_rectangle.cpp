#include "red_rectangle.h"

void RedRectangle::draw(Visualizer *v)
{
    Visual::Rect rect = {pos.x, pos.y, 100, 100};
    v->set_draw_color(RGBA_RED);
    v->draw_rect_filled(rect);
}

void RedRectangle::setPos(Visual::Point pos)
{
    this->pos = pos;
}
