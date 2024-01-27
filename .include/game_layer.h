#pragma once
#include "game_node.h"
#include "game_pos.h"

class GameLayer
{
public:

	GameNode layer[10][10];

	/**
	 * @brief Construct a new `GameLayer` object, with `.id` set to 0
	 *
	 */
	GameLayer();

	/**
	 * @brief Returns if the cell with coordinates (`x`,`y`) exists
	 *
	 * @param x
	 * @param y
	 * @return true
	 * @return false
	 */
	bool exists(int x, int y);

	/**
	 * @brief Returns if the cell with coordinates `pos` exists
	 * 
	 * @param pos 
	 * @return true 
	 * @return false 
	 */
	bool exists(GamePos pos);

	/**
	 * @brief Get the cell at coordinates (`x`,`y`)
	 *
	 * @param x
	 * @param y
	 * @return GameNode
	 */
	GameNode getCell(int x, int y);

	/**
	 * @brief Set the cell at coordinates (`x`,`y`) to `value`
	 *
	 * @param x
	 * @param y
	 * @param value
	 */
	void setCell(int x, int y, GameNode value);
};

