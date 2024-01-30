#include <iostream>

#include "red_rectangle.h"
#include "broad_sword.h"
#include "walk.h"
#include <unistd.h>

void print_layer(GameLayer layer);


// writes a cell value and catches an error
bool game_layer_test_a()
{
	GameLayer l;
	l.spawnNewNode(0,0);
	// wrap with class Unit so we can avoid most of the get-set bullshit
	auto node = l.getNode(0,0);
	node.mele = new BroadSword;
	node.movement = new Walk;
	l.setNode(node.getKey(), node);
	print_layer(l);
	for(int i = 0; i < 3; i++)
	{
		l.getNode(node.getKey()).useMove(l.getNode(node.getKey()).getPos() + GamePos(1,1));
		print_layer(l);
	}
	node = l.getNode(node.getKey());
	l.spawnNewNode(4,2);
	l.spawnNewNode(4,3);
	l.spawnNewNode(4,4);
	node.useMele(node.getPos() + GamePos(1,0));
	print_layer(l);
	return true;
}

void print_layer(GameLayer layer)
{
	for(int j = 0; j < 10; j++)
	{
		for(int i = 0; i < 10; i++)
		{
			if(!layer.exists(i, j))
			{
				std::cout<<"#";
			}
			else
			{
				std::cout<<layer.getNode(i, j).stats.hp;
			}
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

// uses a weapon
bool game_layer_test_b()
{
	return true;
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
	while(1);
	SDL_Quit();
}

// creates a node, gives it some objects that implement interfaces, then runs them
void module_composit_test()
{
	
}

int main(int argc, char **argv)
{
	game_layer_test_a();
	return 0;
}
