#include "mainmenu.h"
#include "../rectanglebuffers.h"
#include "../ecs.h"
#include "../globalenums.h"
#include "World1_2.h"

Mainmenu::Mainmenu()
{
}

void Mainmenu::Start()
{
	RectangleBuffers backgroundBuffers = RectangleBuffers(char(32), char(205), char(186), char(201), char(187), char(188), char(200), 3, 6, 8, 3);
	backgroundCanvas = Canvas(0, 0, 0, *backgroundBuffers.GetCharBuffer(), *backgroundBuffers.GetColorBuffer(), *backgroundBuffers.GetCollisionBuffer());

	mainCanvas = Canvas();
	mainCanvas.Copy(&backgroundCanvas);
	mainCanvas.SetBuffersToZero();

	RectangleBuffers textBoxBuffers = RectangleBuffers(char(32), '*', '*', '*', '*', '*', '*', 29, 6, 0, 3);
	textBox = Canvas(3, 0, 0, *textBoxBuffers.GetCharBuffer(), *textBoxBuffers.GetColorBuffer());
	textBox.PutString("PLAY", 1, 1, 0x0A, false);
	textBox.PutString("QUIT", 1, 4, 0x0A, false);

	textBox.PutString("WASD Move", 10, 1, 0x02, false);
	textBox.PutString("E    Interact", 10, 2, 0x02, false);
	textBox.PutString("By Crumblebit", textBox.GetWidth() - 14, 4, 0x0E, false);

	consoleQueue.insert(consoleQueue.begin(), "Welcome to Bark Boat Island!");

	ECS::Add<SpriteComponent>(PLAYER, SpriteComponent({ { char(34) } }, { {0x0F} },0,1,DrawLayers::TWO));
	ECS::Add<CollisionComponent>(PLAYER, CollisionComponent(CollisionTypes::DYNAMIC, { {true} }));
	ECS::Add<PositionComponent>(PLAYER, PositionComponent(1, 1));
	ECS::Add<MotionComponent>(PLAYER)->movementRate = 10.0f;
	ECS::Add<BackpackComponent>(PLAYER);
	ECS::Add<LifeComponent>(PLAYER, LifeComponent(2,2,100,100,0.5,0))->lives = 2;

	SpriteComponent* doorPlaySprite = ECS::Add<SpriteComponent>(MAINMENU_DOOR_PLAY);
	doorPlaySprite->sprite = { { char(179) } };
	doorPlaySprite->color = { {15} };
	doorPlaySprite->drawLayer = 1;
	ECS::Add<PositionComponent>(MAINMENU_DOOR_PLAY, PositionComponent(2, 1));
	ECS::Add<SceneComponent>(MAINMENU_DOOR_PLAY)->nextScene = WORLD1_2;
	ECS::Add<CollisionComponent>(MAINMENU_DOOR_PLAY)->collisionSetting = CollisionTypes::SOLID;

	SpriteComponent* doorQuitSprite = ECS::Add<SpriteComponent>(MAINMENU_DOOR_QUIT);
	doorQuitSprite->sprite = { { char(179) } };
	doorQuitSprite->color = { {15} };
	doorQuitSprite->drawLayer = 1;
	ECS::Add<PositionComponent>(MAINMENU_DOOR_QUIT, PositionComponent(2, 4));
	ECS::Add<SceneComponent>(MAINMENU_DOOR_QUIT)->nextScene = QUIT;
	ECS::Add<CollisionComponent>(MAINMENU_DOOR_QUIT)->collisionSetting = CollisionTypes::SOLID;

	SpriteComponent* playerSpawnpointSprite = ECS::Add<SpriteComponent>(PLAYER_SPAWNPOINT);
	playerSpawnpointSprite->sprite = { { '#' } };
	playerSpawnpointSprite->color = { {0x09} };
	playerSpawnpointSprite->drawLayer = DrawLayers::ONE;
	PositionComponent* playerSpawnpointPosition = ECS::Add<PositionComponent>(PLAYER_SPAWNPOINT);
	ECS::Add<ConsoleOutputComponent>(PLAYER_SPAWNPOINT)->output = { "You respawned at spawnpoint." };
	playerSpawnpointPosition->posX = ECS::Get<PositionComponent>(PLAYER)->posX;
	playerSpawnpointPosition->posY = ECS::Get<PositionComponent>(PLAYER)->posY;

	update = true;
	playerSpawnTime = Application::GetGlobalTimer();
}

void Mainmenu::Update()
{
	update = continueUpdate;
	Collision(&mainCanvas);
	ReadInput();
	PlayerInputMovement();
	//PlayerInputEscape();
	PlayerInteract();
	Movement(&mainCanvas);
	ExecuteOrder66();
	
	DrawEntities(&mainCanvas);
	DrawConsole();
	DrawCanvas(&mainCanvas);
	DrawCanvasOnCanvas(&mainCanvas, &backgroundCanvas);
	textBox.Draw();
}

void Mainmenu::End()
{
	killQueue.emplace_back(MAINMENU_DOOR_PLAY);
	killQueue.emplace_back(MAINMENU_DOOR_QUIT);
	ExecuteOrder66();

	backgroundCanvas.Erase();
	mainCanvas.Erase();
	textBox.Erase();

	if (nextScene == WORLD1_2)
	{
		ECS::Get<PositionComponent>(PLAYER)->posX = 1;
		ECS::Get<PositionComponent>(PLAYER)->posY = 1;
		SceneManager::RegisterScene(new World1_2());
	}
	else if (nextScene == QUIT)
	{
		SceneManager::RegisterScene(nullptr);
	}
}
