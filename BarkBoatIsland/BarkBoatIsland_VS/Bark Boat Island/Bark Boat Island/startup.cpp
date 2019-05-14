#include "startup.h"
#include "scene.h"
#include "ecs.h"

Startup::Startup()
{
}

void Startup::Start()
{
	update = true;

	scene = new Scene("MainMenu", char(177), char(186), char(205), char(201), char(187), char(188), char(200), 0, 0, 2, 1);

	scene->CreateFromVector2D(Application::ReadFileToVector2D("Scenes/mainmenu.txt"));
	ECS::AssignScene(*scene);

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
	ECS::Add<PositionComponent>(MAINMENU_DOOR_PLAY, PositionComponent(2, 4));
	ECS::Add<SceneComponent>(MAINMENU_DOOR_PLAY)->nextScene = 1;
	ECS::Add<CollisionComponent>(MAINMENU_DOOR_PLAY)->collisionSetting = 2;

	ECS::Add<SpriteComponent>(MAINMENU_DOOR_QUIT)->sprite = char(179);
	ECS::Add<PositionComponent>(MAINMENU_DOOR_QUIT, PositionComponent(2, 6));
	ECS::Add<SceneComponent>(MAINMENU_DOOR_QUIT)->nextScene = 2;
	ECS::Add<CollisionComponent>(MAINMENU_DOOR_QUIT)->collisionSetting = 2;
}

void Startup::Update()
{
	ECS::Systems::Input();
	ECS::Systems::Movement();
	ECS::Systems::ExecuteOrder66();
	ECS::Systems::Draw();
	ProcessPlayerInput();
	scene->Draw();
}

void Startup::End()
{
	//Put entities in kill queue before next scene
	ECS::killQueue.emplace_back(MAINMENU_DOOR_PLAY);
	ECS::killQueue.emplace_back(MAINMENU_DOOR_QUIT);

	//Kill entities
	ECS::Systems::ExecuteOrder66();

	scene->Erase();

	SceneManager::RegisterScene(new Startup());
}

void Startup::ProcessPlayerInput()
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
							update = false;
						}
					}
				}
			}
		}
	}
}