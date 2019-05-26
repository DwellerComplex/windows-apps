#include "startup.h"
#include "scene.h"
#include "ecs.h"

Startup::Startup()
{
}

void Startup::Start()
{
	update = true;

	canvas = new Canvas("MainMenu", char(177), char(186), char(205), char(201), char(187), char(188), char(200), 0, 0, 2, 1, 1, 4);

	canvas->CreateFromVector2D(Application::ReadFileToVector2D("Scenes/mainhall.txt"));

	std::vector<std::vector<char>> sprites = { 
	{ ' ', ' ', ' ', ' ', ' ' }, 
	{ ' ', ' ', ' ', ' ', ' ' }, 
	{ ' ', ' ', '#', ' ', ' ' }, 
	{ ' ', ' ', ' ', ' ', ' ' }, 
	{ ' ', ' ', ' ', ' ', ' ' } };
	std::vector<std::vector<short>> colors = { 
	{7, 7, 7, 7, 7 }, 
	{7, 7, 7, 7, 7 }, 
	{7, 7, 8, 7, 7 }, 
	{7, 7, 7, 7, 7 }, 
	{7, 7, 7, 7, 7 } };

	SpriteComponent* playerSprite = ECS::Add<SpriteComponent>(PLAYER);
	playerSprite->frontBuffer = sprites;
	playerSprite->frontColorBuffer = colors;
	playerSprite->drawLayer = 0;

	std::vector<std::vector<bool>> col = { 
	{ false, false, false, false, false }, 
	{ false, false, false, false, false }, 
	{ false, false, true, false, false }, 
	{ false, false, false, false, false }, 
	{ false, false, false, false, false } };

	CollisionComponent* collision = ECS::Add<CollisionComponent>(PLAYER);
	collision->collisionSetting = CollisionTypes::DYNAMIC;
	collision->collisionBuffer = col;


	ECS::Add<PositionComponent>(PLAYER, PositionComponent(1, 4));
	ECS::Add<NearbyComponent>(PLAYER);
	ECS::Add<MotionComponent>(PLAYER);
	ECS::Add<InputComponent>(PLAYER);
	ECS::Add<BackpackComponent>(PLAYER);




	//ECS::Add<SpriteComponent>(MAINMENU_DOOR_PLAY)->sprite = char(179);
	//ECS::Add<PositionComponent>(MAINMENU_DOOR_PLAY, PositionComponent(2, 4));
	//ECS::Add<SceneComponent>(MAINMENU_DOOR_PLAY)->nextScene = 1;
	//ECS::Add<CollisionComponent>(MAINMENU_DOOR_PLAY)->collisionSetting = 2;

	//ECS::Add<SpriteComponent>(MAINMENU_DOOR_QUIT)->sprite = char(179);
	//ECS::Add<PositionComponent>(MAINMENU_DOOR_QUIT, PositionComponent(2, 6));
	//ECS::Add<SceneComponent>(MAINMENU_DOOR_QUIT)->nextScene = 2;
	//ECS::Add<CollisionComponent>(MAINMENU_DOOR_QUIT)->collisionSetting = 2;
}

void Startup::Update()
{
	Input();
	ProcessPlayerInput();
	Movement();
	ExecuteOrder66();
	canvas->ClearFront();

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			if(x != 2 || y != 2)
				ECS::Get<SpriteComponent>(PLAYER)->frontBuffer[x][y] = canvas->GetChar(ECS::Get<PositionComponent>(PLAYER)->posX + x, ECS::Get<PositionComponent>(PLAYER)->posY + y);
		}
	}

	Draw();
	canvas->Draw();
}

