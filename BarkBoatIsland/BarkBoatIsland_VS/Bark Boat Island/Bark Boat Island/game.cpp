#include "game.h"

Game::Game()
{

}

void Game::PlayScene()
{
	//if (currentScene == MAINMENU)
	//{
	//	this->MainMenu();
	//}
	//else if (currentScene == WORLDONE)
	//{
	//	this->WorldOne();
	//}
	//else
	//{
	//	currentScene = QUIT;
	//}
}

void Game::SetCurrentScene(short const room)
{
	currentScene = room;
}