#include "game.h"

void Game::MainMenu()
{
	theInventoryPanel->erase();
	theConsolePanel->erase();

	//Create room
	Room room("MainMenu", char(177), char(186), char(205), char(201), char(187), char(188), char(200), 0, 0, 2, 1);
	Application& app = Application::get_instance();

	room.CreateFromVector2D(app.ReadFileToVector2D("Scenes/mainmenu.txt")); 

	Entity mainHallDoor;
	SpriteComponent mainHallDoorSprite(char(179));
	PositionComponent mainHallDoorPos(2, 4);
	SceneComponent mainHallDoorNextRoom("Hall");

	theEntityComponentSystem.theEntityManager.addEntity(&mainHallDoor);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&mainHallDoor, &mainHallDoorSprite);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&mainHallDoor, &mainHallDoorPos);
	theEntityComponentSystem.theComponentManagers.theSceneManager.addComponent(&mainHallDoor, &mainHallDoorNextRoom);

	Entity quitDoor;
	SpriteComponent quitDoorSprite(char(179));
	PositionComponent quitDoorPos(2, 6);
	SceneComponent quitDoorNextRoom("Quit");

	theEntityComponentSystem.theEntityManager.addEntity(&quitDoor);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&quitDoor, &quitDoorSprite);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&quitDoor, &quitDoorPos);
	theEntityComponentSystem.theComponentManagers.theSceneManager.addComponent(&quitDoor, &quitDoorNextRoom);

	while (room.GetIsPlaying())
	{
		theEntityComponentSystem.Input();
		theEntityComponentSystem.MovementInput();
		theEntityComponentSystem.Interact(room, theConsolePanel);
		theEntityComponentSystem.Movement(room);
		theEntityComponentSystem.Display(room);
		room.Draw();
	}

	theEntityComponentSystem.theEntityManager.destroyEntity(&mainHallDoor);
	theEntityComponentSystem.theEntityManager.destroyEntity(&quitDoor);

	room.Erase();
	this->currentRoom = room.GetNextName();

	playerMotion->footprint = char();

	if (room.GetNextName() == "Hall")
	{
		playerPosition->posX = 13;
		playerPosition->posY = 1;
	}
}