void Startup::End()
{
	////Put entities in kill queue before next scene
	//killQueue.emplace_back(MAINMENU_DOOR_PLAY);
	//killQueue.emplace_back(MAINMENU_DOOR_QUIT);

	////Kill entities
	//ExecuteOrder66();

	canvas->Erase();

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
							PositionComponent* positionComponent = ECS::Get<PositionComponent>(nearbyComponent->neighbors[nbr]);
							canvas->DrawSprite(canvas->GetFloor(), positionComponent->posX, positionComponent->posY, canvas->GetFloorColor());

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
											update = false;
											backpackComponent->items[lockComponent->key]--;
											lockComponent->isActive = false;
											return;
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

void Startup::ExecuteOrder66()
{
	for (int i = killQueue.size() - 1; !killQueue.empty(); i--)
	{
		int const id = killQueue[i];

		if (PersistencyComponent* persistencyComponent = ECS::Get<PersistencyComponent>(id))
		{
			if (PositionComponent* positionComponent = ECS::Get<PositionComponent>(id)) { if (!positionComponent->registerPersistancy) { ECS::Destroy<PositionComponent>(id); } }; //killQueue.emplace_back(ENTITIES[x]);
			if (SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(id)) { if (!spriteComponent->registerPersistancy) { ECS::Destroy<SpriteComponent>(id); } };
			if (InputComponent* inputComponent = ECS::Get<InputComponent>(id)) { if (!inputComponent->registerPersistancy) { ECS::Destroy<InputComponent>(id); } };
			if (MotionComponent* motionComponent = ECS::Get<MotionComponent>(id)) { if (!motionComponent->registerPersistancy) { ECS::Destroy<MotionComponent>(id); } };
			if (NearbyComponent* nearbyComponent = ECS::Get<NearbyComponent>(id)) { if (!nearbyComponent->registerPersistancy) { ECS::Destroy<NearbyComponent>(id); } };
			if (BackpackComponent* backpackComponent = ECS::Get<BackpackComponent>(id)) { if (!backpackComponent->registerPersistancy) { ECS::Destroy<BackpackComponent>(id); } };
			if (BackpackItemComponent* backpackItemComponent = ECS::Get<BackpackItemComponent>(id)) { if (!backpackItemComponent->registerPersistancy) { ECS::Destroy<BackpackItemComponent>(id); } };
		}
		else
		{
			ECS::Destroy<PositionComponent>(id);
			ECS::Destroy<SpriteComponent>(id);
			ECS::Destroy<InputComponent>(id);
			ECS::Destroy<MotionComponent>(id);
			ECS::Destroy<NearbyComponent>(id);
			ECS::Destroy<BackpackComponent>(id);
			ECS::Destroy<BackpackItemComponent>(id);
		}

		killQueue.pop_back();
	}
}

void Startup::Draw()
{
	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<SpriteComponent>()
		});


	for (short drawLayer = 0; drawLayer < canvas->NUMBER_OF_DRAW_LAYERS; drawLayer++)
	{
		for (int e = 0; e < ENTITIES.size(); e++)
		{
			SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(ENTITIES[e]);
			PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);

			if (spriteComponent->drawLayer == drawLayer && spriteComponent->isActive)
			{
				for (int x = 0; x < spriteComponent->frontBuffer.size(); x++)
				{
					for (int y = 0; y < spriteComponent->frontBuffer[x].size(); y++)
					{
						canvas->DrawSprite(spriteComponent->frontBuffer[x][y], positionComponent->posX + x, positionComponent->posY + y, spriteComponent->frontColorBuffer[x][y]);
					}
				}
			}
		}
	}
}

void Startup::Input()
{
	const std::array<int, 5> vKeys{ 0x41, 0x57, 0x53, 0x44, 0x45 };

	InputComponent* inputComponent = ECS::Get<InputComponent>(Entities::PLAYER);

	inputComponent->command = ' ';
	int i = 0;

	for (i; i < vKeys.size(); i++)
	{
		if (Application::Input(vKeys[i]))
		{
			if (inputComponent->hasClicked == false)
			{
				inputComponent->command = toascii(vKeys[i]);
				inputComponent->hasClicked = true;
			}
			break;
		}
	}
	if (i == vKeys.size() && inputComponent->hasClicked == true)
	{
		inputComponent->hasClicked = false;
	}
}


