#include "World1_1.h"
#include "World1_2.h"
#include "World1_3.h"
#include "mainmenu.h"
#include "../canvas.h"
#include "../rectanglebuffers.h"
#include "../ecs.h"
#include "../globalenums.h"

World1_1::World1_1()
{
}

void World1_1::Start()
{
	std::vector<std::vector<char>> mapChars = {
{char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(93),char(32),char(32),char(32),char(91),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236)},
{char(32),char(32),char(32),char(32),char(79),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(79),char(79),char(39),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(79),char(79),char(79),char(79),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(79),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(39),char(39),char(79),char(39),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(39),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(39),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(236),char(236),char(32),char(32),char(236),char(236),char(32),char(32),char(32),char(32),char(32),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(236),char(236),char(236),char(236),char(236),char(236),char(32),char(32),char(32),char(32),char(32),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(79),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(39),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(79),char(79),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(39),char(39),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236)},
{char(236),char(32),char(32),char(79),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(39),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(236)},
{char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236)} 
};

	std::vector<std::vector<short>> mapColors = {
	{0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E},
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0,0,0,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E },
	{ 0,0,0,0,0x02,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0x02,0x02,0x06,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0x02,0x02,0x02,0x02,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x02,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0x06,0x06,0x02,0x06,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x06,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0x06,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0x0E,0x0E,0,0,0x0E,0x0E,0,0,0,0,0,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0,0,0,0 },
	{ 0,0,0x0E,0,0,0,0,0x0E,0,0,0,0,0,0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E,0,0,0,0 },
	{ 0,0,0x0E,0,0,0,0,0x0E,0,0,0,0,0,0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E,0,0,0,0 },
	{ 0,0,0x0E,0,0,0,0,0x0E,0,0,0,0,0,0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E,0,0,0,0 },
	{ 0,0,0x0E,0,0,0,0,0x0E,0,0,0,0,0,0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E,0,0,0,0 },
	{ 0,0,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0,0,0,0,0,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0,0,0,0 },
	{ 0,0,0,0x02,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0x06,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x02,0x02,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x06,0x06,0,0,0,0,0,0,0,0,0,0 },
	{ 0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0E },
	{ 0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E }
};

	std::vector<std::vector<short>> mapCollisions = {
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,3,3,3,3,3,3,3,3,3,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0},
{0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0},
{0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,3,3,0,0,3,3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0},
{0,0,3,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0},
{0,0,3,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0},
{0,0,3,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0},
{0,0,3,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0},
{0,0,3,3,3,3,3,3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0},
{0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
};

	Application::TransformVector2D(mapChars);
	Application::TransformVector2D(mapColors);
	Application::TransformVector2D(mapCollisions);
	backgroundCanvas = new Canvas(0, 0, 1, mapChars, mapColors, mapCollisions);
	mainCanvas = new Canvas();
	mainCanvas->Copy(backgroundCanvas);
	mainCanvas->SetBuffersToZero();

	SpriteComponent* playerSpawnpointSprite = ECS::Add<SpriteComponent>(PLAYER_SPAWNPOINT);
	playerSpawnpointSprite->sprite = { { '#' } };
	playerSpawnpointSprite->color = { {0x09} };
	playerSpawnpointSprite->drawLayer = DrawLayers::ONE;
	PositionComponent* playerSpawnpointPosition = ECS::Add<PositionComponent>(PLAYER_SPAWNPOINT);
	ECS::Add<ConsoleOutputComponent>(PLAYER_SPAWNPOINT)->output = { "You respawned at spawnpoint." };
	playerSpawnpointPosition->posX = ECS::Get<PositionComponent>(PLAYER)->posX;
	playerSpawnpointPosition->posY = ECS::Get<PositionComponent>(PLAYER)->posY;

	SpriteComponent* door = ECS::Add<SpriteComponent>(WORLD1_1_DOOR1);
	door->sprite = { { char(205) }, { char(205) } };
	door->color = { {0x03}, {0x03} };
	door->drawLayer = 1;
	ECS::Add<PositionComponent>(WORLD1_1_DOOR1, PositionComponent(19, 15));
	ECS::Add<SceneComponent>(WORLD1_1_DOOR1)->nextScene = QUIT;
	ECS::Add<CollisionComponent>(WORLD1_1_DOOR1)->collisionSetting = CollisionTypes::SOLID;
	ECS::Add<LockComponent>(WORLD1_1_DOOR1, LockComponent(SILVER_KEY));

	update = true;
	playerSpawnTime = Application::GetGlobalTimer();
}

void World1_1::Update()
{
	update = continueUpdate;

	Collision(mainCanvas);
	ReadInput();
	PlayerInputMovement();
	PlayerInputEscape();
	PlayerInteractDoors();
	PlayerRespawn();
	Movement(mainCanvas);
	ExecuteOrder66();

	DrawEntities(mainCanvas);
	DrawCanvas(mainCanvas);
	DrawCanvasOnCanvas(mainCanvas, backgroundCanvas);

	if (ECS::Get<PositionComponent>(PLAYER)->posY == 8)
	{
		nextScene = WORLD1_2;
		update = false;
	}
	if (ECS::Get<PositionComponent>(PLAYER)->posY == 15 && 
		(ECS::Get<PositionComponent>(PLAYER)->posX == 4 || ECS::Get<PositionComponent>(PLAYER)->posX == 5))
	{
		nextScene = WORLD1_3;
		update = false;
	}
}

void World1_1::End()
{
	killQueue.push_back(WORLD1_1_DOOR1);
	killQueue.push_back(PLAYER_SPAWNPOINT);
	ExecuteOrder66();

	backgroundCanvas->Erase();
	mainCanvas->Erase();

	delete mainCanvas;
	delete backgroundCanvas;

	if (nextScene == WORLD1_2)
	{
		ECS::Get<PositionComponent>(PLAYER)->posY--;
		SceneManager::RegisterScene(new World1_2());
	}
	else if (nextScene == WORLD1_3)
	{
		ECS::Get<PositionComponent>(PLAYER)->posY++;
		SceneManager::RegisterScene(new World1_3());
	}
	else if (nextScene == MAINMENU)
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
