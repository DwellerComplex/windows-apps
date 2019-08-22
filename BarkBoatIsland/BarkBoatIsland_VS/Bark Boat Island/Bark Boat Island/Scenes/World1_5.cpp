#include "World1_1.h"
#include "World1_5.h"
#include "mainmenu.h"
#include "../rectanglebuffers.h"
#include "../ecs.h"
#include "../globalenums.h"

World1_5::World1_5()
{
}

World1_5::~World1_5()
{
}

void World1_5::Start()
{
	std::vector<std::vector<char>> mapChars = {{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), },
	{ char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219), }
};

	std::vector<std::vector<short>> mapColors = {
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0xAA,0xAA,0xAA,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,},
	{0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xAA,0xAA,} 
	};



	std::vector<std::vector<short>> mapCollisions = {
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{3,0,0,0,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,3,3,3,3,3,0,0,0,},
	{3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,} 
	};

	Application::TransformVector2D(mapChars);
	Application::TransformVector2D(mapColors);
	Application::TransformVector2D(mapCollisions);
	backgroundCanvas = Canvas(0, 0, 1, mapChars, mapColors, mapCollisions);
	mainCanvas = Canvas();
	mainCanvas.Copy(&backgroundCanvas);
	mainCanvas.SetBuffersToZero();

	SpriteComponent* playerSpawnpointSprite = ECS::Add<SpriteComponent>(PLAYER_SPAWNPOINT);
	playerSpawnpointSprite->sprite = { { '#' } };
	playerSpawnpointSprite->color = { {0x09} };
	playerSpawnpointSprite->drawLayer = DrawLayers::ONE;
	PositionComponent* playerSpawnpointPosition = ECS::Add<PositionComponent>(PLAYER_SPAWNPOINT);
	ECS::Add<ConsoleOutputComponent>(PLAYER_SPAWNPOINT)->output = { "You respawned at spawnpoint." };
	playerSpawnpointPosition->posX = ECS::Get<PositionComponent>(PLAYER)->posX;
	playerSpawnpointPosition->posY = ECS::Get<PositionComponent>(PLAYER)->posY;

	update = true;
	playerSpawnTime = Application::GetGlobalTimer();

}

void World1_5::Update()
{
	update = continueUpdate;

	Collision(&mainCanvas);
	ReadInput();
	PlayerInputMovement();
	PlayerInputEscape();
	PlayerInteract();
	PlayerRespawn();
	Movement(&mainCanvas);
	ExecuteOrder66();

	DrawEntities(&mainCanvas);
	DrawConsole();
	DrawPlayerStats();
	DrawCanvas(&mainCanvas);
	DrawCanvasOnCanvas(&mainCanvas, &backgroundCanvas);

	if (ECS::Get<PositionComponent>(PLAYER)->posX == 32)
	{
		nextScene = WORLD1_1;
		update = false;
	}
}

void World1_5::End()
{

	killQueue.push_back(PLAYER_SPAWNPOINT);
	ExecuteOrder66();

	backgroundCanvas.Erase();
	mainCanvas.Erase();

	if (nextScene == WORLD1_1)
	{
		ECS::Get<PositionComponent>(PLAYER)->posX = 0;
		SceneManager::RegisterScene(new World1_1());
	}
	if (nextScene == MAINMENU)
	{
		ECS::Get<PositionComponent>(PLAYER)->posX = 1;
		ECS::Get<PositionComponent>(PLAYER)->posY = 1;
		SceneManager::RegisterScene(new Mainmenu());
	}
	else if (nextScene == QUIT)
	{
		SceneManager::RegisterScene(nullptr);
	}
}
