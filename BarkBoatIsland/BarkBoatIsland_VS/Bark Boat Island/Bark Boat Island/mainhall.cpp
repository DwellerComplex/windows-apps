#include "game.h"
using namespace std;

void CreateObst(ECS* theEntityComponentSystem, int x, int y, vector<Entity*>* arr, bool down)
{
	Entity* obst = new Entity;
	SpriteComponent* obstSprite = new SpriteComponent('O', 4);
	PositionComponent* obstPos = new PositionComponent(x, y);
	CollisionComponent* obstCollision = new CollisionComponent;
	obstCollision->collisionSetting = 1;
	MotionComponent* obstMotion = new MotionComponent;

	if (!down) {
		obstMotion->down = 1;
	}
	else
	{
		obstMotion->up = 1;
	}
	
	obstMotion->movementRate = 20.0f;
	NearbyComponent* obstNearby = new NearbyComponent;
	AttackComponent* obstAtt = new AttackComponent;
	obstAtt->damage = 1;

	theEntityComponentSystem->theEntityManager.addEntity(obst);
	theEntityComponentSystem->theComponentManagers.theSpriteManager.addComponent(obst, obstSprite);
	theEntityComponentSystem->theComponentManagers.thePositionManager.addComponent(obst, obstPos);
	theEntityComponentSystem->theComponentManagers.theCollisionManager.addComponent(obst, obstCollision);
	theEntityComponentSystem->theComponentManagers.theMotionManager.addComponent(obst, obstMotion);
	theEntityComponentSystem->theComponentManagers.theNearbyManager.addComponent(obst, obstNearby);
	theEntityComponentSystem->theComponentManagers.theAttackManager.addComponent(obst, obstAtt);

	arr->push_back(obst);
}

void Game::MainHall()
{
	//Application and ecs controls
	Application& app = Application::get_instance();

	theInventoryPanel->inventory->BackupLoad();
	theConsolePanel->console->BackupLoad();

	//Create room
	Room room("MainHall", char(177), char(186), char(205), char(201), char(187), char(188), char(200), 50, 10, 25, 2, 3, 10);
	room.CreateAsSquare();
	theInventoryPanel->setTitle("Main Hall");

	Entity door;
	SpriteComponent waterSceneDoorSprite(char(179));
	PositionComponent waterSceneDoorPos(0, 1);
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
	PositionComponent keyPos(46, 7);
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

	vector<Entity*> obstacles;
	CreateObst(&theEntityComponentSystem,  2, 2, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 3, 3, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 4, 4, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 5, 5, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 6, 6, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 7, 7, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 8, 8, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 9, 7, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 10, 6, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 11, 5, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 12, 4, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 13, 3, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 14, 2, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 15, 1, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 16, 2, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 17, 3, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 18, 4, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 19, 5, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 20, 6, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 21, 7, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 22, 8, &obstacles, true);
	CreateObst(&theEntityComponentSystem, 23, 7, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 24, 6, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 25, 5, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 26, 4, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 27, 3, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 28, 2, &obstacles, false);
	CreateObst(&theEntityComponentSystem, 29, 1, &obstacles, false);

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


		for (int i = 0; i < obstacles.size(); i++)
		{
			if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obstacles[i]->id)->posY == 8)
			{
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->down = 0;
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->up = 1;
			}
			else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obstacles[i]->id)->posY == 1)
			{
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->down = 1;
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->up = 0;
			}
		}

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