#include "World1_1.h"
#include "World1_2.h"
#include "World1_3.h"
#include "World1_4.h"
#include "World1_5.h"
#include "mainmenu.h"
#include "../rectanglebuffers.h"
#include "../ecs.h"
#include "../globalenums.h"

World1_1::World1_1()
{
}

World1_1::~World1_1()
{
}

void World1_1::Start()
{
	std::vector<std::vector<char>> mapChars = {
{char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236)},
{char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236)},
{char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236)},
{char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236)},
{char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236)},
{char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236)},
{char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236)},
{char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236)},
{char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(93),char(254),char(254),char(254),char(91),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236)},
{char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(177),char(177),char(177),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(177),char(177),char(177),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(254),char(254),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(254),char(254),char(177),char(177),char(254),char(254),char(254),char(254),char(254),char(254),char(177),char(177),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(254),char(254),char(177),char(177),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254)},
{char(177),char(177),char(177),char(177),char(177),char(177),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(177),char(177),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(236),char(93),char(254),char(254),char(91),char(236),char(254),char(254),char(254),char(254),char(254),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(236),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(236),char(236),char(236),char(236),char(236),char(236),char(254),char(254),char(254),char(254),char(254),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(236),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(79),char(79),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254)},
{char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(39),char(39),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254),char(254)},
};

	std::vector<std::vector<short>> mapColors = {
	{0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E},
	{ 0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E },
	{ 0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E },
	{ 0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E },
	{ 0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E },
	{ 0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E },
	{ 0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E },
	{ 0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E },
	{ 0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0,0,0,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E },
	{ 0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xA8,0xA8,0xA8,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xA8,0xA8,0xA8,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0xAA,0xAA,0xAA,0xA8,0xA8,0xA8,0xA8,0xA8,0xA8,0xA8,0xA8,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0xAA,0xAA,0xAA,0xA8,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xA8,0xA8,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0xAA,0xAA,0xA8,0xA8,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xA8,0xA8,0xA8,0xA8,0xA8,0xA8,0xA8,0xA8,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA },
	{ 0xA8,0xA8,0xA8,0xA8,0xA8,0xA8,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xA8,0xA8,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0x6E,0x6E,0,0,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA,0xAA,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA },
	{ 0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA },
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
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{0,0,3,3,0,0,3,3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,3},
{0,0,3,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3},
{0,0,3,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3},
{0,0,3,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3},
{0,0,3,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3},
{0,0,3,3,3,3,3,3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,3},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
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

	ECS::Add<SpriteComponent>(MERIMEL, SpriteComponent({ { char(34) } }, { {0x5F} }, 0, 1, DrawLayers::TWO));
	ECS::Add<CollisionComponent>(MERIMEL, CollisionComponent(CollisionTypes::DYNAMIC, { {true} }));
	ECS::Add<PositionComponent>(MERIMEL, PositionComponent(7, 10));
	ECS::Add<ConsoleOutputComponent>(MERIMEL)->output = {"Merimel: This is so cool dad!", "Look what I found", "while you were asleep!"};
	MotionComponent* motionComponent = ECS::Add<MotionComponent>(MERIMEL);
	motionComponent->movementRate = 10.0f;
	motionComponent->pathNodes =
	{
		MotionComponent::PathNode(PositionComponent(7,16),{MERIMEL},0,0,1,0)
	};

	ECS::Add<SpriteComponent>(WORLD1_1_DOOR1, SpriteComponent({ { char(205) }, { char(205) } },{ {0x03}, {0x03} },0,0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_DOOR1, PositionComponent(19, 15));
	ECS::Add<SceneComponent>(WORLD1_1_DOOR1)->nextScene = WORLD1_4;
	ECS::Add<CollisionComponent>(WORLD1_1_DOOR1)->collisionSetting = CollisionTypes::SOLID;
	ECS::Add<LockComponent>(WORLD1_1_DOOR1, LockComponent(SILVER_KEY));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE1, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE1, PositionComponent(15, 22));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE1, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE1, TreeComponent(3,4,0.2f,0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE2, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE2, PositionComponent(20, 22));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE2, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE2, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE3, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE3, PositionComponent(21, 22));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE3, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE3, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE4, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE4, PositionComponent(4, 21));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE4, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE4, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE5, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE5, PositionComponent(1, 11));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE5, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE5, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE6, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE6, PositionComponent(2, 10));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE6, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE6, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE7, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE7, PositionComponent(2, 11));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE7, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE7, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE8, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE8, PositionComponent(3, 10));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE8, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE8, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE9, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE9, PositionComponent(3, 11));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE9, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE9, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE10, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE10, PositionComponent(4, 9));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE10, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE10, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE11, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE11, PositionComponent(4, 10));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE11, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE11, TreeComponent(3, 4, 0.2f, 0));

	ECS::Add<SpriteComponent>(WORLD1_1_TREE12, SpriteComponent({ { char(79), char(39) } }, { {0xA2, 0xA6} }, 0, 0, DrawLayers::ONE));
	ECS::Add<PositionComponent>(WORLD1_1_TREE12, PositionComponent(4, 11));
	ECS::Add<CollisionComponent>(WORLD1_1_TREE12, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<TreeComponent>(WORLD1_1_TREE12, TreeComponent(3, 4, 0.2f, 0));

	update = true;
	playerSpawnTime = Application::GetGlobalTimer();

}

void World1_1::Update()
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

	if (ECS::Get<PositionComponent>(PLAYER)->posY == 8)
	{
		nextScene = WORLD1_2;
		update = false;
	}
	else if (ECS::Get<PositionComponent>(PLAYER)->posY == 15 && 
		(ECS::Get<PositionComponent>(PLAYER)->posX == 4 || ECS::Get<PositionComponent>(PLAYER)->posX == 5))
	{
		nextScene = WORLD1_3;
		update = false;
	}
	else if (ECS::Get<PositionComponent>(PLAYER)->posX == -1)
	{
		nextScene = WORLD1_5;
		update = false;
	}
}

void World1_1::End()
{
	ECS::Destroy<SpriteComponent>(WORLD1_1_DOOR1);
	ECS::Destroy<PositionComponent>(WORLD1_1_DOOR1);
	ECS::Destroy<SceneComponent>(WORLD1_1_DOOR1);
	ECS::Destroy<CollisionComponent>(WORLD1_1_DOOR1);

	ECS::Destroy<PositionComponent>(WORLD1_1_TREE1);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE2);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE3);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE4);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE5);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE6);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE7);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE8);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE9);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE10);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE11);
	ECS::Destroy<PositionComponent>(WORLD1_1_TREE12);

	killQueue.push_back(PLAYER_SPAWNPOINT);
	ExecuteOrder66();

	backgroundCanvas.Erase();
	mainCanvas.Erase();

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
	else if (nextScene == WORLD1_4)
	{
		ECS::Get<PositionComponent>(PLAYER)->posY+=2;
		SceneManager::RegisterScene(new World1_4());
	}
	else if (nextScene == WORLD1_5)
	{
		ECS::Get<PositionComponent>(PLAYER)->posX = 31;
		SceneManager::RegisterScene(new World1_5());
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
