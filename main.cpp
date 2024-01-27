#include <iostream>
#include ".include/game_layer.h"
#include ".include/broad_sword.h"
#include ".include/visualizer.h"

// writes a cell value and catches an error
void game_layer_test_a()
{
	GameLayer jim;
	std::cout<<"Get cell, set id to 10, save it to the board:"<<std::endl;
	auto cell = jim.getCell(0,0);
	std::cout<<"Cell id: "<<cell.id<<std::endl;
	std::cout<<"Modifying cell..."<<std::endl;
	cell.id = 1;
	jim.setCell(0,0,cell);
	std::cout<<"Cell new id: "<<jim.getCell(0,0).id<<std::endl;
	std::cout<<"Attempting access at x7,y11..."<<std::endl;
	try{
		jim.getCell(7,11);
	}catch(const std::exception& e){
		std::cout<<e.what()<<std::endl;
	};
}

void print_layer(GameLayer layer)
{
	auto blank = layer.getBlankCell();
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			auto cell = layer.getCell(i, j);
			if(cell.id == blank.id)
			{
				std::cout<<"#";
			}
			else
			{
				std::cout<<cell.id;
			}
		}
		std::cout<<std::endl;
	}
}

// uses a weapon
void game_layer_test_b()
{
	std::cout<<"Setting up game layer, giving cell 5,5 a broadsword, swinging right, then seeing what happens:"<<std::endl;
	GameLayer layer;
	print_layer(layer);
	auto cell = layer.getBlankCell();
	cell.stats.hp = 0;
	layer.setCell(4,4, cell);
	layer.setCell(4,5, cell);
	layer.setCell(4,6, cell);
	cell.mele = (MeleWeapon*) new BroadSword();
	cell.pos = GamePos(5,5);
	cell.layer = &layer;
	layer.setCell(5,5,cell);
	layer.layer[5][5].useMele(GamePos(4,5));
	std::cout<<std::endl;
	print_layer(layer);
	std::cout<<"Cell hp are:"<<std::endl;
	std::cout<<"4,4: "<<layer.getCell(4,4).stats.hp<<std::endl;
	std::cout<<"4,5: "<<layer.getCell(4,5).stats.hp<<std::endl;
	std::cout<<"4,6: "<<layer.getCell(4,6).stats.hp<<std::endl;
}

// draws on the screen
void graphic_module_test()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Visualizer v;
	Visual::Rect rect = {100,100,100,100};
	VisualShape shape = VisualShape(rect);
	shape.set_fullness(true);
	shape.color = (Visual::Color){RGBA_CYAN};
	v.set_draw_color(RGBA_WHITE);
	v.flush();
	v.draw_shape(shape);
	v.present();
	int stall;
	std::cin>>stall;
	SDL_Quit();
}

int main(int argc, char **argv)
{
	graphic_module_test();
	return 0;
}
