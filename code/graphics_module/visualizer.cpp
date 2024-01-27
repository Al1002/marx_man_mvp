#include "visualizer.h"
#include <SDL2/SDL.h>
#include <list>

/**
 * @brief Construct a new Visualizer:: Visualizer object
 * 
 */
Visualizer::Visualizer()
{
    this->window = SDL_CreateWindow("Hello world!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 720, SDL_WINDOW_SHOWN);
    this->render = SDL_CreateRenderer(window, -1, 0);
}

/**
 * @brief Centeres a rectangle inside another rectangle
 * 
 * @param frame Outer rectangle, sets position
 * @param inner Inner rectangle, keeps size
 * @return SDL_Rect 
 */
SDL_Rect center_rect(SDL_Rect frame, SDL_Rect inner)
{
    return (SDL_Rect){.x = frame.x + (frame.w - inner.w) / 2, .y = frame.y + (frame.h - inner.h) / 2, .w = inner.w, .h = inner.h};
}

/**
 * @brief Clears the screen with a solid color, defined by `r` `g` `b` `a`
 * 
 * @param r Red, from 0 to 255
 * @param g Green, from 0 to 255
 * @param b Blue, from 0 to 255
 * @param a Alpha transparency, ignored
 */
void Visualizer::flush(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    Uint8 rr, gg, bb, aa; 
    SDL_GetRenderDrawColor(render, &rr, &gg, &bb, &aa); // save colors
    SDL_SetRenderDrawColor(render, r, g, b, a);
    SDL_RenderClear(render);
    SDL_SetRenderDrawColor(render, rr, gg, bb, aa); // restore colors
}

/**
 * @brief Fills the screen with a solid color, as defined by `set_draw_color`
 * 
 */
void Visualizer::flush()
{
    SDL_RenderClear(render);
}

/**
 * @brief Sets draw color for future draw operations, unless overwritten
 * 
 * @param r Red, from 0 to 255
 * @param g Green, from 0 to 255
 * @param b Blue, from 0 to 255
 * @param a Alpha transparency, from 0 to 255
 */
void Visualizer::set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(render, r, g, b, a);
}

/**
 * @brief Draws a line on the screen buffer
 * 
 * @param line A line
 */
void Visualizer::draw_line(Visual::Line line)
{
    SDL_RenderDrawLine(render, line.a.x, line.a.y, line.b.x, line.b.y);
}

/**
 * @brief Draws a rectangle outline on the screen buffer
 * 
 * @param rect 
 */
void Visualizer::draw_rect(Visual::Rect rect)
{
    SDL_RenderDrawRect(render, &rect);
}

/**
 * @brief Draws a filled in rectangle on the screen buffer 
 * 
 * @param rect 
 */
void Visualizer::draw_rect_filled(Visual::Rect rect)
{
    SDL_RenderFillRect(render, &rect);
}

/**
 * @brief Draws a circle outline on the screen buffer
 * 
 * @param circle 
 */
void Visualizer::draw_circle(Visual::Circle circle)
{
    // Note: this code can be optimised, but it will become even more of a mess
    // Tl;dr its division trough add and sub, somewhat fast
    int low = 0;
	int high = circle.radius;
	int err = -(high * 2 - 1);
	int cnt = 0;
	SDL_Point *points = new SDL_Point [circle.radius * 2];
	for(;high > low; low++)
	{
			points[cnt + 0] = {circle.x + low, circle.y + high};    // Draws points 8 times per each eigth of the circle
			points[cnt + 1] = {circle.x + low, circle.y - high};
			points[cnt + 2] = {circle.x + high, circle.y + low};
			points[cnt + 3] = {circle.x + high, circle.y - low};
			points[cnt + 4] = {circle.x - low, circle.y + high};
			points[cnt + 5] = {circle.x - low, circle.y - high};
			points[cnt + 6] = {circle.x - high, circle.y + low};
			points[cnt + 7] = {circle.x - high, circle.y - low};
			cnt += 8;
		err += low * 2 + 1;
		if(err >= 0)
		{
			SDL_RenderDrawPoints(render, points, cnt);             // We agregate the draw calls in points, then periodically flush
			cnt = 0;
			err -= high * 2 - 1;
			high--;
		}
	}
	SDL_RenderDrawPoints(render, points, cnt);		
	delete points;
}

