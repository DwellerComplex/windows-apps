#include "game.h"

void Game::WorldOne()
{
	//Create room
	Scene scene("World One", char(177), char(186), char(205), char(201), char(187), char(188), char(200),10, 10, 0, 0, 2, 1);
	
	scene.CreateFromVector2D(Application::ReadFileToVector2D("Scenes/worldone.txt"));
	ECS::AssignScene(scene);

	ECS::Get<MotionComponent>(PLAYER)->footprintColor = scene.GetFloorColor();
	ECS::Get<PositionComponent>(PLAYER)->posX = 9;
	ECS::Get<PositionComponent>(PLAYER)->posY = 2;

	Scene PlayerBackpack("Backpack", ' ', char(186), char(205), char(201), char(187), char(188), char(200), 20, 20, Application::GetConsoleWidth() - 20, 0, 8, 3);

	PlayerBackpack.CreateAsSquare();
	PlayerBackpack.DrawString("BACKPACK", 1, 1,95, true, ' ', 95);

	PlayerBackpack.DrawString("Silver Keys: 0", 1, 3);
	PlayerBackpack.DrawString("Gold Keys:   0", 1, 4);

	//Keep keys between scenes
	if (!ECS::Get<BackpackItemComponent>(MAINMENU_KEY))
	{
		ECS::Add<SpriteComponent>(MAINMENU_KEY, SpriteComponent(char(235), 14));
		ECS::Add<PositionComponent>(MAINMENU_KEY, PositionComponent(15, 2));
		ECS::Add<CollisionComponent>(MAINMENU_KEY)->collisionSetting = 2;
		ECS::Add<BackpackItemComponent>(MAINMENU_KEY)->type = SILVER_KEY;
	}

	ECS::Add<SpriteComponent>(MAINMENU_DOOR_PLAY)->sprite = char(179);
	ECS::Add<PositionComponent>(MAINMENU_DOOR_PLAY, PositionComponent(8, 2));
	ECS::Add<SceneComponent>(MAINMENU_DOOR_PLAY)->nextScene = Scenes::MAINMENU;
	ECS::Add<CollisionComponent>(MAINMENU_DOOR_PLAY)->collisionSetting = 2;
	ECS::Add<LockComponent>(MAINMENU_DOOR_PLAY)->key = SILVER_KEY;

	double tick = Application::GetGlobalTimer();
	while (scene.GetIsPlaying())
	{
		double const newTick = Application::GetGlobalTimer();
		if (tick < newTick)
		{
			ECS::Systems::Input();
			ECS::Systems::Movement();
			ECS::Systems::ExecuteOrder66();
			ECS::Systems::Draw();
			scene.Draw();
			
			int silverKeys = 0;
			for (int i = 0; i < ECS::Get<BackpackComponent>(PLAYER)->items.size(); i++)
			{
				if (ECS::Get<BackpackItemComponent>(ECS::Get<BackpackComponent>(PLAYER)->items[i])->type == SILVER_KEY) { silverKeys++; }
			}
			PlayerBackpack.DrawSprite('0' + silverKeys, 14, 3);

			PlayerBackpack.Draw();
			tick = newTick + 0.01;
		}
	}

	//Put entities in kill queue before next scene
	ECS::killQueue.emplace_back(MAINMENU_DOOR_PLAY);

	//Kill entities
	ECS::Systems::ExecuteOrder66();

	scene.Erase();
	PlayerBackpack.Erase();
	this->currentScene = scene.GetNextName();
}