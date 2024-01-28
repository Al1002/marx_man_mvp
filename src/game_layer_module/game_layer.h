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
	bool exists(int x, int y) const;

	/**
	 * @brief Returns if the cell with coordinates `pos` exists
	 * 
	 * @param pos 
	 * @return true 
	 * @return false 
	 */
	bool exists(GamePos pos) const;

	/**
	 * @brief Get the cell at coordinates (`x`,`y`)
	 *
	 * @param x
	 * @param y
	 * @return GameNode
	 */
	GameNode getCell(int x, int y) const;

	/**
	 * @brief Get the cell at coordinates `pos`
	 *
	 * @param pos
	 * @return GameNode
	 */
	GameNode getCell(GamePos pos) const;

	/**
	 * @brief Set the cell at coordinates (`x`,`y`) to `value`
	 *
	 * @param x
	 * @param y
	 * @param value
	 */
	void setCell(int x, int y, GameNode value);

	/**
	 * @brief Set the cell at coordinates `pos` to `value`
	 *
	 * @param pos
	 * @return GameNode
	 */
	void setCell(GamePos pos, GameNode value);

	/**
	 * @brief Get a default cell. May be used for clearing spaces.
	 * 
	 */
	GameNode getBlankCell();
};

