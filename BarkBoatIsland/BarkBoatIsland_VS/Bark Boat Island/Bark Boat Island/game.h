#pragma once
#include <string>

#include "application.h"
#include "inventorypanel.h"
#include "consolepanel.h"
#include "room.h"
#include "ECS.h"
using namespace std;

class Game
{
public:
	Game();
	void PlayRoom();
	std::string const GetCurrentRoom() { return currentRoom; };
	void SetCurrentRoom(std::string currentRoom);

	void MainMenu();
	void MainHall();
private:
	std::string currentRoom;

	ECS theEntityComponentSystem;
	InventoryPanel* theInventoryPanel;
	ConsolePanel* theConsolePanel;

	Entity* player;
	NearbyComponent* playerNearby;
	PositionComponent* playerPosition;
	SpriteComponent* playerSprite;
	InputComponent* playerInput;
	MotionComponent* playerMotion;
	InventoryComponent* playerInventory;
	LifeComponent* playerLife;
	CollisionComponent* playerCollision;
};