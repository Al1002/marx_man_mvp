#include <iostream>
#include "include/game_layer.h"
#include "include/mele_weapon.h"
#include "include/broad_sword.h"

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
	std::cout<<"Setting up game layer, giving cell 5,5 a broadsword, swinging right, then seeing what happens:"<<std::endl;
	GameLayer layer;
	cell.stats.hp = 0;
	layer.setCell(4,4, cell);
	layer.setCell(4,5, cell);
	layer.setCell(4,6, cell);
	cell.mele = (MeleWeapon*) new BroadSword();
	cell.pos = GameLayer::GamePos(5,5);
	cell.layer = &layer;
	layer.setCell(5,5,cell);
	layer.layer[5][5].useMele(GameLayer::GamePos(4,5));
	std::cout<<"Cell hp are:"<<std::endl;
	std::cout<<"4,4: "<<layer.getCell(4,4).stats.hp<<std::endl;
	std::cout<<"4,5: "<<layer.getCell(4,5).stats.hp<<std::endl;
	std::cout<<"4,6: "<<layer.getCell(4,6).stats.hp<<std::endl;
	
	return 0;
}
