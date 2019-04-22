#include "game.h"

void Game::MainMenu()
{
	//Create room
	Scene scene("MainMenu", char(177), char(186), char(205), char(201), char(187), char(188), char(200), 0, 0, 2, 1);

	scene.CreateFromVector2D(Application::ReadFileToVector2D("Scenes/mainmenu.txt"));
	ECS::AssignScene(scene);



	ECS::Add<SpriteComponent>(PLAYER)->sprite = '#';
	ECS::Add<PositionComponent>(PLAYER, PositionComponent(1, 4));
	ECS::Add<CollisionComponent>(PLAYER)->collisionSetting = 0;
	ECS::Add<NearbyComponent>(PLAYER);
	ECS::Add<MotionComponent>(PLAYER);
	ECS::Add<InputComponent>(PLAYER);
	ECS::Add<BackpackComponent>(PLAYER);

	ECS::Get<PositionComponent>(PLAYER)->posX = 1;
	ECS::Get<PositionComponent>(PLAYER)->posY = 4;

	ECS::Add<SpriteComponent>(MAINMENU_DOOR_PLAY)->sprite = char(179);
	ECS::Add<PositionComponent>(MAINMENU_DOOR_PLAY, PositionComponent(2,4));
	ECS::Add<SceneComponent>(MAINMENU_DOOR_PLAY)->nextScene = Scenes::WORLDONE;
	ECS::Add<CollisionComponent>(MAINMENU_DOOR_PLAY)->collisionSetting = 2;

	ECS::Add<SpriteComponent>(MAINMENU_DOOR_QUIT)->sprite = char(179);
	ECS::Add<PositionComponent>(MAINMENU_DOOR_QUIT, PositionComponent(2, 6));
	ECS::Add<SceneComponent>(MAINMENU_DOOR_QUIT)->nextScene = Scenes::QUIT;
	ECS::Add<CollisionComponent>(MAINMENU_DOOR_QUIT)->collisionSetting = 2;


	double tick = Application::GetGlobalTimer();
	double newTick;
	while (scene.GetIsPlaying())
	{
		newTick = Application::GetGlobalTimer();
		if (tick < newTick)
		{
			ECS::Systems::Input();
			ECS::Systems::Movement();
			ECS::Systems::ExecuteOrder66();
			ECS::Systems::Draw();
			scene.Draw();

			tick = newTick + 0.01;
		}
	}

	//Put entities in kill queue before next scene
	ECS::killQueue.emplace_back(MAINMENU_DOOR_PLAY);
	ECS::killQueue.emplace_back(MAINMENU_DOOR_QUIT);

	//Kill entities
	ECS::Systems::ExecuteOrder66();

	scene.Erase();
	this->currentScene = scene.GetNextName();
}