#pragma once
#include <SDL2/SDL.h>
#include <list>

#define RGBA_RED (Uint8)255, (Uint8)0, (Uint8)0, (Uint8)255
#define RGBA_GREEN (Uint8)0, (Uint8)255, (Uint8)0, (Uint8)255
#define RGBA_BLUE (Uint8)0, (Uint8)0, (Uint8)255, (Uint8)255
#define RGBA_CYAN (Uint8)0, (Uint8)127, (Uint8)127, (Uint8)255
#define RGBA_YELLOW (Uint8)127, (Uint8)127, (Uint8)0, (Uint8)255
#define RGBA_MAGENTA (Uint8)0, (Uint8)127, (Uint8)127, (Uint8)255
#define RGBA_WHITE (Uint8)255, (Uint8)255, (Uint8)255, (Uint8)255
#define RGBA_BLACK (Uint8)0, (Uint8)0, (Uint8)0, (Uint8)255

namespace Visual
{
    // WARNING: X and X_FILLED MUST AWAYS BE n-th and n+1-th, otherwise set_fullness() bricks :)
    enum ShapeType{LINE, RECT, RECT_FILLED, CIRCLE, CIRCLE_FILLED};
    
    /**
     * @brief A point on the screen.
     * 
     */
    typedef SDL_Point Point;
    
    /**
     * @brief A line on the screen.
     * 
     */
    typedef struct{
        Point a, b;
    }Line;
    
    /**
     * @brief A rectangle on the screen.
     * 
     */
    typedef SDL_Rect Rect;
    typedef struct{
        union
        {
            SDL_Color sdl_color;
            struct{
                Uint8 r, g, b, a;
            };
        };
    }Color;
    
    /**
     * @brief A circle on the screen.
     * 
     */
    typedef struct{
	    int radius;
        union{
	        Point center;
            struct{
                int x;
                int y;
            };
        };
    }Circle;
}

/**
 * @brief An abstarct class (union) of shapes on the screen.
 * 
 */
class VisualShape{
public:
    union{
        Visual::Line line;
        Visual::Rect rect;
        Visual::Circle circle;
    };
    Visual::ShapeType type;
    Visual::Color color;
    VisualShape(Visual::Rect rect);
    VisualShape(Visual::Line line);
    VisualShape(Visual::Circle circle);
    void set_fullness(bool is_full);
    ~VisualShape();
};

// Dont pass referencess unless nescesary, the user can dereference themselves
class Visualizer{
private:
    int win_width, win_height;
    SDL_Window *window;
    
public:
    SDL_Renderer *render;
    Visualizer(const char *window_name, int width, int height);
    void present();
    void set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void set_draw_color(Visual::Color color);
    void flush(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void flush();
    void draw_line(Visual::Line line);
    void draw_rect(Visual::Rect rect);
    void draw_rect_filled(Visual::Rect rect);
    void draw_circle(Visual::Circle circle);
    void draw_circle_filled(Visual::Circle circle);
    void draw_shape(VisualShape shape);
    void draw_list(std::list<VisualShape> shapes);
    ~Visualizer();
};