#include ".include/sprite.h"

class RedRectangle : public Sprite
{
public:
    void draw(Visualizer *v, Visual::Point p)
    {
        Visual::Rect rect = {p.x, p.y, 100, 100};
        v->set_draw_color(RGBA_RED);
        v->draw_rect_filled(rect);
    }
};