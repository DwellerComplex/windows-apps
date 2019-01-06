#include "game.h"
using namespace std;

void Game::Test()
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
	CollisionComponent keyCol;
	keyCol.collisionSetting = 3;
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
	CollisionComponent doorCol;
	doorCol.collisionSetting = 2;

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
	CollisionComponent door2Col;
	door2Col.collisionSetting = 2;

	theEntityComponentSystem.theEntityManager.addEntity(&door2);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&door2, &door2Sprite);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&door2, &door2Pos);
	theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&door2, &door2Output);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&door2, &door2Col);

	Entity merl("Merl");
	SpriteComponent merlSprite('#', 8);
	PositionComponent merlPos(2, 1);
	MotionComponent merlMotion;
	ConsoleOutputComponent merlOutput;
	NearbyComponent merlNearby;
	vector<string> out = {
		"Oh, you are early! Hello, I am in dire need of help.", 
		"I am Merl, not that such formalities really matter in these times hehe...", 
		"Anyway, this is my home, or rather, it was until... My wife...",
		"Sorry, doesn't matter hehe...",
		"These days I avoid this place. Pesky cockroaches wander the halls so be careful. They bite.",
		"But what am I saying! You are Fendal, the bold and brave!",
		"Please, the key is just behind these cockroaches. Should be no problem for... A hero to get. Hehehe..."
	};

	merlOutput = out;
	CollisionComponent merlCol;
	merlCol.collisionSetting = 2;

	theEntityComponentSystem.theEntityManager.addEntity(&merl);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&merl, &merlSprite);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&merl, &merlPos);
	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&merl, &merlMotion);
	theEntityComponentSystem.theComponentManagers.theConsoleOutputManager.addComponent(&merl, &merlOutput);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&merl, &merlCol);
	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&merl, &merlNearby);

	Entity obst;
	SpriteComponent obstSpr('X', 4);
	PositionComponent obstPos(7, 2);
	CollisionComponent obstCol;
	obstCol.collisionSetting = 1;
	MotionComponent obstMotion;
	obstMotion.right = 1;
	obstMotion.movementRate = 10.0f;
	NearbyComponent obstNearby;
	AttackComponent obstAtt;
	obstAtt.damage = 1;

	theEntityComponentSystem.theEntityManager.addEntity(&obst);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&obst, &obstSpr);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&obst, &obstPos);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&obst, &obstCol);
	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&obst, &obstMotion);
	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&obst, &obstNearby);
	theEntityComponentSystem.theComponentManagers.theAttackManager.addComponent(&obst, &obstAtt);

	vector<Entity> obstacles;
	obstacles.push_back(obst);

	Entity obst2;
	SpriteComponent obstSpr2('X', 4);
	PositionComponent obstPos2(7, 4);
	CollisionComponent obstCol2;
	obstCol2.collisionSetting = 1;
	MotionComponent obstMotion2;
	obstMotion2.right = 1;
	obstMotion2.movementRate = 10.0f;
	NearbyComponent obstNearby2;
	AttackComponent obstAtt2;
	obstAtt2.damage = 1;

	theEntityComponentSystem.theEntityManager.addEntity(&obst2);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&obst2, &obstSpr2);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&obst2, &obstPos2);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&obst2, &obstCol2);
	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&obst2, &obstMotion2);
	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&obst2, &obstNearby2);
	theEntityComponentSystem.theComponentManagers.theAttackManager.addComponent(&obst2, &obstAtt2);

	obstacles.push_back(obst2);


	Entity obst3;
	SpriteComponent obstSpr3('X', 4);
	PositionComponent obstPos3(13, 3);
	CollisionComponent obstCol3;
	obstCol3.collisionSetting = 1;
	MotionComponent obstMotion3;
	obstMotion3.right = 1;
	obstMotion3.movementRate = 10.0f;
	NearbyComponent obstNearby3;
	AttackComponent obstAtt3;
	obstAtt3.damage = 1;

	theEntityComponentSystem.theEntityManager.addEntity(&obst3);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&obst3, &obstSpr3);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&obst3, &obstPos3);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&obst3, &obstCol3);
	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&obst3, &obstMotion3);
	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&obst3, &obstNearby3);
	theEntityComponentSystem.theComponentManagers.theAttackManager.addComponent(&obst3, &obstAtt3);

	obstacles.push_back(obst3);

	Entity obst4;
	SpriteComponent obstSpr4('X', 4);
	PositionComponent obstPos4(13, 5);
	CollisionComponent obstCol4;
	obstCol4.collisionSetting = 1;
	MotionComponent obstMotion4;
	obstMotion4.right = 1;
	obstMotion4.movementRate = 10.0f;
	NearbyComponent obstNearby4;
	AttackComponent obstAtt4;
	obstAtt4.damage = 1;

	theEntityComponentSystem.theEntityManager.addEntity(&obst4);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(&obst4, &obstSpr4);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(&obst4, &obstPos4);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(&obst4, &obstCol4);
	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(&obst4, &obstMotion4);
	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(&obst4, &obstNearby4);
	theEntityComponentSystem.theComponentManagers.theAttackManager.addComponent(&obst4, &obstAtt4);

	obstacles.push_back(obst4);

	Entity obst5;
	SpriteComponent obstSpr5('X', 4);
	PositionComponent obstPos5(1, 7);
	CollisionComponent obstCol5;
	obstCol5.collisionSetting = 1;
	MotionComponent obstMotion5;
	obstMotion5.right = 1;
	obstMotion5.movementRate = 5.0f;
	NearbyComponent obstNearby5;
	AttackComponent obstAtt5;
	obstAtt5.damage = 1;

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
			if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obstacles[i].id)->posX == 13)
			{
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i].id)->right = 0;
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i].id)->left = 1;
			}
			else if (theEntityComponentSystem.theComponentManagers.thePositionManager.getComponent(obstacles[i].id)->posX == 7)
			{
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i].id)->right = 1;
				theEntityComponentSystem.theComponentManagers.theMotionManager.getComponent(obstacles[i].id)->left = 0;
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
		else if(merlPos.posY == 4 && merlPos.posX == 1 && theEntityComponentSystem.theEntityManager.getEntity(merl.id) != nullptr)
		{
			room.DrawSprite(room.GetFloor(), merlPos.posX, merlPos.posY,3);
			theEntityComponentSystem.theEntityManager.destroyEntity(theEntityComponentSystem.theEntityManager.getEntity(merl.id));
			int i;
		}
	}

	theConsolePanel->console->BackupCreate();
	theInventoryPanel->inventory->BackupCreate();

	theEntityComponentSystem.theEntityManager.destroyEntity(&obst);
	theEntityComponentSystem.theEntityManager.destroyEntity(&door);

	room.Erase();
	this->currentRoom = room.GetNextName();

	playerMotion->footprint = char();

	if (room.GetNextName() == "MainMenu")
	{
		playerPosition->posX = 1;
		playerPosition->posY = 4;
	}
}