bool Startup::TryPosition(int const posX, int const posY, int const id, CollisionComponent* collisionComponent)
{
	if (canvas->TryPositionIsFloor(posX, posY) == false)
	{
		if (canvas->TryPositionIsWall(posX, posY) == true)
		{
			return false;
		}

		const std::vector<int> OTHERENTITIES = Application::ExtractSameInts(
			{
				ECS::GetAllIDFrom<PositionComponent>(),
				ECS::GetAllIDFrom<CollisionComponent>()
			});

		for (int other = 0; other < OTHERENTITIES.size(); other++)
		{
			PositionComponent* positionComponentOther = ECS::Get<PositionComponent>(OTHERENTITIES[other]);
			CollisionComponent* collisionComponentOther = ECS::Get<CollisionComponent>(OTHERENTITIES[other]);

			if (OTHERENTITIES[other] != id && 
				positionComponentOther->posX == posX &&
				positionComponentOther->posY == posY)
			{
				if (collisionComponent->collisionSetting == CollisionTypes::SOLID &&
					(collisionComponentOther->collisionSetting == CollisionTypes::SOLID || 
					collisionComponentOther->collisionSetting == CollisionTypes::DYNAMIC ||
					collisionComponentOther->collisionSetting == CollisionTypes::KINETIC))
				{
					return false;
				}
				
				if (collisionComponent->collisionSetting == CollisionTypes::DYNAMIC &&
					(collisionComponentOther->collisionSetting == CollisionTypes::SOLID))
				{
					return false;
				}
			}
		}
	}
	
	return true;
}

void Startup::Movement()
{
	float timePoint = Application::GetGlobalTimer();

	const std::vector<int> ENTITIES_NEARBY = ECS::GetAllIDFrom<PositionComponent>();

	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<CollisionComponent>(),
			//ECS::GetAllIDFrom<NearbyComponent>(),
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<MotionComponent>()
		});

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(ENTITIES[e]);
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);
		//NearbyComponent* nearbyComponent = ECS::Get<NearbyComponent>(ENTITIES[e]);
		MotionComponent* motionComponent = ECS::Get<MotionComponent>(ENTITIES[e]);

		bool collided = false;

		if (motionComponent->isActive && (motionComponent->movementRate == 0.0f || motionComponent->timeToMove < timePoint))
		{
			// MOTION UP
			if (motionComponent->up)
			{			
				for (int x = 0; x < collisionComponent->collisionBuffer.size(); x++)
				{
					for (int y = 0; y < collisionComponent->collisionBuffer[x].size(); y++)
					{
						if (collisionComponent->collisionBuffer[x][y])
						{
							if (this->TryPosition(positionComponent->posX + x, positionComponent->posY + y - 1, ENTITIES[e], collisionComponent) == false)
							{
								collided = true;
							}
						}
					}
				}

				if (collided == false)
				{
					positionComponent->posY -= 1;
				}
			}

			// MOTION DOWN
			if (motionComponent->down)
			{
				for (int x = 0; x < collisionComponent->collisionBuffer.size(); x++)
				{
					for (int y = 0; y < collisionComponent->collisionBuffer[x].size(); y++)
					{
						if (collisionComponent->collisionBuffer[x][y])
						{
							if (this->TryPosition(positionComponent->posX + x, positionComponent->posY + y + 1, ENTITIES[e], collisionComponent) == false)
							{
								collided = true;
							}
						}
					}
				}

				if (collided == false)
				{
					positionComponent->posY += 1;
				}
			}

			// MOTION RIGHT
			if (motionComponent->right)
			{
				for (int x = 0; x < collisionComponent->collisionBuffer.size(); x++)
				{
					for (int y = 0; y < collisionComponent->collisionBuffer[x].size(); y++)
					{
						if (collisionComponent->collisionBuffer[x][y])
						{
							if (this->TryPosition(positionComponent->posX + x + 1, positionComponent->posY + y, ENTITIES[e], collisionComponent) == false)
							{
								collided = true;
							}
						}
					}
				}

				if (collided == false)
				{
					positionComponent->posX += 1;
				}
			}

			// MOTION LEFT
			if (motionComponent->left)
			{
				for (int x = 0; x < collisionComponent->collisionBuffer.size(); x++)
				{
					for (int y = 0; y < collisionComponent->collisionBuffer[x].size(); y++)
					{
						if (collisionComponent->collisionBuffer[x][y])
						{
							if (this->TryPosition(positionComponent->posX + x - 1, positionComponent->posY + y, ENTITIES[e], collisionComponent) == false)
							{
								collided = true;
							}
						}
					}
				}

				if (collided == false)
				{
					positionComponent->posX -= 1;
				}
			}

			if (motionComponent->movementRate == 0.0f)
			{
				motionComponent->up = 0;
				motionComponent->down = 0;
				motionComponent->left = 0;
				motionComponent->right = 0;
			}
			else
			{
				motionComponent->timeToMove = timePoint + (1.0f / motionComponent->movementRate);
			}
		}
	}
}