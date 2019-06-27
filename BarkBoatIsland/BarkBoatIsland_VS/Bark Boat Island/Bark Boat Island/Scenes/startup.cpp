#include "startup.h"
#include "../canvas.h"
#include "../rectanglebuffers.h"
#include "../ecs.h"
#include "../globalenums.h"
#include "smallhouse.h"
#include "mainmenu.h"
#include "amberstrand.h"
//background: East Sea Dokdo
Startup::Startup()
{
}

void Startup::Start()
{
	std::vector<std::vector<char>> mapChars = {
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(201),char(205),char(205),char(205),char(205),char(205),char(187),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(186),char(177),char(177),char(177),char(177),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(201),char(205),char(205),char(205),char(205),char(205),char(205),char(187),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(200),char(187),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(200),char(187),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(201),char(188),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(201),char(205),char(205),char(205),char(187),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(177),char(177),char(177),char(177),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(201),char(188),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(201),char(188),char(32),char(32),char(32),char(32),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(186),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(200),char(205),char(205),char(187),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(200),char(205),char(205),char(188),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(200),char(205),char(205),char(205),char(205),char(205),char(205),char(188),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(200),char(205),char(205),char(205),char(205),char(188),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(177),char(177),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(201),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(187),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(201),char(205),char(205),char(205),char(205),char(205),char(205),char(187),char(32),char(32),char(32),char(177),char(177),char(177),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(201),char(205),char(205),char(188),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(201),char(188),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(200),char(205),char(205),char(187),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(200),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(188),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(200),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(188),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(177),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(201),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(187),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(186),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(200),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(188),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) },
	{ char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32),char(32) }
	};

	std::vector<std::vector<short>> mapColors = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,15,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,15,0,0,0,0,0,15,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,15,15,0,0,0,0,15,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,15,0,0,0,0,15,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,15,15,0,0,0,0,15,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,0,0,0,0,0},
	{0,15,0,0,0,0,0,15,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,15,0,0,0,0,0,0,0,15,8,8,8,8,8,0,0,0,0,0,0,0,15,15,0,0,0,15,0,0,0,0,0},
	{0,15,0,0,0,0,0,15,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,15,0,0,0,0,0,0,0,15,0,0,0,0,8,0,0,0,0,0,0,0,15,0,0,0,0,15,0,0,0,0,0},
	{0,15,0,0,0,0,0,15,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,15,0,0,0,0,0,0,0,15,0,0,0,0,8,0,0,0,0,0,0,0,15,0,0,0,0,15,0,0,0,0,0},
	{0,15,0,0,0,0,0,15,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,15,0,0,0,0,0,0,15,15,0,0,0,0,8,8,8,8,8,8,8,8,15,0,0,0,0,15,0,0,0,0,0},
	{0,15,15,15,15,0,0,15,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,15,0,0,0,0,0},
	{0,0,0,0,15,15,15,15,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,0},
	{0,0,0,0,0,15,15,15,15,15,15,15,15,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,15,15,15,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,15,0,0,0,0,0,0,15,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,15,15,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,15,0,0,0,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,15,15,15,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	std::vector<std::vector<short>> mapCollisions = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,3,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,3,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0},
	{0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,3,0,0,0,0,0},
	{0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0},
	{0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0},
	{0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0},
	{0,3,3,3,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0},
	{0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0},
	{0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,3,3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	Application::TransformVector2D(mapChars);
	Application::TransformVector2D(mapColors);
	Application::TransformVector2D(mapCollisions);
	backgroundCanvas = new Canvas(0, 0, 1, mapChars, mapColors, mapCollisions);

	mainCanvas = new Canvas();
	mainCanvas->Copy(backgroundCanvas);
	mainCanvas->SetBuffersToZero();

	fogOfWarCanvas = new Canvas();
	fogOfWarCanvas->Copy(backgroundCanvas);
	fogOfWarCanvas->SetBuffersToZero();
	fogOfWarCanvas->SetColorkey(15);

	RectangleBuffers playerBackpackBuffers = RectangleBuffers(char(32), char(205), char(186), char(201), char(187), char(188), char(200), 20, Application::GetConsoleHeight() - 8, 8, 3);
	playerBackpack = new Canvas(Application::GetConsoleWidth() - 20, 0, 0, *playerBackpackBuffers.GetCharBuffer(), *playerBackpackBuffers.GetColorBuffer());
	playerBackpack->PutString("BACKPACK", 1, 1, 95, true, ' ', 95);

	RectangleBuffers consoleBuffers = RectangleBuffers(char(32), char(205), char(186), char(201), char(187), char(188), char(200), Application::GetConsoleWidth(), 8, 8, 3);
	console = new Canvas(0, Application::GetConsoleHeight() - 8, 0, *consoleBuffers.GetCharBuffer(), *consoleBuffers.GetColorBuffer());

	ECS::Get<SpriteComponent>(PLAYER_SPAWNPOINT)->isActive = true;
	ECS::Get<PositionComponent>(PLAYER_SPAWNPOINT)->posX = ECS::Get<PositionComponent>(PLAYER)->posX;
	ECS::Get<PositionComponent>(PLAYER_SPAWNPOINT)->posY = ECS::Get<PositionComponent>(PLAYER)->posY;

	SpriteComponent* doorSmallHouseSprite = ECS::Add<SpriteComponent>(STARTUP_DOOR_SMALLHOUSE);
	doorSmallHouseSprite->sprite = { { char(179) } };
	doorSmallHouseSprite->color = { {15} };
	doorSmallHouseSprite->drawLayer = DrawLayers::ONE;
	ECS::Add<PositionComponent>(STARTUP_DOOR_SMALLHOUSE, PositionComponent(7, 3));
	ECS::Add<SceneComponent>(STARTUP_DOOR_SMALLHOUSE)->nextScene = SMALLHOUSE;
	//ECS::Add<LockComponent>(STARTUP_DOOR_SMALLHOUSE)->key = SILVER_KEY;
	ECS::Add<CollisionComponent>(STARTUP_DOOR_SMALLHOUSE)->collisionSetting = CollisionTypes::SOLID;

	SpriteComponent* spikeTrapSprite = ECS::Add<SpriteComponent>(STARTUP_SPIKETRAP);
	spikeTrapSprite->sprite = { { 'O' } };
	spikeTrapSprite->color = { {8} };
	spikeTrapSprite->drawLayer = DrawLayers::ONE;
	ECS::Add<PositionComponent>(STARTUP_SPIKETRAP, PositionComponent(10, 10));
	SpikeTrapComponent* spikeTrapComponent = ECS::Add<SpikeTrapComponent>(STARTUP_SPIKETRAP);
	spikeTrapComponent->attackDelay = 0.5f;
	spikeTrapComponent->activeTime = 2.0f;
	ECS::Add<AttackComponent>(STARTUP_SPIKETRAP)->damage = 1;
	ECS::Add<CollisionComponent>(STARTUP_SPIKETRAP)->collisionSetting = CollisionTypes::NONE;
	ECS::Add<ConsoleOutputComponent>(STARTUP_SPIKETRAP)->output = { "You took 1 damage!" };

	update = true;
	playerSpawnTime = Application::GetGlobalTimer();
}

