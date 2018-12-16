#ifndef __CONSOLEPANEL_H_INCLUDED__
#define __CONSOLEPANEL__

#pragma once
#include "room.h"

class ConsolePanel
{
public:
	ConsolePanel() {};
	void create(int const topLeftX, int const topLeftY, int const width, int const height);
	void draw();
	void destroy();
	void erase();
	void enqueue(std::string const output);
	Room* console;

private:
	std::vector <std::string> outputQueue;
};

#endif