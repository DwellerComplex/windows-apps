#include "game.h"
using namespace std;

void CreateObst(ECS* theEntityComponentSystem, int x, int y, vector<Entity*>* arr, bool left, int footprColor)
{
	Entity* obst = new Entity;
	SpriteComponent* obstSprite = new SpriteComponent('O', 4);
	PositionComponent* obstPos = new PositionComponent(x, y);
	CollisionComponent* obstCollision = new CollisionComponent(1);
	MotionComponent* obstMotion = new MotionComponent;

	if (!left) {
		obstMotion->right = 1;
	}
	else
	{
		obstMotion->left = 1;
	}

	obstMotion->movementRate = 10.0f;
	obstMotion->footprintColor = footprColor;
	NearbyComponent* obstNearby = new NearbyComponent;
	AttackComponent* obstAtt = new AttackComponent(1);

	theEntityComponentSystem->theEntityManager.addEntity(obst);
	theEntityComponentSystem->theComponentManagers.theSpriteManager.addComponent(obst, obstSprite);
	theEntityComponentSystem->theComponentManagers.thePositionManager.addComponent(obst, obstPos);
	theEntityComponentSystem->theComponentManagers.theCollisionManager.addComponent(obst, obstCollision);
	theEntityComponentSystem->theComponentManagers.theMotionManager.addComponent(obst, obstMotion);
	theEntityComponentSystem->theComponentManagers.theNearbyManager.addComponent(obst, obstNearby);
	theEntityComponentSystem->theComponentManagers.theAttackManager.addComponent(obst, obstAtt);

	arr->push_back(obst);
}