void Startup::Update()
{
	update = continueUpdate;

	Collision(mainCanvas);

	DrawLight(ECS::Get<PositionComponent>(PLAYER), 12, 0.05f);

	Input();
	PlayerInputMovement();
	PlayerInputEscape();
	PlayerInteractBackpack(playerBackpack, console);
	PlayerInteractDoors();
	PlayerRespawn(console);
	UpdateSpikeTraps(console);
	Movement(mainCanvas);
	ExecuteOrder66();
	DrawEntities(mainCanvas);
	DrawCanvasOnCanvas(mainCanvas, fogOfWarCanvas);
	DrawConsole(console);
	DrawPlayerBackpack(playerBackpack);
	DrawCanvas(mainCanvas);
	DrawCanvasOnCanvas(mainCanvas, backgroundCanvas);
	ZeroCanvasBuffers(fogOfWarCanvas);

	if (ECS::Get<PositionComponent>(PLAYER)->posX == 55)
	{
		nextScene = AMBERSTRAND;
		update = false;
	}
}

void Startup::End()
{
	killQueue.emplace_back(STARTUP_DOOR_SMALLHOUSE);
	killQueue.emplace_back(STARTUP_SPIKETRAP);
	ExecuteOrder66();

	backgroundCanvas->Erase();
	fogOfWarCanvas->Erase();
	mainCanvas->Erase();
	playerBackpack->Erase();
	console->Erase();

	delete backgroundCanvas;
	delete fogOfWarCanvas;
	delete mainCanvas;
	delete playerBackpack;
	delete console;

	if (nextScene == MAINMENU)
	{
		SceneManager::RegisterScene(new Mainmenu());
		ECS::Get<PositionComponent>(PLAYER)->posX = 1;
		ECS::Get<PositionComponent>(PLAYER)->posY = 1;
	}
	else if (nextScene == SMALLHOUSE)
	{
		SceneManager::RegisterScene(new SmallHouse());
		ECS::Get<PositionComponent>(PLAYER)->posX = 5;
		ECS::Get<PositionComponent>(PLAYER)->posY = 2;
	}
	else if (nextScene == AMBERSTRAND)
	{
		SceneManager::RegisterScene(new Amberstrand());
		ECS::Get<PositionComponent>(PLAYER)->posX = 0;
	}
}

void Startup::DrawLight(PositionComponent* positionComponent, const int radius, const float angleRadStepSize)
{
	const float twoPi = 2.0f * (atanf(1) * 4);
	float angleRad = 0.0f;

	const int entityPosX = positionComponent->posX - radius;
	const int entityPosY = positionComponent->posY - radius;

	for (angleRad; angleRad < twoPi; angleRad += angleRadStepSize)
	{
		for (int r = 1; r != radius; r++)
		{
			int const spritePosX = radius + (int)((r)* cos(angleRad));
			int const spritePosY = radius + (int)((r)* sin(angleRad));

			if (mainCanvas->GetCollisionAt(spritePosX + entityPosX, spritePosY + entityPosY) == false || 
				spritePosX == radius && spritePosY == radius)
			{
				fogOfWarCanvas->PutChar(' ', spritePosX + entityPosX, spritePosY + entityPosY, fogOfWarCanvas->GetColorKey());
			}
			else
			{
				fogOfWarCanvas->PutChar(' ', spritePosX + entityPosX, spritePosY + entityPosY, fogOfWarCanvas->GetColorKey());
				break;
			}
		}
	}
}
