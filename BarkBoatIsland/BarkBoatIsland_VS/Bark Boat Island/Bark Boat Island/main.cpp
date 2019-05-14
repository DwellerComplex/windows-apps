#include "game.h"
#include "startup.h"

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

	SceneManager::RegisterScene(new Startup());

	while (SceneManager::IsRunning())
	{
		SceneManager::ExecuteScene();
	}

	return 0;
}