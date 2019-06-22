#include "startup.h"
#include "canvas.h"
#include "ecs.h"

Startup::Startup()
{
}

void Startup::Start()
{
	update = true;

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
	mainCanvas->EraseBuffersContents();

	fogOfWarCanvas = new Canvas();
	fogOfWarCanvas->Copy(backgroundCanvas);
	fogOfWarCanvas->SetBuffersToZero();
	fogOfWarCanvas->SetColorkey(15);


	SpriteComponent* playerSprite = ECS::Add<SpriteComponent>(PLAYER);
	playerSprite->sprite = { { '#' } };
	playerSprite->color = { {13} };
	playerSprite->drawLayer = drawLayers::TWO;

	CollisionComponent* collision = ECS::Add<CollisionComponent>(PLAYER);
	collision->collisionSetting = CollisionTypes::DYNAMIC;
	collision->collisionBuffer = { {true} };

	PositionComponent* playerPosition = ECS::Add<PositionComponent>(PLAYER, PositionComponent(9, 3));
	ECS::Add<MotionComponent>(PLAYER);
	ECS::Add<InputComponent>(PLAYER);
	ECS::Add<BackpackComponent>(PLAYER);

	//SpriteComponent* lightSprite = ECS::Add<SpriteComponent>(40);
	//lightSprite->sprite = std::vector<std::vector<char>>(11, std::vector<char>(11, ' '));
	//lightSprite->color = std::vector<std::vector<short>>(11, std::vector<short>(11, 15));
	////lightSprite->canvasToDrawOn = canvases::FOG_OF_WAR;
	//lightSprite->drawLayer = drawLayers::ONE;
	ECS::Add<PositionComponent>(40, PositionComponent(0, 0));

	SpriteComponent* keySprite = ECS::Add<SpriteComponent>(WORLD_ONE_SILVER_KEY);
	keySprite->sprite = { { char(235) } };
	keySprite->sprite.shrink_to_fit();

	keySprite->color = { {14} };
	keySprite->color.shrink_to_fit();

	keySprite->drawLayer = 1;

	ECS::Add<PositionComponent>(WORLD_ONE_SILVER_KEY, PositionComponent(18, 10));
	ECS::Add<CollisionComponent>(WORLD_ONE_SILVER_KEY, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<BackpackItemComponent>(WORLD_ONE_SILVER_KEY, BackpackItemComponent(GOLD_KEY));
}



void Startup::Update()
{
	mainCanvas->CombineWith(backgroundCanvas);
	fogOfWarCanvas->SetBuffersToZero();

	Draw();	
	Input();
	ProcessPlayerInput();
	Movement();

	DrawLight(ECS::Get<PositionComponent>(40), 12, 0.05f);
	ECS::Get<PositionComponent>(40)->posX = ECS::Get<PositionComponent>(PLAYER)->posX - 12;
	ECS::Get<PositionComponent>(40)->posY = ECS::Get<PositionComponent>(PLAYER)->posY - 12;
	

	mainCanvas->CombineWith(fogOfWarCanvas);
	mainCanvas->Draw();
}

void Startup::End()
{
	SceneManager::RegisterScene(new Startup());
}
//OWNER BLOCKS LIGHT
void Startup::DrawLight(PositionComponent* positionComponent, const int radius, const float angleRadStepSize)
{
	const float twoPi = 2.0f * (atanf(1) * 4);
	float angleRad = 0.0f;

	const int entityPosX = positionComponent->posX;
	const int entityPosY = positionComponent->posY;

	for (angleRad; angleRad < twoPi; angleRad += angleRadStepSize)
	{
		for (int r = 1; r != radius; r++)
		{
			int const spritePosX = radius + (int)((r)* cos(angleRad));
			int const spritePosY = radius + (int)((r)* sin(angleRad));

			if (mainCanvas->GetCollisionAt(spritePosX + entityPosX, spritePosY + entityPosY) == false || 
				spritePosX == radius && spritePosY == radius)
			{
				fogOfWarCanvas->PutChar(' ', spritePosX + entityPosX, spritePosY + entityPosY, fogOfWarCanvas->GetColorKey(), 0);
			}
			else
			{
				fogOfWarCanvas->PutChar(' ', spritePosX + entityPosX, spritePosY + entityPosY, fogOfWarCanvas->GetColorKey(), 0);
				break;
			}
		}
	}
}


void Startup::ProcessPlayerInput()
{
	if (InputComponent* inputComponent = ECS::Get<InputComponent>(Entities::PLAYER))
	{
		if (MotionComponent* motionComponent = ECS::Get<MotionComponent>(Entities::PLAYER))
		{
			if (inputComponent->command == 'W')
			{
				motionComponent->up = 1;
			}
			if (inputComponent->command == 'A')
			{
				motionComponent->left = 1;
			}
			if (inputComponent->command == 'S')
			{
				motionComponent->down = 1;
			}
			if (inputComponent->command == 'D')
			{
				motionComponent->right = 1;
			}
		}

		if (inputComponent->command == 'E')
		{
			if (BackpackComponent* backpackComponent = ECS::Get<BackpackComponent>(Entities::PLAYER))
			{
				if (PositionComponent* positionComponent = ECS::Get<PositionComponent>(Entities::PLAYER))
				{
					//kolla alla
					if (int const item = GetEntityAt(positionComponent->posX + 1, positionComponent->posY, Entities::PLAYER))
					{
						if (BackpackItemComponent* backpackItemComponent = ECS::Get<BackpackItemComponent>(item))
						{
							PositionComponent* positionComponent = ECS::Get<PositionComponent>(item);
							positionComponent->isActive = false;

							if (SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(item))
							{
								spriteComponent->isActive = false;
							}
							if (CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(item))
							{
								collisionComponent->isActive = false;
							}

							backpackComponent->items[backpackItemComponent->type]++;
						}
					}
				}
			}
		}
	}
}

void Startup::Draw()
{
	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<SpriteComponent>()
		});


	for (short drawLayer = 0; drawLayer < drawLayers::NUMBER_OF_DRAW_LAYERS; drawLayer++)
	{
		for (int e = 0; e < ENTITIES.size(); e++)
		{
			SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(ENTITIES[e]);
			PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);

			if (spriteComponent->drawLayer == drawLayer && spriteComponent->isActive)
			{
				for (int x = 0; x < spriteComponent->sprite.size(); x++)
				{
					for (int y = 0; y < spriteComponent->sprite[x].size(); y++)
					{
						if (spriteComponent->color[x][y] != spriteComponent->colorKey)
						{
							short collisionType = CollisionTypes::NONE;

							if (CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(ENTITIES[e]))
							{
								collisionType = collisionComponent->collisionSetting;
							}

							if (!spriteComponent->canvasToDrawOn || spriteComponent->canvasToDrawOn == canvases::MAIN)
							{
								mainCanvas->PutChar(spriteComponent->sprite[x][y], positionComponent->posX + x, positionComponent->posY + y, spriteComponent->color[x][y], collisionType);
							}
							else if (spriteComponent->canvasToDrawOn == canvases::FOG_OF_WAR)
							{
								fogOfWarCanvas->PutChar(spriteComponent->sprite[x][y], positionComponent->posX + x, positionComponent->posY + y, spriteComponent->color[x][y], collisionType);
							}
						}
					}
				}
			}
		}
	}
}