/**
 * @brief Draws a filled in circle on the screen buffer
 * 
 * @param circle 
 */
void Visualizer::draw_circle_filled(Visual::Circle circle)
{
    // Black magic, we fill a rect in the middle of the circle and only bother with the edges
	int sqrt2 = circle.radius * 0.7;
	SDL_Rect rect = {circle.x-sqrt2, circle.y-sqrt2, 2*sqrt2, 2*sqrt2};
	SDL_RenderFillRect(render, &rect);
	SDL_Point *points = new SDL_Point [circle.radius * 8];
	int cnt = 0;
	for(int high = sqrt2; high < circle.radius; high++)
	{
		for(int low = 0;; low++)
		{
			if (high * high + low * low >= circle.radius * circle.radius)
			{
				SDL_RenderDrawPoints(render, points, cnt);
				cnt = 0;
				break;
			}
			points[cnt + 0] = {circle.x + low, circle.y + high};
			points[cnt + 1] = {circle.x + low, circle.y - high};
			points[cnt + 2] = {circle.x + high, circle.y + low};
			points[cnt + 3] = {circle.x + high, circle.y - low};
			points[cnt + 4] = {circle.x - low, circle.y + high};
			points[cnt + 5] = {circle.x - low, circle.y - high};
			points[cnt + 6] = {circle.x - high, circle.y + low};
			points[cnt + 7] = {circle.x - high, circle.y - low};
			cnt += 8;
		}
	}
	SDL_RenderDrawPoints(render, points, cnt);		
	delete points;
}

/**
 * @brief Draws the shape contained within `shape` on the screen buffer.
 *      For filled in shapes, call `set_fullness()`
 * 
 * @param shape 
 */
void Visualizer::draw_shape(VisualShape shape)
{
    Uint8 rr, gg, bb, aa; 
    SDL_GetRenderDrawColor(render, &rr, &gg, &bb, &aa); // save colors
    SDL_SetRenderDrawColor(render, shape.color.r, shape.color.g, shape.color.b, shape.color.a);
    switch (shape.type)
    {
    case Visual::LINE:
        this->draw_line(shape.line);
        break;
    case Visual::RECT:
        this->draw_rect(shape.rect);
        break;
    case Visual::RECT_FILLED:
        this->draw_rect_filled(shape.rect);
        break;
    case Visual::CIRCLE:
        this->draw_circle(shape.circle);
        break;
    case Visual::CIRCLE_FILLED:
        this->draw_circle_filled(shape.circle);
        break;
    default:
        throw "Unrecognized shape"; //add error
        break;
    }
    SDL_SetRenderDrawColor(render, rr, gg, bb, aa); // restore colors
}

/**
 * @brief Draws the shapes listed in `shapes` on the screen buffer
 * 
 * @param shapes An `std::list` with shapes
 */
void Visualizer::draw_list(std::list<VisualShape> shapes)
{
    for (auto iter = shapes.begin(); iter != shapes.end(); ++iter) // .end() is one past the last element, aka dont do{}while; 
    {
        draw_shape(*iter);
    }
}

/**
 * @brief Presents the screen buffer to the screen and clears it
 * 
 */
void Visualizer::present()
{
    SDL_RenderPresent(render);
}

/*
void Visualizer::draw_cells(int **arr, int arr_x, int arr_y, SDL_Rect outer, SDL_Rect inner)
{
    SDL_Rect index_o = outer, index_i = inner;
    for(int y = 0; y < arr_y; y++)
    {
        index_o.y = outer.w * y;
        for(int x = 0; x < arr_x; x++)
        {
            index_o.x = outer.w * x;
            SDL_SetRenderDrawColor(render, 255,0,0, 255);
            SDL_RenderDrawRect(this->render, &index_o);
            index_i = center_rect(index_o, index_i);
            SDL_SetRenderDrawColor(render, 0,255,0, 255);
            SDL_RenderFillRect(this->render, &index_i);
        }
    }
}
*/

/**
 * @brief N/A
 * 
 */
Visualizer::~Visualizer()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}