void Game::Hall()
{
	//Application and ecs controls
	Application& app = Application::get_instance();

	theInventoryPanel->inventory->BackupLoad();
	theConsolePanel->console->BackupLoad();

	//Create room
	Room room("Hall", char(177), char(186), char(205), char(201), char(187), char(188), char(200), 0, 0, 0, 0, 3, 9);
	room.CreateFromVector2D(app.ReadFileToVector2D("Scenes/mainhall.txt"));
	theInventoryPanel->setTitle("Hall");


	Entity key("Yellow Key");
	SpriteComponent keySpr(char(235), 14);
	PositionComponent keyPos(2, 9);
	CollisionComponent keyCol(3);
	InventoryItemComponent keyInvItem;
	ConsoleOutputComponent keyOut("Picked up Yellow Key.");
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

	Entity door;
	SpriteComponent doorSprite(char(179), 14);
	PositionComponent doorPos(14, 1);
	SceneComponent doorRoom("MainMenu");
	LockComponent doorLock("Yellow Key");
	ConsoleOutputComponent doorOutput("Locked");
	CollisionComponent doorCol(2);

	theEntityComponentSystem.theEntityManager.addEntity(&door);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&door, &doorSprite);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&door, &doorPos);
	theEntityComponentSystem.theComponentManagers.theSceneManager.addComponent(&door, &doorRoom);
	theEntityComponentSystem.theComponentManagers.theLockManager.addComponent(&door, &doorLock);
	theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&door, &doorOutput);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&door, &doorCol);

	Entity door2;
	SpriteComponent door2Sprite(char(179), 8);
	PositionComponent door2Pos(0, 4);
	ConsoleOutputComponent door2Output("Locked");
	CollisionComponent door2Col(2);

	theEntityComponentSystem.theEntityManager.addEntity(&door2);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&door2, &door2Sprite);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&door2, &door2Pos);
	theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&door2, &door2Output);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&door2, &door2Col);

	Entity merl("Merl");
	SpriteComponent merlSprite('#', 8);
	PositionComponent merlPos(2, 1);
	MotionComponent merlMotion;
	merlMotion.footprintColor = room.GetFloorColor();
	ConsoleOutputComponent merlOutput;
	NearbyComponent merlNearby;
	vector<string> out = {
		//"Oh, you are early! Hello, I am in dire need of help.", I'm Merl... 
		"Hello there.",
		"My neck is... killing me right now, you know...",
		"Anyway, she should be here somewhere.",
		"..."
	};

	merlOutput = out;
	CollisionComponent merlCol(2);

	theEntityComponentSystem.theEntityManager.addEntity(&merl);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&merl, &merlSprite);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&merl, &merlPos);
	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&merl, &merlMotion);
	theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&merl, &merlOutput);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&merl, &merlCol);
	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&merl, &merlNearby);


	vector<Entity*> obstacles;
	CreateObst(&theEntityComponentSystem, 7, 2, &obstacles, false, room.GetFloorColor());
	CreateObst(&theEntityComponentSystem, 7, 4, &obstacles, false, room.GetFloorColor());
	CreateObst(&theEntityComponentSystem, 13, 3, &obstacles, true, room.GetFloorColor());
	CreateObst(&theEntityComponentSystem, 13, 5, &obstacles, true, room.GetFloorColor());

	Entity obst5;
	SpriteComponent obstSpr5('X', 4);
	PositionComponent obstPos5(1, 7);
	CollisionComponent obstCol5(1);
	MotionComponent obstMotion5(0,0,0,1,5.0f,room.GetFloorColor());
	NearbyComponent obstNearby5;
	AttackComponent obstAtt5(1);

	theEntityComponentSystem.theEntityManager.addEntity(&obst5);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&obst5, &obstSpr5);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&obst5, &obstPos5);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&obst5, &obstCol5);
	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&obst5, &obstMotion5);
	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&obst5, &obstNearby5);
	theEntityComponentSystem.theComponentManagers.theAttackManager.addComponent(&obst5, &obstAtt5);

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
			if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obstacles[i]->id)->posX == 13)
			{
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->right = 0;
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->left = 1;
			}
			else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obstacles[i]->id)->posX == 7)
			{
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->right = 1;
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i]->id)->left = 0;
			}
		}

		if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posX == 1 &&
			theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posY == 7)
		{
			obstMotion5.right = 1;
			obstMotion5.left = 0;
			obstMotion5.up = 0;
			obstMotion5.down = 0;
		}
		else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posX == 6 &&
			theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posY == 7)
		{
			obstMotion5.right = 0;
			obstMotion5.left = 0;
			obstMotion5.up = 0;
			obstMotion5.down = 1;
		}
		else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posX == 6 &&
			theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posY == 10)
		{
			obstMotion5.right = 0;
			obstMotion5.left = 1;
			obstMotion5.up = 0;
			obstMotion5.down = 0;
		}
		else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posX == 1 &&
			theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obst5.id)->posY == 10)
		{
			obstMotion5.right = 0;
			obstMotion5.left = 0;
			obstMotion5.up = 1;
			obstMotion5.down = 0;
		}

		if (this->playerPosition->posY > 6 && merlPos.posY < 4 && merlPos.posX > 1) {
			merlMotion.left = true;
			merlMotion.down = true;
			merlMotion.movementRate = 2.0;
		}
		else if (merlPos.posY == 4 && merlPos.posX == 1 && theEntityComponentSystem.theEntityManager.getEntity(merl.id) != nullptr)
		{
			room.DrawSprite(room.GetFloor(), merlPos.posX, merlPos.posY, 3);
			theEntityComponentSystem.theEntityManager.destroyEntity(theEntityComponentSystem.theEntityManager.getEntity(merl.id));
		}
	}

	theConsolePanel->console->BackupCreate();
	theInventoryPanel->inventory->BackupCreate();


	theEntityComponentSystem.theEntityManager.destroyEntity(&door);
	theEntityComponentSystem.theEntityManager.destroyEntity(&obst5);
	for (int i = 0; i < obstacles.size(); i++)
	{
		theEntityComponentSystem.theEntityManager.destroyEntity(obstacles[i]);
	}

	room.Erase();
	this->currentRoom = room.GetNextName();

	//playerMotion->footprint = char();

	if (room.GetNextName() == "MainMenu")
	{
		playerPosition->posX = 1;
		playerPosition->posY = 4;
	}
}