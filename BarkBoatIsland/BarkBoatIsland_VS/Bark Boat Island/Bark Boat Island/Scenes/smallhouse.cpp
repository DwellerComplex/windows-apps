#include "smallhouse.h"
#include "../canvas.h"
#include "../ecs.h"
#include "../globalenums.h"
#include "../rectanglebuffers.h"
#include "startup.h"
#include "mainmenu.h"

SmallHouse::SmallHouse()
{
}

void SmallHouse::Start()
{
	std::vector<std::vector<char>> mapChars = {
		{char(201), char(205), char(205), char(205), char(205), char(205), char(187)},
		{char(186), char(32), char(32), char(32), char(32), char(32), char(186)},
		{char(186), char(32), char(32), char(32), char(32), char(32), char(186)},
		{char(200), char(187), char(32), char(32), char(32), char(32), char(186)},
		{char(32), char(186), char(32), char(32), char(32), char(32), char(186)},
		{char(201), char(188), char(32), char(32), char(32), char(32), char(186)},
		{char(186), char(32), char(32), char(32), char(32), char(32), char(186)},
		{char(186), char(32), char(32), char(32), char(32), char(32), char(186)},
		{char(186), char(32), char(32), char(32), char(32), char(32), char(186)},
		{char(186), char(32), char(32), char(32), char(32), char(32), char(186)},
		{char(200), char(205), char(205), char(187), char(32), char(32), char(186)},
		{char(32), char(32), char(32), char(200), char(205), char(205), char(188)}
	};

	std::vector<std::vector<short>> mapColors = {
		{15, 15, 15, 15, 15, 15, 15},
		{15, 0, 0, 0, 0, 0, 15},
		{15, 0, 0, 0, 0, 0, 15},
		{15, 15, 0, 0, 0, 0, 15},
		{0, 15, 0, 0, 0, 0, 15},
		{15, 15, 0, 0, 0, 0, 15},
		{15, 0, 0, 0, 0, 0, 15},
		{15, 0, 0, 0, 0, 0, 15},
		{15, 0, 0, 0, 0, 0, 15},
		{15, 0, 0, 0, 0, 0, 15},
		{15, 15, 15, 15, 0, 0, 15},
		{0, 0, 0, 15, 15, 15, 15}
	};
	std::vector<std::vector<short>> mapCollisions = {
		{3, 3, 3, 3, 3, 3, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{3, 3, 0, 0, 0, 0, 3},
		{0, 3, 0, 0, 0, 0, 3},
		{3, 3, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{3, 3, 3, 3, 0, 0, 3},
		{0, 0, 0, 3, 3, 3, 3}
	};

	Application::TransformVector2D(mapChars);
	Application::TransformVector2D(mapColors);
	Application::TransformVector2D(mapCollisions);
	backgroundCanvas = new Canvas(1, 1, 1, mapChars, mapColors, mapCollisions);

	mainCanvas = new Canvas();
	mainCanvas->Copy(backgroundCanvas);
	mainCanvas->SetBuffersToZero();

	RectangleBuffers playerBackpackBuffers = RectangleBuffers(char(32), char(205), char(186), char(201), char(187), char(188), char(200), 20, Application::GetConsoleHeight() - 8, 8, 3);
	playerBackpack = new Canvas(Application::GetConsoleWidth() - 20, 0, 0, *playerBackpackBuffers.GetCharBuffer(), *playerBackpackBuffers.GetColorBuffer());
	playerBackpack->PutString("BACKPACK", 1, 1, 95, true, ' ', 95);

	RectangleBuffers consoleBuffers = RectangleBuffers(char(32), char(205), char(186), char(201), char(187), char(188), char(200), Application::GetConsoleWidth(), 8, 8, 3);
	console = new Canvas(0, Application::GetConsoleHeight() - 8, 0, *consoleBuffers.GetCharBuffer(), *consoleBuffers.GetColorBuffer());

	ECS::Get<SpriteComponent>(PLAYER_SPAWNPOINT)->isActive = true;
	ECS::Get<PositionComponent>(PLAYER_SPAWNPOINT)->posX = ECS::Get<PositionComponent>(PLAYER)->posX;
	ECS::Get<PositionComponent>(PLAYER_SPAWNPOINT)->posY = ECS::Get<PositionComponent>(PLAYER)->posY;

	SpriteComponent* keySprite = ECS::Add<SpriteComponent>(SMALLHOUSE_SILVER_KEY);
	keySprite->sprite = { { char(235) } };
	keySprite->color = { {0x0F} };
	keySprite->drawLayer = DrawLayers::ONE;
	ECS::Add<ConsoleOutputComponent>(SMALLHOUSE_SILVER_KEY)->output = { "Picked up Silver Key." };
	ECS::Add<PositionComponent>(SMALLHOUSE_SILVER_KEY, PositionComponent(1, 8));
	ECS::Add<CollisionComponent>(SMALLHOUSE_SILVER_KEY, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<BackpackItemComponent>(SMALLHOUSE_SILVER_KEY, BackpackItemComponent(SILVER_KEY));

	SpriteComponent* doorStartupSprite = ECS::Add<SpriteComponent>(SMALLHOUSE_DOOR_STARTUP);
	doorStartupSprite->sprite = { { char(179) } };
	doorStartupSprite->color = { {15} };
	doorStartupSprite->drawLayer = 1;
	ECS::Add<PositionComponent>(SMALLHOUSE_DOOR_STARTUP, PositionComponent(6, 2));
	ECS::Add<SceneComponent>(SMALLHOUSE_DOOR_STARTUP)->nextScene = STARTUP;
	ECS::Add<CollisionComponent>(SMALLHOUSE_DOOR_STARTUP)->collisionSetting = CollisionTypes::SOLID;

	update = true;
	playerSpawnTime = Application::GetGlobalTimer();
}

void SmallHouse::Update()
{
	update = continueUpdate;

	Collision(mainCanvas);
	Input();
	PlayerInputEscape();
	PlayerInputMovement();
	PlayerInteractBackpack(playerBackpack, console);
	PlayerInteractDoors();
	PlayerRespawn(console);
	Movement(mainCanvas);
	ExecuteOrder66();

	DrawEntities(mainCanvas);
	DrawConsole(console);
	DrawPlayerBackpack(playerBackpack);
	DrawMainCanvas(mainCanvas);
	DrawCanvasOnMain(mainCanvas, backgroundCanvas);
}

void SmallHouse::End()
{
	killQueue.emplace_back(SMALLHOUSE_DOOR_STARTUP);
	ExecuteOrder66();

	backgroundCanvas->Erase();
	mainCanvas->Erase();
	playerBackpack->Erase();
	console->Erase();

	delete mainCanvas;
	delete backgroundCanvas;
	delete playerBackpack;
	delete console;

	if (nextScene == MAINMENU)
	{
		SceneManager::RegisterScene(new Mainmenu());
		ECS::Get<PositionComponent>(PLAYER)->posX = 1;
		ECS::Get<PositionComponent>(PLAYER)->posY = 1;
	}
	if (nextScene == STARTUP)
	{
		ECS::Get<PositionComponent>(PLAYER)->posX = 8;
		ECS::Get<PositionComponent>(PLAYER)->posY = 3;
		SceneManager::RegisterScene(new Startup());
	}
}
