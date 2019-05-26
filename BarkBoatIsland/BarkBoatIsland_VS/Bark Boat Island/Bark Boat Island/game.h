#pragma once
#include <string>

#include "application.h"
#include "scene.h"
#include "ecs.h"

class Game
{
public:
	Game();
	void PlayScene();
	short const GetCurrentRoom() { return currentScene; };
	void SetCurrentScene(short const currentScene);

	//void MainMenu();
	//void WorldOne();
	//void Hall();

	enum Scenes
	{
		QUIT,
		MAINMENU,
		WORLDONE,
		NUMBER_OF_SCENES
	};

private:
	short currentScene;


};