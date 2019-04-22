#include "game.h"

int main(int argc, const char** argv)
{
	//Initial system setup

	Application::SetFontEncoding(437);
	Application::SetTitle("Bark Boat Island");
	Application::SetFontSize(16, 16);
	Application::SetConsoleSize(1800, 1000);
	Application::SetConsoleScreenBuffer();
	Application::SetCursorPosition(0, 0);
	Application::ShowConsoleCursor(false);
	Application::StartGlobalTimer();

	//Start a game
	Game gameInstance;
	gameInstance.SetCurrentScene(gameInstance.Scenes::MAINMENU);

	while (gameInstance.GetCurrentRoom())
	{
		gameInstance.PlayScene();
	}

	return 0;
}