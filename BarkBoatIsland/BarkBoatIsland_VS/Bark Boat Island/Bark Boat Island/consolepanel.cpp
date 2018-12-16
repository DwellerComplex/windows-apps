#include "consolepanel.h"

void ConsolePanel::create(int const topLeftX, int const topLeftY, int const width, int const height)
{
	Room* con = new Room("Console", char(39), char(248), char(248), char(248), char(248), char(248), char(248), width, height, topLeftX, topLeftY,8,3); //char(219)
	this->console = con;

	this->outputQueue.resize(this->console->GetHeight() - 2);
}

void ConsolePanel::draw()
{
	console->Draw();
}

void ConsolePanel::enqueue(std::string const output)
{
	for (int i = (this->outputQueue.size() - 2) ; i >= 0; --i) 
	{
		outputQueue[i + 1] = outputQueue[i];
	}
	
	outputQueue[0] = output;


	std::string out;
	char character;

	for (int row = 0; row < this->outputQueue.size(); row++)
	{
		out = outputQueue[row];

		//"erase" output in scene
		for (int charPos = 0; charPos < console->GetWidth() - 2; charPos++)
		{
			character = this->console->GetFloor(); 
			console->DrawSprite(character, charPos + 1, row + 1, this->console->GetFloorColor());
		}

		//draw output
		for (int charPos = 0; charPos < out.size(); charPos++)
		{
			character = out[charPos];
			console->DrawSprite(character, charPos + 1, row + 1);
		}
	}
}

void ConsolePanel::destroy()
{
	this->console->Erase();
	delete this->console;
}

void ConsolePanel::erase()
{
	this->console->Erase();
}