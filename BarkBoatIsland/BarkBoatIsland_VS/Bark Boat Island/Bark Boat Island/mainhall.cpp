#include "game.h"
using namespace std;

void Game::MainHall()
{
	//Application and ecs controls
	Application& app = Application::get_instance();

	theInventoryPanel->inventory->BackupLoad();
	theConsolePanel->console->BackupLoad();

	//Create room
	Room room("MainHall", char(177), char(186), char(205), char(201), char(187), char(188), char(200), 7, 30, 25, 2, 3, 10);
	room.CreateAsSquare();
	theInventoryPanel->setTitle("Main Hall");

	Entity door;
	SpriteComponent waterSceneDoorSprite(char(179));
	PositionComponent waterSceneDoorPos(0, 10);
	SceneComponent waterSceneDoorRoom("MainMenu");
	LockComponent waterSceneDoorLock("Key here");
	ConsoleOutputComponent waterSceneDoorOutput("WaterScene Locked");

	theEntityComponentSystem.theEntityManager.addEntity(&door);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&door, &waterSceneDoorSprite);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&door, &waterSceneDoorPos);
	theEntityComponentSystem.theComponentManagers.theSceneManager.addComponent(&door, &waterSceneDoorRoom);
	theEntityComponentSystem.theComponentManagers.theLockManager.addComponent(&door, &waterSceneDoorLock);
	theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&door, &waterSceneDoorOutput);

	Entity platform;
	SpriteComponent platformSprite('O', 4);
	PositionComponent platformPos(1, 5);
	PlatformComponent platformPlatform;
	CollisionComponent platformCollision;
	platformCollision.collisionSetting = 1;
	MotionComponent platformMotion;
	platformMotion.down = 1;
	platformMotion.movementRate = 1.0f;
	NearbyComponent platformNearby;

	theEntityComponentSystem.theEntityManager.addEntity(&platform);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&platform, &platformSprite);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&platform, &platformPos);
	theEntityComponentSystem.theComponentManagers.thePlatformManager.addComponent(&platform, &platformPlatform);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&platform, &platformCollision);
	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&platform, &platformMotion);
	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&platform, &platformNearby);

	Entity key(3,"Key here");
	SpriteComponent keySpr(char(235));
	PositionComponent keyPos(2, 7);
	CollisionComponent keyCol;
	keyCol.collisionSetting = 3;
	InventoryItemComponent keyInvItem;
	ConsoleOutputComponent keyOut("Picked up key.");
	NearbyComponent keyNear;
	
	if (theEntityComponentSystem.theEntityManager.getEntity(key.id) == nullptr)
	{
		theEntityComponentSystem.theEntityManager.addEntity(&key);
		theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&key, &keySpr);
		theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&key, &keyPos);
		theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&key, &keyCol);
		theEntityComponentSystem.theComponentManagers.theInventoryItemManager.addComponent(&key, &keyInvItem);
		theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&key, &keyOut);
		theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&key, &keyNear);
	}

	while (room.GetIsPlaying())
	{
		theEntityComponentSystem.Input();
		theEntityComponentSystem.MovementInput();
		theEntityComponentSystem.Movement(room);
		theEntityComponentSystem.Attack(room);
		theEntityComponentSystem.Platform();
		theEntityComponentSystem.Interact(room, theConsolePanel);
		theEntityComponentSystem.Display(room);
		theInventoryPanel->draw();
		theConsolePanel->draw();
		room.Draw();
	}

	theConsolePanel->console->BackupCreate();
	theInventoryPanel->inventory->BackupCreate();

	theEntityComponentSystem.theEntityManager.destroyEntity(&door);
	theEntityComponentSystem.theEntityManager.destroyEntity(&platform);
	//theEntityComponentSystem.theEntityManager.destroyEntity(&key);

	room.Erase();
	this->currentRoom = room.GetNextName();

	playerMotion->footprint = char();

	if (room.GetNextName() == "MainMenu")
	{
		playerPosition->posX = 1;
		playerPosition->posY = 4;
	}
}