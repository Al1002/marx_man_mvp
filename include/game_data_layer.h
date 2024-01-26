#pragma once

class GameLayer
{
public:
	/**
	 * @brief A class representing the stats of our entitie(s)
	 * 
	 */
	class Stats
	{
		int hp;
	};

	/**
	 * @brief A class representation of our entitie(s)
	 * 
	 */
	class GameNode
	{
	public:
		Stats stats;
		int id;
	};

	class GamePos
	{
		int x;
		int y;
	};

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

