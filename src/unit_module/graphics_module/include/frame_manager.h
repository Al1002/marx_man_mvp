#pragma once
#include "sprite.h"

class FrameManager{
    std::list<Sprite*> finished_frame[10];
    std::list<Sprite*> new_frame[10];
    Visualizer *window;
    bool locked[10];
    bool making_frame = false;
public:
    FrameManager(const char *window_name, int width, int height);
    ~FrameManager();
    /**
     * @brief Starts drawing on a new frame.
     * 
     */
    void beginFrame();
    
    void endFrame();

    /**
     * @brief This layer will persist throughout frames.
     * 
     */
    //void lockLayer(int depth);

    /**
     * @brief Adds a sprite to the current frame. `depth` specifies how the sprite will be drawn. 
     * 
     * @param sprite Address to a sprite. Must have been allocated with `new`.
     * @param depth Sprites with lower depth will be drawn above sprites with higher depth. 0-9.
     */
    void addSprite(Sprite *sprite, int depth);
    
    /**
     * @brief Draws the most recent frame. May reuse old frames if no new ones were provided.
     * 
     */
    void drawFrame();
};