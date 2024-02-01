#include "mele_weapon.h"
#include "game_layer.h"
#include "game_pos.h"
#include <list>
#include <algorithm>
#include <stdexcept>

/**
 * @brief Class/interface for all mele-like objects. Mele weapons do not logically exist in the enviornment and as such take positional arguments.
 *
 */
class MeleWeapon;

/**
 * @brief Automatically validates an attack using `.targetable()`. Dont overwrite unless nescesary.
 *
 * @param layer
 * @param origin
 * @param target
 */
void MeleWeapon::try_attack(GameLayer *layer, GamePos origin, GamePos target)
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