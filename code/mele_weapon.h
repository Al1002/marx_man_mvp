#pragma once
#include "game_layer.h"

/**
 * @brief Class/interface for all mele-like objects. Mele weapons do not logically exist in the enviornment and as such take positional arguments. 
 * 
 */
class MeleWeapon{
public:
    /**
     * @brief Attack function. A function representing a mele or otherwise tile-based attack. Takes a ref to the active game layer.
     * 
     * @param layer The game data layer (aka, place where the game state is stored)  
     * @param origin The origin of the attack
     * @param target The tile to be attacked/targeted
     */
    virtual void attack(GameLayer *layer, GameLayer::GamePos origin, GameLayer::GamePos target) = 0;
    
    /**
     * @brief Returns a list of spaces the weapon can target.
     * 
     */
    //virtual void Targetable(GameLayer *layer, GameLayer::GamePos origin);
};