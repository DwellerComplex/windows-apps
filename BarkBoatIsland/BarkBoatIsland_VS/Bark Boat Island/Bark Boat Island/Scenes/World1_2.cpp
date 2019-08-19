#include "World1_2.h"
#include "World1_1.h"
#include "mainmenu.h"
#include "../canvas.h"
#include "../rectanglebuffers.h"
#include "../ecs.h"
#include "../globalenums.h"

World1_2::World1_2()
{
}

void World1_2::Start()
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
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
{char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32)},
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
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
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
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
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

	ECS::Add<SpriteComponent>(WORLD1_2_OBSTACLE1, SpriteComponent({ { '*' } }, { {0x0C} }, 0, 0, 1));
	ECS::Add<EnemyPatrolComponent>(WORLD1_2_OBSTACLE1, EnemyPatrolComponent(0, 1, 0, 7, 0.1, 0));
	ECS::Add<PositionComponent>(WORLD1_2_OBSTACLE1, PositionComponent(7, 3));
	ECS::Add<CollisionComponent>(WORLD1_2_OBSTACLE1)->collisionSetting = CollisionTypes::KINETIC;
	ECS::Add<MotionComponent>(WORLD1_2_OBSTACLE1, MotionComponent(1, 0, 0, 0, 10));
	ECS::Add<AttackComponent>(WORLD1_2_OBSTACLE1, AttackComponent(1));

	update = true;
	playerSpawnTime = Application::GetGlobalTimer();
}

void World1_2::Update()
{
	update = continueUpdate;

	Collision(mainCanvas);
	ReadInput();
	PlayerInputMovement();
	PlayerInputEscape();
	PlayerInteract();
	PlayerRespawn();
	Movement(mainCanvas);
	ExecuteOrder66();

	DrawEntities(mainCanvas);
	DrawConsole();
	DrawCanvas(mainCanvas);
	DrawCanvasOnCanvas(mainCanvas, backgroundCanvas);

	UpdateEnemyPatrols();

	if (ECS::Get<PositionComponent>(PLAYER)->posY == 8)
	{
		nextScene = WORLD1_1;
		update = false;
	}
}

void World1_2::End()
{
	killQueue.push_back(WORLD1_2_OBSTACLE1);
	killQueue.push_back(PLAYER_SPAWNPOINT);
	ExecuteOrder66();

	backgroundCanvas->Erase();
	mainCanvas->Erase();

	delete mainCanvas;
	delete backgroundCanvas;

	if (nextScene == WORLD1_1)
	{
		ECS::Get<PositionComponent>(PLAYER)->posY ++;
		SceneManager::RegisterScene(new World1_1());
	}
	else if (nextScene == MAINMENU)
	{
		ECS::Get<PositionComponent>(PLAYER)->posX = 1;
		ECS::Get<PositionComponent>(PLAYER)->posY = 1;
		SceneManager::RegisterScene(new Mainmenu());
	}
}
