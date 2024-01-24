#include <iostream>
#include <stdexcept>
#include "game_layer.h"

typedef GameLayer::GameNode GameNode; // just uncovers the name for this translation unit, doesnt work with methods :/

GameLayer::GameLayer()
{
	for(int x = 0; x < 10; x++)
		for(int y = 0; y < 10; y++)
			{
				layer[x][y].id = 0;
			}
}

bool GameLayer::exists(int x, int y)
{
	return !(x > 9 || x < 0 || y > 9 || y < 0);
}

GameNode GameLayer::getCell(int x, int y)
{
	if(!exists(x,y))
	{
		throw std::runtime_error("Out of bounds exception, attempting to GET a cell that does not exist!");
	}
	return layer[x][y];
}

void GameLayer::setCell(int x, int y, GameNode value)
{
	if(!exists(x,y))
	{
		throw std::runtime_error("Out of bounds exception, attempting to SET a cell that does not exist!");
	}
	layer[x][y] = value;
}

/* ::Some fluf, coppy to a note or smt, delete if forgot
Visualizer -> (rule master) -> screen
Controler -> (input method)+(rule master)
AI -> software input
Input -> hardware input
RuleMaster -> move, fire, turn order
PhyLayer -> support certain actions (shoot)
GameLayer -> add, remove, edit
*/

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
