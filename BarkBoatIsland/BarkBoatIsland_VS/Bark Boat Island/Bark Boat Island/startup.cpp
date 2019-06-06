#include "startup.h"
#include "scene.h"
#include "ecs.h"

Startup::Startup()
{
}

void Startup::Start()
{
	update = true;

	canvas = new Canvas("MainMenu", char(177), char(186), char(205), char(201), char(187), char(188), char(200), 0, 0, 2, 1, 0, 0);

	canvas->CreateFromVector2D(Application::ReadFileToVector2D("Scenes/worldone.txt"));

	playerBackpack = new Canvas("Backpack", ' ', char(186), char(205), char(201), char(187), char(188), char(200), 20, 20, Application::GetConsoleWidth() - 20, 0, 8, 3);

	playerBackpack->CreateAsSquare();
	playerBackpack->DrawStringToBack("BACKPACK", 1, 1,95, true, ' ', 95);

	const int size = 24;
	const std::vector<std::vector<char>> sprites(size, std::vector<char>(size, ' '));

	const std::vector<std::vector<short>> colors(size, std::vector<short>(size, 15));

	SpriteComponent* spr = ECS::Add<SpriteComponent>(40);
	spr->sprite = sprites;
	spr->sprite.shrink_to_fit();

	spr->color = colors;
	spr->color.shrink_to_fit();

	spr->drawLayer = 0;
	ECS::Add<PositionComponent>(40, PositionComponent(0, 0));




	SpriteComponent* playerSprite = ECS::Add<SpriteComponent>(PLAYER);
	playerSprite->sprite = { { '#' } };
	playerSprite->sprite.shrink_to_fit();

	playerSprite->color = { {13} };
	playerSprite->color.shrink_to_fit();

	playerSprite->drawLayer = 1;

	CollisionComponent* collision = ECS::Add<CollisionComponent>(PLAYER);
	collision->collisionSetting = CollisionTypes::DYNAMIC;
	collision->collisionBuffer = { {true} };

	ECS::Add<PositionComponent>(PLAYER, PositionComponent(9, 0));
	ECS::Add<MotionComponent>(PLAYER);
	ECS::Add<InputComponent>(PLAYER);
	ECS::Add<BackpackComponent>(PLAYER);

	SpriteComponent* keySprite = ECS::Add<SpriteComponent>(WORLD_ONE_SILVER_KEY);
	keySprite->sprite = { { char(235) } };
	keySprite->sprite.shrink_to_fit();

	keySprite->color = { {14} };
	keySprite->color.shrink_to_fit();

	keySprite->drawLayer = 1;
	
	ECS::Add<PositionComponent>(WORLD_ONE_SILVER_KEY, PositionComponent(18, 10));
	ECS::Add<CollisionComponent>(WORLD_ONE_SILVER_KEY, CollisionComponent(CollisionTypes::SOLID));
	ECS::Add<BackpackItemComponent>(WORLD_ONE_SILVER_KEY, BackpackItemComponent(GOLD_KEY));

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

	Draw();	

	DrawLight(ECS::Get<SpriteComponent>(40), ECS::Get<PositionComponent>(40), (int)(ECS::Get<SpriteComponent>(40)->sprite.size() / 2), 0.05f, 1);

	canvas->Draw();

	playerBackpack->ClearFront();

	if (BackpackComponent* backpackComponent = ECS::Get<BackpackComponent>(PLAYER))
	{
		if (backpackComponent->items[SILVER_KEY]) { playerBackpack->DrawString("Silver Keys: " + std::to_string(backpackComponent->items[SILVER_KEY]), 1, 3, 6); } 
		if (backpackComponent->items[GOLD_KEY]) { playerBackpack->DrawString("Gold Keys: " + std::to_string(backpackComponent->items[GOLD_KEY]), 1, 4, 6); }
	}

	playerBackpack->Draw();
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


void Startup::DrawLight(SpriteComponent* spriteComponent, PositionComponent* positionComponent, const int radius, const float angleRadStepSize, const int idOwner = 0)
{
	const float twoPi = 2.0f * (atanf(1) * 4);
	float angleRad = 0.0f;

	if (PositionComponent * positionComponentOwner = ECS::Get<PositionComponent>(idOwner)) 
	{ 
		positionComponent->posX = positionComponentOwner->posX - radius;
		positionComponent->posY = positionComponentOwner->posY - radius;
	}

	const int entityPosX = positionComponent->posX;
	const int entityPosY = positionComponent->posY;

	for (int x = 0; x < spriteComponent->sprite.size(); x++)
	{
		for (int y = 0; y < spriteComponent->sprite[x].size(); y++)
		{
			spriteComponent->sprite[x][y] = ' ';
		}
	}

	for (angleRad; angleRad < twoPi; angleRad += angleRadStepSize)
	{
		for (int r = 1; r != radius; r++)
		{
			int const spritePosX = radius + (int)((r)* cos(angleRad));
			int const spritePosY = radius + (int)((r)* sin(angleRad));

			if (!GetEntityAt(spritePosX + entityPosX, spritePosY + entityPosY, idOwner) && 
				canvas->TryPositionIsWall(spritePosX + entityPosX, spritePosY + entityPosY) == false)
			{
				spriteComponent->sprite[spritePosX][spritePosY] = canvas->GetChar(spritePosX + entityPosX, spritePosY + entityPosY);
			}
			else
			{
				spriteComponent->sprite[spritePosX][spritePosY] = canvas->GetChar(spritePosX + entityPosX, spritePosY + entityPosY);
				break;
			}
		}
	}
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

		if (inputComponent->command == 'E')
		{
			if (BackpackComponent* backpackComponent = ECS::Get<BackpackComponent>(Entities::PLAYER))
			{
				if (PositionComponent* positionComponent = ECS::Get<PositionComponent>(Entities::PLAYER))
				{
					//kolla alla
					if (int const item = GetEntityAt(positionComponent->posX + 1, positionComponent->posY, Entities::PLAYER))
					{
						if (BackpackItemComponent* backpackItemComponent = ECS::Get<BackpackItemComponent>(item))
						{
							PositionComponent* positionComponent = ECS::Get<PositionComponent>(item);
							positionComponent->isActive = false;

							if (SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(item))
							{
								spriteComponent->isActive = false;
							}
							if (CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(item))
							{
								collisionComponent->isActive = false;
							}

							backpackComponent->items[backpackItemComponent->type]++;
						}
					}
				}
			}
		}

					//for (int nbr = 0; nbr < nearbyComponent->neighbors.size(); nbr++)
					//{
					//	if (BackpackItemComponent* backpackItemComponent = ECS::Get<BackpackItemComponent>(nearbyComponent->neighbors[nbr]))
					//	{
					//		PositionComponent* positionComponent = ECS::Get<PositionComponent>(nearbyComponent->neighbors[nbr]);
					//		canvas->DrawSprite(canvas->GetFloor(), positionComponent->posX, positionComponent->posY, canvas->GetFloorColor());

					//		positionComponent->isActive = false;

					//		if (SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(nearbyComponent->neighbors[nbr]))
					//		{
					//			spriteComponent->isActive = false;
					//		}
					//		if (CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(nearbyComponent->neighbors[nbr]))
					//		{
					//			collisionComponent->isActive = false;
					//		}

					//		backpackComponent->items[backpackItemComponent->type]++;
					//	}

			//			if (SceneComponent* sceneComponent = ECS::Get<SceneComponent>(nearbyComponent->neighbors[nbr]))
			//			{
			//				if (LockComponent* lockComponent = ECS::Get<LockComponent>(nearbyComponent->neighbors[nbr]))
			//				{
			//					if (lockComponent->isActive)
			//					{
			//						for (int i = 0; i < backpackComponent->items.size(); i++)
			//						{
			//							if (backpackComponent->items[lockComponent->key])
			//							{
			//								update = false;
			//								backpackComponent->items[lockComponent->key]--;
			//								lockComponent->isActive = false;
			//								return;
			//							}
			//						}
			//						return;
			//					}
			//				}
			//				update = false;
			//			}
			//		}
			//	}
			//}
		//}
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
				for (int x = 0; x < spriteComponent->sprite.size(); x++)
				{
					for (int y = 0; y < spriteComponent->sprite[x].size(); y++)
					{
						if (spriteComponent->sprite[x][y] != ' ')
						{
							canvas->DrawSprite(spriteComponent->sprite[x][y], positionComponent->posX + x, positionComponent->posY + y, spriteComponent->color[x][y]);
						}
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

int Startup::GetEntityAt(int const posX, int const posY, int const id)
{
	const std::vector<int> ENTITIES = ECS::GetAllIDFrom<PositionComponent>();

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);

		if (ENTITIES[e] != id && 
			positionComponent->isActive &&
			positionComponent->posX == posX &&
			positionComponent->posY == posY)
		{
			return ENTITIES[e];
		}
	}
	return 0;
}

//background: East Sea Dokdo

bool Startup::IsPositionFree(int const posX, int const posY, int const id, CollisionComponent* collisionComponent)
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

			if (GetEntityAt(posX, posY, id))
			{
				if (collisionComponent != nullptr && 
					collisionComponentOther->isActive == true && 
					positionComponentOther->isActive == true)
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
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<MotionComponent>()
		});

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(ENTITIES[e]);
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);
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
							if (this->IsPositionFree(positionComponent->posX + x, positionComponent->posY + y - 1, ENTITIES[e], collisionComponent) == false)
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
							if (this->IsPositionFree(positionComponent->posX + x, positionComponent->posY + y + 1, ENTITIES[e], collisionComponent) == false)
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
							if (this->IsPositionFree(positionComponent->posX + x + 1, positionComponent->posY + y, ENTITIES[e], collisionComponent) == false)
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
							if (this->IsPositionFree(positionComponent->posX + x - 1, positionComponent->posY + y, ENTITIES[e], collisionComponent) == false)
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