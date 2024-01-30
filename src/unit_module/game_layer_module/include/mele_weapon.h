#pragma once
#include "game_layer.h"
#include "game_pos.h"
#include <list>
#include <algorithm>
#include <stdexcept>

/**
 * @brief Class/interface for all mele-like objects. Mele weapons do not logically exist in the enviornment and as such take positional arguments.
 *
 */
class MeleWeapon
{
public:
    /**
     * @brief Automatically validates an attack using `.targetable()`. Dont overwrite unless nescesary.
     * 
     * @param layer 
     * @param origin 
     * @param target 
     */
    virtual void try_attack(GameLayer *layer, GamePos origin, GamePos target)
    {
        auto targetable = this->targetable(layer, origin);
        if (!layer->isValid(target))
        {
            throw std::runtime_error("Out of bounds exception, attempting to target a cell that does not exist in the given layer!");
        }

        if (find(targetable.begin(), targetable.end(), target) == targetable.end()) // if target not found in targetable, i.e. reached end
        {
            throw std::runtime_error("Invalid argument exception, attempting to target a cell that (BroadSword) cant target!");
        }
        attack(layer, origin, target);
    }

    /**
     * @brief Attack function. A function representing a mele or otherwise tile-based attack. Takes a ref to the active game layer.
     *
     * @param layer The game data layer (aka, place where the game state is stored)
     * @param origin The origin of the attack
     * @param target The tile to be attacked/targeted
     */
    virtual void attack(GameLayer *layer, GamePos origin, GamePos target) = 0;

    /**
     * @brief Returns list of tiles the weapon can target.
     *
     * @param layer
     * @param origin
     * @return std::list<GamePos>
     */
    virtual std::list<GamePos> targetable(GameLayer *layer, GamePos origin) = 0;
};