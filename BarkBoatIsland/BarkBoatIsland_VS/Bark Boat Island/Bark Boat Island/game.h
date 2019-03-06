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

	void MainMenu();
	void WorldOne();
	void Hall();

	enum Scenes
	{
		QUIT,
		MAINMENU,
		WORLDONE,
		NUMBER_OF_SCENES
	};

private:
	short currentScene;

	const enum Entities
	{
		PLAYER = 1,

		//_________________mainmenu_________________//
		MAINMENU_DOOR_PLAY,
		MAINMENU_DOOR_QUIT,
		MAINMENU_KEY,
		NUMBER_OF_ENTITIES
	};

	const enum BackPackItemTypes
	{
		GOLD_KEY = 1,
		SILVER_KEY,
		NUMBER_OF_TYPES
	};
};