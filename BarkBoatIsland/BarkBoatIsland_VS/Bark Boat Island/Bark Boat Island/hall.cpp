#include "game.h"
//using namespace std;
//
//void CreateObst(ECS* theEntityComponentSystem, int x, int y, vector<Entity*>* arr, bool left, int footprColor)
//{
//	Entity* obst = new Entity;
//	theEntityComponentSystem->theEntityManager.addEntity(obst);
//	theEntityComponentSystem->theComponentManagers.theSpriteManager.addComponent(obst, new SpriteComponent('O', 4));
//	theEntityComponentSystem->theComponentManagers.thePositionManager.addComponent(obst, new PositionComponent(x, y));
//	theEntityComponentSystem->theComponentManagers.theCollisionManager.addComponent(obst, new CollisionComponent(1));
//	theEntityComponentSystem->theComponentManagers.theNearbyManager.addComponent(obst, new NearbyComponent);
//	theEntityComponentSystem->theComponentManagers.theAttackManager.addComponent(obst, new AttackComponent(1));
//
//	if (!left) {
//		theEntityComponentSystem->theComponentManagers.theMotionManager.addComponent(obst, new MotionComponent(0,0,0,1,10.0f, footprColor));
//	}
//	else
//	{
//		theEntityComponentSystem->theComponentManagers.theMotionManager.addComponent(obst, new MotionComponent(0, 0, 1, 0, 10.0f, footprColor));
//	}
//
//	arr->push_back(obst);
//}
//
void Game::Hall()
{
//	theInventoryPanel->inventory->BackupLoad();
//	theConsolePanel->console->BackupLoad();
//
//	checkpointPosition->posX = playerPosition->posX;
//	checkpointPosition->posY = playerPosition->posY;
//
//	//Create room
//	Room room("Hall", char(177), char(186), char(205), char(201), char(187), char(188), char(200), 0, 0, 0, 0, 3, 9);
//	room.CreateFromVector2D(Application::ReadFileToVector2D("Scenes/mainhall.txt"));
//	theInventoryPanel->setTitle("Hall");
//	
//	if (theEntityComponentSystem.theEntityManager.getEntity(3) == nullptr)
//	{
//		Entity* key = new Entity(3, "Yellow Key");
//		theEntityComponentSystem.theEntityManager.addEntity(key);
//		theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(key, new SpriteComponent(char(235), 14));
//		theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(key, new PositionComponent(2, 9));
//		theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(key, new CollisionComponent(3));
//		theEntityComponentSystem.theComponentManagers.theInventoryItemManager.addComponent(key, new InventoryItemComponent);
//		theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(key, new ConsoleOutputComponent("Picked up Yellow Key."));
//		theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(key, new NearbyComponent);
//	}
//
//	Entity door;
//	theEntityComponentSystem.theEntityManager.addEntity(&door);
//	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&door, new SpriteComponent(char(179), 14));
//	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&door, new PositionComponent(14, 1));
//	theEntityComponentSystem.theComponentManagers.theSceneManager.addComponent(&door, new SceneComponent("MainMenu"));
//	theEntityComponentSystem.theComponentManagers.theLockManager.addComponent(&door, new LockComponent("Yellow Key"));
//	theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&door, new ConsoleOutputComponent("Locked"));
//	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&door, new CollisionComponent(2));
//
//	Entity door2;
//	theEntityComponentSystem.theEntityManager.addEntity(&door2);	
//	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&door2, new SpriteComponent(char(179), 8));
//	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&door2, new PositionComponent(0,4));
//	theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&door2, new ConsoleOutputComponent("Locked"));
//	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&door2, new CollisionComponent(2));
//
//	Entity merl("Merl");
//	SpriteComponent merlSprite('#', 8);
//	PositionComponent merlPos(2, 1);
//	MotionComponent merlMotion;
//	merlMotion.footprintColor = room.GetFloorColor();
//	ConsoleOutputComponent merlOutput;
//	NearbyComponent merlNearby;
//	vector<string> out = {
//		//"Oh, you are early! Hello, I am in dire need of help.", I'm Merl... 
//		"Hello there.",
//		"My neck is... killing me right now, you know...",
//		"Anyway, she should be here somewhere.",
//		"..."
//	};
//
//	merlOutput = out;
//	CollisionComponent merlCol(2);
//
//	theEntityComponentSystem.theEntityManager.addEntity(&merl);
//	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&merl, &merlSprite);
//	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&merl, &merlPos);
//	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&merl, &merlMotion);
//	theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&merl, &merlOutput);
//	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&merl, &merlCol);
//	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&merl, &merlNearby);
//
//
//	vector<Entity*> obstacles;
//	CreateObst(&theEntityComponentSystem, 7, 2, &obstacles, false, room.GetFloorColor());
//	CreateObst(&theEntityComponentSystem, 7, 4, &obstacles, false, room.GetFloorColor());
//	CreateObst(&theEntityComponentSystem, 13, 3, &obstacles, true, room.GetFloorColor());
//	CreateObst(&theEntityComponentSystem, 13, 5, &obstacles, true, room.GetFloorColor());
//
//	Entity obst5;
//	theEntityComponentSystem.theEntityManager.addEntity(&obst5);
//	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&obst5, new SpriteComponent('X', 4));
//	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&obst5, new PositionComponent(1, 7));
//	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&obst5, new CollisionComponent(1));
//	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&obst5, new MotionComponent(0, 0, 0, 1, 5.0f, room.GetFloorColor()));
//	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&obst5, new NearbyComponent);
//	theEntityComponentSystem.theComponentManagers.theAttackManager.addComponent(&obst5, new AttackComponent(1));
//
//	while (room.GetIsPlaying())
//	{
//		theEntityComponentSystem.Input();
//		theEntityComponentSystem.MovementInput();
//		theEntityComponentSystem.Movement(room);
//		theEntityComponentSystem.Attack(room);
//		theEntityComponentSystem.Platform();
//		theEntityComponentSystem.Interact(room, theConsolePanel);
//		theEntityComponentSystem.Display(room);
//		theInventoryPanel->draw();
//		theConsolePanel->draw();
//		room.Draw();
//
//		for (int i = 0; i < obstacles.size(); i++)
//		{
//			if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obstacles[i]->id)->posX == 13)
//			{
//				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->right = 0;
//				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->left = 1;
//			}
//			else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obstacles[i]->id)->posX == 7)
//			{
//				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->right = 1;
//				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->left = 0;
//			}
//		}
//
//		if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posX == 1 &&
//			theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posY == 7)
//		{
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->right = 1;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->left = 0;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->up = 0;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->down = 0;
//		}
//		else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posX == 6 &&
//			theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posY == 7)
//		{
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->right = 0;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->left = 0;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->up = 0;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->down = 1;
//		}
//		else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posX == 6 &&
//			theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posY == 10)
//		{
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->right = 0;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->left = 1;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->up = 0;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->down = 0;
//		}
//		else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posX == 1 &&
//			theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posY == 10)
//		{
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->right = 0;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->left = 0;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->up = 1;
//			theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obst5.id)->down = 0;
//		}
//
//		if (this->playerPosition->posY > 6 && merlPos.posY < 4 && merlPos.posX > 1) {
//			merlMotion.left = true;
//			merlMotion.down = true;
//			merlMotion.movementRate = 2.0;
//		}
//		if (merlPos.posY == 4 && merlPos.posX == 1 && theEntityComponentSystem.theEntityManager.getEntity(merl.id) != nullptr)
//		{
//			room.DrawSprite(room.GetFloor(), merlPos.posX, merlPos.posY, 3);
//			theEntityComponentSystem.theEntityManager.destroyEntity(&merl);
//		}
//	}
//
//	theConsolePanel->console->BackupCreate();
//	theInventoryPanel->inventory->BackupCreate();
//
//
//	theEntityComponentSystem.theEntityManager.destroyEntity(&door);
//	theEntityComponentSystem.theEntityManager.destroyEntity(&door2);
//	theEntityComponentSystem.theEntityManager.destroyEntity(&obst5);
//	theEntityComponentSystem.theEntityManager.destroyEntity(&merl);
//	for (int i = 0; i < obstacles.size(); i++)
//	{
//		theEntityComponentSystem.theEntityManager.destroyEntity(obstacles[i]);
//	}
//
//	room.Erase();
//	this->currentRoom = room.GetNextName();
//
//	//playerMotion->footprint = char();
//
//	if (room.GetNextName() == "MainMenu")
//	{
//		playerPosition->posX = 1;
//		playerPosition->posY = 4;
//	}
}