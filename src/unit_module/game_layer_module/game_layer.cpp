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
			layer[x][y] = NULL;
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
bool GameLayer::isValid(int x, int y) const
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
bool GameLayer::isValid(GamePos pos) const
{
	return isValid(pos.x, pos.y);
}

/**
 * @brief Returns if the node with coordinates (`x`,`y`) exists
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool GameLayer::exists(int x, int y) const
{
	return isValid(x,y) && layer[x][y] != NULL;
}

/**
 * @brief Returns if the node with coordinates `pos` exists
 *
 * @param pos
 * @return true
 * @return false
 */
bool GameLayer::exists(GamePos pos) const
{
	return exists(pos.x, pos.y);
}

/**
 * @brief Returns if the node associated with `key` exists
 *
 * @param key
 * @return true
 * @return false
 */
bool GameLayer::exists(int key) const
{
	return nodes.count(key);
}

/**
 * @brief Get the cell at coordinates (`x`,`y`)
 *
 * @param x
 * @param y
 * @return GameNode
 */
GameNode GameLayer::getNode(int x, int y) const
{
	if (!exists(x, y))
	{
		throw std::runtime_error("Out of bounds exception, attempting to GET a cell that does not exist!");
	}
	return *layer[x][y];
}

/**
 * @brief Get the cell at coordinates `pos`
 *
 * @param pos
 * @return GameNode
 */
GameNode GameLayer::getNode(GamePos pos) const
{
	return getNode(pos.x, pos.y);
}

/**
 * @brief Get the node identified by `key`
 *
 * @param key
 * @return GameNode
 */
GameNode GameLayer::getNode(int key) const
{
	if (!exists(key))
	{
		throw std::runtime_error("Invalid argument exception, attempting to GET a cell that does not exist!");
	}
	return *nodes.at(key);
}

/**
 * @brief Set the cell at coordinates (`x`,`y`) to `value`
 *
 * @param x
 * @param y
 * @param value
 */
void GameLayer::setNode(int x, int y, GameNode value)
{
	if (!isValid(x, y))
	{
		throw std::runtime_error("Out of bounds exception, attempting to SET a cell that does not exist!");
	}
	if (!exists(x,y)) // empty, move cell
	{
		value.pos = GamePos(x, y);
		auto old_value = getNode(value.getKey());
		layer[old_value.pos.x][old_value.pos.y] = NULL; 				// clearing the old cell in layer
		layer[value.pos.x][value.pos.y] = nodes[value.getKey()];	// and setting the new cell to point to the same place
		*nodes[value.getKey()] = value;
	}
	else
	if (layer[x][y]->id == value.id) // same place, just edit the value
	{
		value.pos = GamePos(x, y);
		*layer[x][y] = value;
	}
	else // writing over another node
	{
		throw std::runtime_error("Invalid argument exception, attempting to overwrite another node!");
	}
	
}

/**
 * @brief Set the cell at coordinates `pos` to `value`
 *
 * @param pos
 * @return GameNode
 */
void GameLayer::setNode(GamePos pos, GameNode value)
{
	setNode(pos.x, pos.y, value);
}

void GameLayer::setNode(int key, GameNode value)
{
	// this is special, as we may need to edit positions
	if (key != value.id)
	{
		throw std::runtime_error("Fuck you!");
	}
	if (!exists(key))
	{
		throw std::runtime_error("Invalid argumen exception, attempting to SET a cell that does not exist!");
	}
	if (layer[value.pos.x][value.pos.y]->id != value.id) // writing over another node
	{
		throw std::runtime_error("Invalid argument exception, attempting to overwrite another node!");
	}
	else // just edit the values, and update layer data
	{
		auto old_value = *nodes[key];
		layer[old_value.pos.x][old_value.pos.y] = NULL; // clearing the old cell in layer
		layer[value.pos.x][value.pos.y] = nodes[key];	// and setting the new cell to point to the same place
		*nodes[key] = value;
	}
}

/**
 * @brief Get a default cell. May be used for clearing spaces.
 *
 */
GameNode GameLayer::spawnNewNode(int x, int y)
{
	if (!isValid(x, y))
	{
		throw std::runtime_error("Invalid argument exception, attempting to overwrite another node!");
	}
	GameNode *node = new GameNode();
	node->id = ++id;
	node->layer = this;
	node->pos = GamePos(x, y);
	layer[x][y] = node;
	nodes[id] = node;
	return *node;
}

void GameLayer::deleteNode(int x, int y)
{
	if (!exists(x, y))
	{
		throw std::runtime_error("Trying to erase a node that doesnt exist!");
	}
	auto value = layer[x][y];
	nodes.erase(value->id);
	layer[x][y] = NULL;
	delete value;
}