#include "unit_movement.h"

#include "game_layer.h"
#include "game_pos.h"
#include <list>
#include <stdexcept>
#include <algorithm>

/**
 * @brief  Class/interface for all movement-like objects. These are objects that represent a unit's ability to move.
 *         Movement is performed in 'steps'.
 */
class UnitMovement;

/**
 * @brief Automatically validates an attack using `.reachable()`. Dont overwrite unless nescesary.
 *
 * @param layer
 * @param origin
 * @param target
 */
void UnitMovement::try_move(GameLayer *layer, GamePos origin, GamePos target)
{
    auto reachable = this->reachable(layer, origin);
    if (!layer->isValid(target))
    {
        throw std::runtime_error("Out of bounds exception, attempting to reach a cell that does not exist in the given layer!");
    }
    if (find(reachable.begin(), reachable.end(), target) == reachable.end()) // if target not found in reachable, i.e. reached end
    {
        throw std::runtime_error("Invalid argument exception, attempting to reach a cell that (walk) cant reach!");
    }
    move(layer, origin, target);
}
