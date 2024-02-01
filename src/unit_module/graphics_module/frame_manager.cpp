#include "frame_manager.h"

#include "sprite.h"
#include <list>
#include <stdexcept>

FrameManager::FrameManager(const char *window_name, int width, int height)
{
    window = new Visualizer(window_name, width, height);
}

FrameManager::~FrameManager()
{
    beginFrame(); // hack, but who cares
    endFrame();
}

/**
 * @brief Starts drawing on a new frame.
 *
 */
void FrameManager::beginFrame()
{
    if (making_frame)
    {
        throw std::runtime_error("Attemting to start a new frame before ending the previous one!");
    }
    making_frame = true;
    
}

void FrameManager::endFrame()
{
    if (!making_frame)
    {
        throw std::runtime_error("Attemting to end a frame that hasnt begun!");
    }
    making_frame = false;
    for (int i = 0; i < 10; i++)
    {
        for (auto iter = finished_frame[i].begin(); iter != finished_frame[i].end(); ++iter)
        {
            delete *iter;
        }
        finished_frame[i] = new_frame[i];
        new_frame[i].clear();
    }
}

/**
 * @brief This layer will persist throughout frames.
 *
 */
// void lockLayer(int depth);

/**
 * @brief Adds a sprite to the current frame. `depth` specifies how the sprite will be drawn.
 *
 * @param sprite Address to a sprite. Must have been allocated with `new`.
 * @param depth Sprites with lower depth will be drawn above sprites with higher depth. 0-9.
 */
void FrameManager::addSprite(Sprite *sprite, int depth)
{
    if (!making_frame)
    {
        throw std::runtime_error("Adding sprite while no frame is being made!");
    }
    new_frame[depth].push_front(sprite);
}

/**
 * @brief Draws the most recent frame. May reuse old frames if no new ones were provided.
 *
 */
void FrameManager::drawAll()
{
    for (int i = 0; i < 10; i++)
    {
        for (auto iter = finished_frame[i].begin(); iter != finished_frame[i].end(); ++iter)
        {
            (*iter)->draw(window);
        }
    }
    window->present();
}