void Startup::Input()
{
	const std::array<int, 5> vKeys{ 0x41, 0x57, 0x53, 0x44, 0x45 };

	if (InputComponent* inputComponent = ECS::Get<InputComponent>(Entities::PLAYER))
	{
		inputComponent->command = ' ';
		int i = 0;

		for (i; i < vKeys.size(); i++)
		{
			if (Application::Input(vKeys[i]))
			{
				if (inputComponent->hasClicked == false)
				{
					inputComponent->command = toascii(vKeys[i]);
					inputComponent->hasClicked = true;
				}
				break;
			}
		}
		if (i == vKeys.size() && inputComponent->hasClicked == true)
		{
			inputComponent->hasClicked = false;
		}
	}
}

int Startup::GetEntityAt(int const posX, int const posY, int const id)
{
	const std::vector<int> ENTITIES = ECS::GetAllIDFrom<PositionComponent>();

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);

		if (ENTITIES[e] != id && 
			positionComponent->isActive &&
			positionComponent->posX == posX &&
			positionComponent->posY == posY)
		{
			return ENTITIES[e];
		}
	}
	return 0;
}

//background: East Sea Dokdo

bool Startup::IsPositionFree(int const posX, int const posY, int const id, CollisionComponent* collisionComponent)
{	
	short const collisionCanvas = mainCanvas->GetCollisionAt(posX, posY);

	if (collisionComponent->collisionSetting == CollisionTypes::SOLID &&
		(collisionCanvas == CollisionTypes::SOLID ||
			collisionCanvas == CollisionTypes::DYNAMIC ||
			collisionCanvas == CollisionTypes::KINETIC))
	{
		return false;
	}

	if (collisionComponent->collisionSetting == CollisionTypes::DYNAMIC &&
		(collisionCanvas == CollisionTypes::SOLID ||
			collisionCanvas == CollisionTypes::DYNAMIC))
	{
		return false;
	}


	//if (mainCanvas->GetCollisionAt(posX, posY) == CollisionTypes::DYNAMIC)
	//{
	//	return false;
	//}

	//if (int const other = GetEntityAt(posX, posY, id))
	//{
	//	if (CollisionComponent* collisionComponentOther = ECS::Get<CollisionComponent>(other))
	//	{
	//		if (collisionComponent != nullptr && 
	//			collisionComponentOther->isActive == true)
	//		{
	//			if (collisionComponent->collisionSetting == CollisionTypes::SOLID &&
	//				(collisionComponentOther->collisionSetting == CollisionTypes::SOLID || 
	//				collisionComponentOther->collisionSetting == CollisionTypes::DYNAMIC ||
	//				collisionComponentOther->collisionSetting == CollisionTypes::KINETIC))
	//			{
	//				return false;
	//			}
	//			
	//			if (collisionComponent->collisionSetting == CollisionTypes::DYNAMIC &&
	//				(collisionComponentOther->collisionSetting == CollisionTypes::SOLID))
	//			{
	//				return false;
	//			}
	//		}
	//	}
	//}
	
	return true;
}

