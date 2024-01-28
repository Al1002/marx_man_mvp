#include "game_layer.h"

#include <iostream>
#include <stdexcept>

/**
 * @brief Construct a new `GameLayer` object, with `.id` set to 0
 *
 */
GameLayer::GameLayer()
{
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
		{
			layer[x][y] = getBlankCell();
		}
}

/**
 * @brief Returns if the cell with coordinates (`x`,`y`) exists
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool GameLayer::exists(int x, int y) const
{
	return !(x > 9 || x < 0 || y > 9 || y < 0);
}

/**
 * @brief Returns if the cell with coordinates `pos` exists
 *
 * @param pos
 * @return true
 * @return false
 */
bool GameLayer::exists(GamePos pos) const
{
	int x = pos.x;
	int y = pos.y;
	return !(x > 9 || x < 0 || y > 9 || y < 0);
}

/**
 * @brief Get the cell at coordinates (`x`,`y`)
 *
 * @param x
 * @param y
 * @return GameNode
 */
GameNode GameLayer::getCell(int x, int y) const
{
	if (!exists(x, y))
	{
		throw std::runtime_error("Out of bounds exception, attempting to GET a cell that does not exist!");
	}
	return layer[x][y];
}

/**
 * @brief Get the cell at coordinates `pos`
 *
 * @param pos
 * @return GameNode
 */
GameNode GameLayer::getCell(GamePos pos) const
{
	if (!exists(pos))
	{
		throw std::runtime_error("Out of bounds exception, attempting to GET a cell that does not exist!");
	}
	return layer[pos.x][pos.y];
}

/**
 * @brief Set the cell at coordinates (`x`,`y`) to `value`
 *
 * @param x
 * @param y
 * @param value
 */
void GameLayer::setCell(int x, int y, GameNode value)
{
	if (!exists(x, y))
	{
		throw std::runtime_error("Out of bounds exception, attempting to SET a cell that does not exist!");
	}
	layer[x][y] = value;
}

/**
 * @brief Set the cell at coordinates `pos` to `value`
 *
 * @param pos
 * @return GameNode
 */
void GameLayer::setCell(GamePos pos, GameNode value)
{
	if (!exists(pos))
	{
		throw std::runtime_error("Out of bounds exception, attempting to SET a cell that does not exist!");
	}
	layer[pos.x][pos.y] = value;
}

/**
 * @brief Get a default cell. May be used for clearing spaces.
 *
 */
GameNode GameLayer::getBlankCell()
{
	GameNode blank;
	blank.layer = this;
	blank.id = 0;
	blank.stats.hp = 0;
	blank.mele = NULL;
	blank.movement = NULL;
	return blank;
}

// UNCOMMENT FOR TESTING
/*
int main(int argc, char **argv)
{
	GameLayer jim;
	std::cout<<"Get cell, set id to 10, save it to the board:"<<std::endl;
	auto cell = jim.getCell(0,0);
	std::cout<<"Cell id: "<<cell.id<<std::endl;
	std::cout<<"Modifying cell..."<<std::endl;
	cell.id = 10;
	jim.setCell(0,0,cell);
	std::cout<<"Cell new id: "<<jim.getCell(0,0).id<<std::endl;
	std::cout<<"Attempting access at x7,y11..."<<std::endl;
	try{
		jim.getCell(7,11);
	}catch(const std::exception& e){
		std::cout<<e.what()<<std::endl;
	};

	return 0;
}*/
