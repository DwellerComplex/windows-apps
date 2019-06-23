#include "startup.h"
#include "canvas.h"
#include "rectanglebuffers.h"
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

	RectangleBuffers playerBackpackBuffers = RectangleBuffers(char(32), char(205), char(186), char(201), char(187), char(188), char(200), 20, 40, 8, 3);
	playerBackpack = new Canvas(Application::GetConsoleWidth() - 20, 0, 0, *playerBackpackBuffers.GetCharBuffer(), *playerBackpackBuffers.GetColorBuffer());
	playerBackpack->PutString("BACKPACK", 1, 1, 95, true, ' ', 95);

	SpriteComponent* playerSprite = ECS::Add<SpriteComponent>(PLAYER);
	playerSprite->sprite = { { '#' } };
	playerSprite->color = { {13} };
	playerSprite->drawLayer = drawLayers::TWO;

	CollisionComponent* playerCollision = ECS::Add<CollisionComponent>(PLAYER);
	playerCollision->collisionSetting = CollisionTypes::DYNAMIC;
	playerCollision->collisionBuffer = { {true} };

	PositionComponent* playerPosition = ECS::Add<PositionComponent>(PLAYER, PositionComponent(9, 3));
	ECS::Add<MotionComponent>(PLAYER);
	ECS::Add<InputComponent>(PLAYER);
	ECS::Add<BackpackComponent>(PLAYER);

	ECS::Add<PositionComponent>(FLASHLIGHT, PositionComponent(0, 0));

	SpriteComponent* keySprite = ECS::Add<SpriteComponent>(STARTUP_SILVER_KEY);
	keySprite->sprite = { { char(235) } };
	keySprite->sprite.shrink_to_fit();

	keySprite->color = { {0x0F} };
	keySprite->color.shrink_to_fit();

	keySprite->drawLayer = 1;

	ECS::Add<PositionComponent>(STARTUP_SILVER_KEY, PositionComponent(18, 10));
	ECS::Add<CollisionComponent>(STARTUP_SILVER_KEY, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<BackpackItemComponent>(STARTUP_SILVER_KEY, BackpackItemComponent(SILVER_KEY));
}

void Startup::Update()
{
	Collision();
	Input();
	ProcessPlayerInput();
	Movement();
	Draw();
}

void Startup::End()
{
	delete backgroundCanvas;
	delete fogOfWarCanvas;
	delete mainCanvas;
	SceneManager::RegisterScene(new Startup());
}

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
							playerBackpack->SetDrawThisTick(true);
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
							if (!spriteComponent->canvasToDrawOn || spriteComponent->canvasToDrawOn == canvases::MAIN)
							{
								mainCanvas->PutChar(spriteComponent->sprite[x][y], positionComponent->posX + x, positionComponent->posY + y, spriteComponent->color[x][y]);
							}
							else if (spriteComponent->canvasToDrawOn == canvases::FOG_OF_WAR)
							{
								fogOfWarCanvas->PutChar(spriteComponent->sprite[x][y], positionComponent->posX + x, positionComponent->posY + y, spriteComponent->color[x][y]);
							}
						}
					}
				}
			}
		}
	}

	//_________________other_draws_________________//

	//flashlight
	DrawLight(ECS::Get<PositionComponent>(FLASHLIGHT), 12, 0.05f);
	ECS::Get<PositionComponent>(FLASHLIGHT)->posX = ECS::Get<PositionComponent>(PLAYER)->posX - 12;
	ECS::Get<PositionComponent>(FLASHLIGHT)->posY = ECS::Get<PositionComponent>(PLAYER)->posY - 12;

	//backpack
	if (playerBackpack->GetDrawThisTick() == true)
	{
		if (BackpackComponent* backpackComponent = ECS::Get<BackpackComponent>(PLAYER))
		{
			if (backpackComponent->items[SILVER_KEY]) { playerBackpack->PutString("Silver Keys: " + std::to_string(backpackComponent->items[SILVER_KEY]), 1, 3, 6, false); }
			if (backpackComponent->items[GOLD_KEY]) { playerBackpack->PutString("Gold Keys: " + std::to_string(backpackComponent->items[GOLD_KEY]), 1, 4, 6, false); }
		}
		playerBackpack->Draw();
		playerBackpack->SetDrawThisTick(false);
	}

	//canvas
	mainCanvas->CombineWith(fogOfWarCanvas);
	mainCanvas->Draw();
	mainCanvas->CombineWith(backgroundCanvas);
	fogOfWarCanvas->SetBuffersToZero();
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

void Startup::Collision()
{
	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<SpriteComponent>(),
			ECS::GetAllIDFrom<CollisionComponent>()
		});

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(ENTITIES[e]);
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);
		CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(ENTITIES[e]);

		if (spriteComponent->isActive)
		{
			for (int x = 0; x < spriteComponent->sprite.size(); x++)
			{
				for (int y = 0; y < spriteComponent->sprite[x].size(); y++)
				{
					if (spriteComponent->color[x][y] != spriteComponent->colorKey)
					{
						mainCanvas->PutCollision(positionComponent->posX + x, positionComponent->posY + y, collisionComponent->collisionSetting);
					}
				}
			}
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