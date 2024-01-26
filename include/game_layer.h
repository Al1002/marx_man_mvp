#pragma once

class MeleWeapon;

class GameLayer
{
public:
	/**
	 * @brief A class representing the stats of our entitie(s)
	 * 
	 */
	class Stats
	{
	public:
		int hp;
	};

	/**
	 * @brief Class representing a position somewhere on the board, with fields `x` and `y`
	 * 
	 */
	class GamePos
	{
	public:
		int x;
		int y;

		GamePos();

		GamePos(int x, int y);

		GamePos operator-(GamePos const &other);

		GamePos operator+(GamePos const &other);

		bool operator==(GamePos const &other);
	};

	class GameNode
	{
	public:
		int id;
		GameLayer *layer;
		GamePos pos;
		Stats stats;
		MeleWeapon *mele;
		void setLayer(GameLayer *layer);
		void useMele(GamePos target);
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

