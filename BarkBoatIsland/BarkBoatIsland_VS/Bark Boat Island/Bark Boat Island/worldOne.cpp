#include "game.h"

//Process input
void ProcessPlayerInput(Scene* scene)
{
	if (InputComponent* inputComponent = ECS::Get<InputComponent>(Entities::PLAYER))
	{
		if (MotionComponent* motionComponent = ECS::Get<MotionComponent>(Entities::PLAYER))
		{
			if (inputComponent->command == 'W')
			{
				motionComponent->up = 1;
			}
			if (inputComponent->command == 'A')
			{
				motionComponent->left = 1;
			}
			if (inputComponent->command == 'S')
			{
				motionComponent->down = 1;
			}
			if (inputComponent->command == 'D')
			{
				motionComponent->right = 1;
			}
		}

		if (NearbyComponent* nearbyComponent = ECS::Get<NearbyComponent>(Entities::PLAYER))
		{
			if (inputComponent->command == 'E')
			{
				if (BackpackComponent* backpackComponent = ECS::Get<BackpackComponent>(Entities::PLAYER))
				{
					for (int nbr = 0; nbr < nearbyComponent->neighbors.size(); nbr++)
					{
						if (BackpackItemComponent* backpackItemComponent = ECS::Get<BackpackItemComponent>(nearbyComponent->neighbors[nbr]))
						{
							//backpackComponent->items.emplace_back(nearbyComponent->nbrUp);
							PositionComponent* positionComponent = ECS::Get<PositionComponent>(nearbyComponent->neighbors[nbr]);
							scene->DrawSprite(scene->GetFloor(), positionComponent->posX, positionComponent->posY, scene->GetFloorColor());
							//Destroy<PositionComponent>(nearbyComponent->neighbors[nbr]);

							positionComponent->isActive = false;

							if (SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(nearbyComponent->neighbors[nbr]))
							{
								spriteComponent->isActive = false;
							}
							if (CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(nearbyComponent->neighbors[nbr]))
							{
								collisionComponent->isActive = false;
							}

							backpackComponent->items[backpackItemComponent->type]++;
						}

						if (SceneComponent* sceneComponent = ECS::Get<SceneComponent>(nearbyComponent->neighbors[nbr]))
						{
							if (LockComponent* lockComponent = ECS::Get<LockComponent>(nearbyComponent->neighbors[nbr]))
							{
								if (lockComponent->isActive)
								{
									for (int i = 0; i < backpackComponent->items.size(); i++)
									{
										if (backpackComponent->items[lockComponent->key])
										{
											scene->SetNextSceneName(sceneComponent->nextScene);
											scene->SetIsPlaying(false);
											backpackComponent->items[lockComponent->key]--;
											lockComponent->isActive = false;
											return;
											//Destroy<LockComponent>(nearbyComponent->neighbors[nbr]);
										}
									}
									return;
								}
							}
							scene->SetNextSceneName(sceneComponent->nextScene);
							scene->SetIsPlaying(false);
						}
					}
				}
			}
		}
	}
}


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

	Scene Console("Console", char(32), char(248), char(248), char(248), char(248), char(248), char(248), Application::GetConsoleWidth(), 7, 0, Application::GetConsoleHeight() - 7, 15, 3);
	Console.CreateAsSquare();

	Console.DrawString("(Entered Backyard.)", 1, 1);

	ECS::Add<SpriteComponent>(WORLD_ONE_SILVER_KEY, SpriteComponent(char(235), 14));
	ECS::Add<PositionComponent>(WORLD_ONE_SILVER_KEY, PositionComponent(15, 2));
	ECS::Add<CollisionComponent>(WORLD_ONE_SILVER_KEY, CollisionComponent(2));
	ECS::Add<BackpackItemComponent>(WORLD_ONE_SILVER_KEY, BackpackItemComponent(SILVER_KEY));

	ECS::Add<SpriteComponent>(100, SpriteComponent('X', 123));
	ECS::Add<PositionComponent>(100, PositionComponent(15, 3));
	ECS::Add<CollisionComponent>(100)->collisionSetting = 2;
	ECS::Add<NearbyComponent>(100);
	ECS::Add<MotionComponent>(100, MotionComponent(0, 1, 0, 0, 1));

	ECS::Add<PersistencyComponent>(WORLD_ONE_DOOR_MAINMENU);
	ECS::Add<SpriteComponent>(WORLD_ONE_DOOR_MAINMENU)->sprite = char(179);
	ECS::Add<PositionComponent>(WORLD_ONE_DOOR_MAINMENU, PositionComponent(8, 2));
	ECS::Add<SceneComponent>(WORLD_ONE_DOOR_MAINMENU)->nextScene = Scenes::MAINMENU;
	ECS::Add<CollisionComponent>(WORLD_ONE_DOOR_MAINMENU)->collisionSetting = 2;
	ECS::Add<LockComponent>(WORLD_ONE_DOOR_MAINMENU, LockComponent(SILVER_KEY))->registerPersistancy = true;



	double tick = Application::GetGlobalTimer();
	while (scene.GetIsPlaying())
	{
		double const newTick = Application::GetGlobalTimer();
		if (tick < newTick)
		{
			ProcessPlayerInput(&scene);
			ECS::Systems::Input();
			ECS::Systems::Movement();
			ECS::Systems::ExecuteOrder66();
			ECS::Systems::Draw();
			scene.Draw();
			
			PlayerBackpack.DrawSprite('0' + ECS::Get<BackpackComponent>(PLAYER)->items[SILVER_KEY], 14, 3);
			PlayerBackpack.DrawSprite('0' + ECS::Get<BackpackComponent>(PLAYER)->items[GOLD_KEY], 14, 4);

			PlayerBackpack.Draw();
			Console.Draw();
			tick = newTick + 1/30;
		}
	}

	//Put entities in kill queue before next scene
	ECS::killQueue.emplace_back(WORLD_ONE_DOOR_MAINMENU);

	//Kill entities
	ECS::Systems::ExecuteOrder66();

	scene.Erase();
	PlayerBackpack.Erase();
	this->currentScene = scene.GetNextName();
}