void Startup::Movement()
{
	float timePoint = Application::GetGlobalTimer();

	const std::vector<int> ENTITIES_NEARBY = ECS::GetAllIDFrom<PositionComponent>();

	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<CollisionComponent>(),
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<MotionComponent>()
		});

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(ENTITIES[e]);
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);
		MotionComponent* motionComponent = ECS::Get<MotionComponent>(ENTITIES[e]);

		bool collided = false;

		if (motionComponent->isActive && (motionComponent->movementRate == 0.0f || motionComponent->timeToMove < timePoint))
		{
			// MOTION UP
			if (motionComponent->up)
			{			
				for (int x = 0; x < collisionComponent->collisionBuffer.size(); x++)
				{
					for (int y = 0; y < collisionComponent->collisionBuffer[x].size(); y++)
					{
						if (collisionComponent->collisionBuffer[x][y])
						{
							if (this->IsPositionFree(positionComponent->posX + x, positionComponent->posY + y - 1, ENTITIES[e], collisionComponent) == false)
							{
								collided = true;
							}
						}
					}
				}

				if (collided == false)
				{
					positionComponent->posY -= 1;
				}
			}

			// MOTION DOWN
			if (motionComponent->down)
			{
				for (int x = 0; x < collisionComponent->collisionBuffer.size(); x++)
				{
					for (int y = 0; y < collisionComponent->collisionBuffer[x].size(); y++)
					{
						if (collisionComponent->collisionBuffer[x][y])
						{
							if (this->IsPositionFree(positionComponent->posX + x, positionComponent->posY + y + 1, ENTITIES[e], collisionComponent) == false)
							{
								collided = true;
							}
						}
					}
				}

				if (collided == false)
				{
					positionComponent->posY += 1;
				}
			}

			// MOTION RIGHT
			if (motionComponent->right)
			{
				for (int x = 0; x < collisionComponent->collisionBuffer.size(); x++)
				{
					for (int y = 0; y < collisionComponent->collisionBuffer[x].size(); y++)
					{
						if (collisionComponent->collisionBuffer[x][y])
						{
							if (this->IsPositionFree(positionComponent->posX + x + 1, positionComponent->posY + y, ENTITIES[e], collisionComponent) == false)
							{
								collided = true;
							}
						}
					}
				}

				if (collided == false)
				{
					positionComponent->posX += 1;
				}
			}

			// MOTION LEFT
			if (motionComponent->left)
			{
				for (int x = 0; x < collisionComponent->collisionBuffer.size(); x++)
				{
					for (int y = 0; y < collisionComponent->collisionBuffer[x].size(); y++)
					{
						if (collisionComponent->collisionBuffer[x][y])
						{
							if (this->IsPositionFree(positionComponent->posX + x - 1, positionComponent->posY + y, ENTITIES[e], collisionComponent) == false)
							{
								collided = true;
							}
						}
					}
				}

				if (collided == false)
				{
					positionComponent->posX -= 1;
				}
			}

			if (motionComponent->movementRate == 0.0f)
			{
				motionComponent->up = 0;
				motionComponent->down = 0;
				motionComponent->left = 0;
				motionComponent->right = 0;
			}
			else
			{
				motionComponent->timeToMove = timePoint + (1.0f / motionComponent->movementRate);
			}
		}
	}
}