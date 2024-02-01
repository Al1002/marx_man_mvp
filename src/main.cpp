#include <iostream>

#include "unit.h"
#include "frame_manager.h"
#include "red_rectangle.h"
#include "broad_sword.h"
#include "walk.h"
#include <unistd.h>


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

// does the same as game_layer test a, but with unit
bool unit_module_test_a()
{
	GameLayer l;
	Unit myUnit(&l, 0, 0);
	myUnit.giveMele(new BroadSword);
	myUnit.giveMove(new Walk);
	print_layer(l);
	for(int i = 0; i < 3; i++)
	{
		print_layer(l);
		myUnit.useMove(myUnit.getPos() + GamePos(1,1));
	}
	myUnit.useMele(myUnit.getPos() + GamePos(0,1));
	l.spawnNewNode(4,2);
	l.spawnNewNode(4,3);
	l.spawnNewNode(4,4);
	print_layer(l);
	return true;
}

// draws on the screen with visualizer
void graphic_module_test_a()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Visualizer v("Hello world!", 1024, 720);
	Visual::Rect rect = {100,100,100,100};
	VisualShape shape = VisualShape(rect);
	shape.set_fullness(true);
	shape.color = (Visual::Color){RGBA_CYAN};
	v.set_draw_color(RGBA_WHITE);
	v.flush();
	v.draw_shape(shape);
	v.present();
	usleep(1000000);
	SDL_Quit();
}

// draws with sprite manager
void graphic_module_test_b()
{
	FrameManager jeph("This is a game window", 1024, 720);
	jeph.beginFrame();
	RedRectangle *red = new RedRectangle;
	red->setPos((Visual::Point){100,100});
	jeph.addSprite(red, 0);
	jeph.endFrame();
	jeph.drawAll();
	usleep(1000000);
}

// creates a node, gives it some objects that implement interfaces, then runs them
void module_composit_test()
{
	
}

int main(int argc, char **argv)
{
	graphic_module_test_a();
	graphic_module_test_b();
	return 0;
}
