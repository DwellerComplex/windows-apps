//#include <vld.h> 
#include "Scenes/mainmenu.h"

int main(int argc, const char** argv)
{
	//Initial system setup

	Application::SetFontEncoding(437);
	Application::SetTitle("Bark Boat Island");
	Application::SetFontSize(16, 16);
	Application::SetConsoleScreenBuffer();
	Application::SetConsoleSize(528, 570); //32 x 32
	Application::SetCursorPosition(0, 0);
	Application::ShowConsoleCursor(false);
	Application::StartGlobalTimer();

	SceneManager::RegisterScene(new Mainmenu());

	while (SceneManager::IsRunning())
	{
		SceneManager::ExecuteScene();
	}

	SceneManager::EraseScene();

	//std::cin.get();
	return 0;
}