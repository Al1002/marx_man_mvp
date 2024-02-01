#include "rectangle.h"

SpriteRectangle::SpriteRectangle(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    pos = (Visual::Point){x, y};
    color = (Visual::Color){r,g,b,a};
    width = w;
    height = h;
}

void SpriteRectangle::draw(Visualizer *v)
{
    Visual::Rect rect = {pos.x, pos.y, width, height};
    v->set_draw_color(color.r,color.g,color.b,color.a);
    v->draw_rect_filled(rect);
}

void SpriteRectangle::setPos(Visual::Point pos)
{
    this->pos = pos;
}
