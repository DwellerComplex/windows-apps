#include "game.h"

int main(int argc, const char** argv)
{
	//Initial system setup
	Application& app = Application::get_instance();
	app.SetTitle("Bark Boat Island");
	app.SetConsoleSize(1800, 1000);
	app.SetConsoleScreenBuffer();
	app.SetCursorPosition(0, 0);
	app.ShowConsoleCursor(false);
	app.StartGlobalTimer();

	//Start a game
	Game gameInstance;
	gameInstance.SetCurrentRoom("MainMenu");

	while (gameInstance.GetCurrentRoom() != "")
	{
		gameInstance.PlayRoom();
	}

	return 0;
}