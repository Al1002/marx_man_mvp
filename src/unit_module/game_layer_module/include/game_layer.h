#pragma once
#include "game_node.h"
#include "game_pos.h"
#include <map>

class GameLayer
{
	std::map<int, GameNode*> nodes;

	int id = 0;

	GameNode* layer[10][10];

public:

	/**
	 * @brief Returns if the coordinates (`x`,`y`) are a valid position on the board
	 *
	 * @param x
	 * @param y
	 * @return true
	 * @return false
	 */
	bool isValid(int x, int y) const;

	/**
	 * @brief Returns if the coordinates `pos` are a valid position on the board
	 * 
	 * @param pos 
	 * @return true 
	 * @return false 
	 */
	bool isValid(GamePos pos) const;

	/**
	 * @brief Construct a new `GameLayer` object
	 *
	 */
	GameLayer();
	
	/**
	 * @brief Returns if the node with coordinates (`x`,`y`) exists
	 *
	 * @param x
	 * @param y
	 * @return true
	 * @return false
	 */
	bool exists(int x, int y) const;

	/**
	 * @brief Returns if the node with coordinates `pos` exists
	 * 
	 * @param pos 
	 * @return true 
	 * @return false 
	 */
	bool exists(GamePos pos) const;

	/**
	 * @brief Returns if the node associated with `key` exists
	 * 
	 * @param key 
	 * @return true 
	 * @return false 
	 */
	bool exists(int key) const;

	/**
	 * @brief Get the node at coordinates (`x`,`y`)
	 *
	 * @param x
	 * @param y
	 * @return GameNode
	 */
	GameNode getNode(int x, int y) const;

	/**
	 * @brief Get the node at coordinates `pos`
	 *
	 * @param pos
	 * @return GameNode
	 */
	GameNode getNode(GamePos pos) const;

	/**
	 * @brief Get the node identified by `key`
	 * 
	 * @param key 
	 * @return GameNode 
	 */
	GameNode getNode(int key) const;

	/**
	 * @brief Set the node at coordinates (`x`,`y`) to `value`
	 *
	 * @param x
	 * @param y
	 * @param value
	 */
	void setNode(int x, int y, GameNode value);

	/**
	 * @brief Set the node at coordinates `pos` to `value`
	 *
	 * @param pos
	 * @return GameNode
	 */
	void setNode(GamePos pos, GameNode value);

	/**
	 * @brief Set the node asociated with `key`
	 * 
	 * @param key 
	 */
	void setNode(int key, GameNode value);
	
	/**
	 * @brief Get a new `default` node with a unique key. Node must have a position on the board.  
	 * 
	 */
	GameNode spawnNewNode(int x, int y);
	// NOTE: create another "template" class that isnt GameNode, so it can exist outside of GameLayer, and add a spawnNewNode(pos, template);

	/**
	 * @brief Erase node from existance.
	 * 
	 * @param x 
	 * @param y 
	 */
	void deleteNode(int x, int y);
};

