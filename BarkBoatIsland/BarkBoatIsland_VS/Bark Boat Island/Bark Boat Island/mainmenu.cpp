#include "mainmenu.h"
#include "canvas.h"
#include "rectanglebuffers.h"
#include "ecs.h"
#include "globalenums.h"
#include "startup.h"

Mainmenu::Mainmenu()
{
}

void Mainmenu::Start()
{
	update = true;

	RectangleBuffers backgroundBuffers = RectangleBuffers(char(32), char(205), char(186), char(201), char(187), char(188), char(200), 3, 5, 8, 3);
	backgroundCanvas = new Canvas(0, 0, 0, *backgroundBuffers.GetCharBuffer(), *backgroundBuffers.GetColorBuffer(), *backgroundBuffers.GetCollisionBuffer());

	mainCanvas = new Canvas();
	mainCanvas->Copy(backgroundCanvas);
	mainCanvas->SetBuffersToZero();

	RectangleBuffers textBoxBuffers = RectangleBuffers(char(32), '*', '*', '*', '*', '*', '*', 30, 5, 0, 3);
	textBox = new Canvas(3, 0, 0, *textBoxBuffers.GetCharBuffer(), *textBoxBuffers.GetColorBuffer());
	textBox->PutString("PLAY", 1, 1, 0x0A, false);
	textBox->PutString("QUIT", 1, 3, 0x0A, false);
	textBox->PutString("Made by Crumblebit", textBox->GetWidth() - 19, 3, 0x0E, false);

	SpriteComponent* playerSprite = ECS::Add<SpriteComponent>(PLAYER);
	playerSprite->sprite = { { '#' } };
	playerSprite->color = { {13} };
	playerSprite->drawLayer = 1;

	CollisionComponent* playerCollision = ECS::Add<CollisionComponent>(PLAYER);
	playerCollision->collisionSetting = CollisionTypes::DYNAMIC;
	playerCollision->collisionBuffer = { {true} };

	PositionComponent* playerPosition = ECS::Add<PositionComponent>(PLAYER, PositionComponent(1, 1));
	ECS::Add<MotionComponent>(PLAYER)->movementRate = 5.0f;
	ECS::Add<InputComponent>(PLAYER);
	ECS::Add<BackpackComponent>(PLAYER);

	SpriteComponent* doorPlaySprite = ECS::Add<SpriteComponent>(MAINMENU_DOOR_PLAY);
	doorPlaySprite->sprite = { { char(179) } };
	doorPlaySprite->color = { {15} };
	doorPlaySprite->drawLayer = 1;
	ECS::Add<PositionComponent>(MAINMENU_DOOR_PLAY, PositionComponent(2, 1));
	ECS::Add<SceneComponent>(MAINMENU_DOOR_PLAY)->nextScene = STARTUP;
	ECS::Add<CollisionComponent>(MAINMENU_DOOR_PLAY)->collisionSetting = CollisionTypes::SOLID;

	SpriteComponent* doorQuitSprite = ECS::Add<SpriteComponent>(MAINMENU_DOOR_QUIT);
	doorQuitSprite->sprite = { { char(179) } };
	doorQuitSprite->color = { {15} };
	doorQuitSprite->drawLayer = 1;
	ECS::Add<PositionComponent>(MAINMENU_DOOR_QUIT, PositionComponent(2, 3));
	ECS::Add<SceneComponent>(MAINMENU_DOOR_QUIT)->nextScene = QUIT;
	ECS::Add<CollisionComponent>(MAINMENU_DOOR_QUIT)->collisionSetting = CollisionTypes::SOLID;
}

void Mainmenu::Update()
{
	Collision();
	Input();
	ProcessPlayerInput();
	Movement();
	ExecuteOrder66();
	Draw();
}

void Mainmenu::End()
{
	killQueue.emplace_back(MAINMENU_DOOR_PLAY);
	ExecuteOrder66();

	backgroundCanvas->Erase();
	mainCanvas->Erase();
	textBox->Erase();

	delete mainCanvas;
	delete backgroundCanvas;
	delete textBox;

	if (nextScene == STARTUP)
	{
		ECS::Get<PositionComponent>(PLAYER)->posX = 9;
		ECS::Get<PositionComponent>(PLAYER)->posY = 3;
		SceneManager::RegisterScene(new Startup());
	}
	else if (nextScene == QUIT)
	{
		SceneManager::RegisterScene(nullptr);
	}
}

void Mainmenu::ExecuteOrder66()
{
	for (int i = killQueue.size() - 1; !killQueue.empty(); i--)
	{
		int const id = killQueue[i];

		ECS::Destroy<PositionComponent>(id);
		ECS::Destroy<SpriteComponent>(id);
		ECS::Destroy<InputComponent>(id);
		ECS::Destroy<MotionComponent>(id);
		ECS::Destroy<BackpackComponent>(id);
		ECS::Destroy<BackpackItemComponent>(id);
		ECS::Destroy<LockComponent>(id);

		killQueue.pop_back();
	}
}

void Mainmenu::ProcessPlayerInput()
{
	if (InputComponent* inputComponent = ECS::Get<InputComponent>(Entities::PLAYER))
	{
		if (MotionComponent* motionComponent = ECS::Get<MotionComponent>(Entities::PLAYER))
		{
			motionComponent->up = 0;
			motionComponent->down = 0;
			motionComponent->left = 0;
			motionComponent->right = 0;

			if (inputComponent->command == ' ')
			{
				inputComponent->isHoldingKey = false;
			}
			else
			{
				if (inputComponent->isHoldingKey == false)
				{
					motionComponent->timeToMove = 0;
					inputComponent->isHoldingKey = true;
				}
			}
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
			if (PositionComponent* positionComponent = ECS::Get<PositionComponent>(Entities::PLAYER))
			{
				for (short x = -1; x != 2; x++)
				{
					for (short y = -1; y != 2; y++)
					{
						if (abs(x) * abs(y))
						{
							continue;
						}

						if (int const other = GetEntityAt(positionComponent->posX + x, positionComponent->posY + y, Entities::PLAYER))
						{
							//doors
							if (SceneComponent* sceneComponent = ECS::Get<SceneComponent>(other))
							{
								if (LockComponent* lockComponent = ECS::Get<LockComponent>(other))
								{
									if (lockComponent->isActive)
									{
										if (BackpackComponent* backpackComponent = ECS::Get<BackpackComponent>(Entities::PLAYER))
										{
											for (int i = 0; i < backpackComponent->items.size(); i++)
											{
												if (backpackComponent->items[lockComponent->key])
												{
													backpackComponent->items[lockComponent->key]--;
													lockComponent->isActive = false;
													nextScene = sceneComponent->nextScene;
													update = false;
													break;
												}
											}
										}
									}
									else
									{
										nextScene = sceneComponent->nextScene;
										update = false;
									}
								}
								else
								{
									nextScene = sceneComponent->nextScene;
									update = false;
								}
							}
						}
					}
				}
			}
		}
	}
}

void Mainmenu::Draw()
{
	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<SpriteComponent>()
		});

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(ENTITIES[e]);
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);

		if (spriteComponent->isActive)
		{
			for (int x = 0; x < spriteComponent->sprite.size(); x++)
			{
				for (int y = 0; y < spriteComponent->sprite[x].size(); y++)
				{
					if (spriteComponent->color[x][y] != spriteComponent->colorKey)
					{
						mainCanvas->PutChar(spriteComponent->sprite[x][y], positionComponent->posX + x, positionComponent->posY + y, spriteComponent->color[x][y]);
					}
				}
			}
		}
	}

	//canvas
	mainCanvas->Draw();
	mainCanvas->CombineWith(backgroundCanvas);
	textBox->Draw();
}

void Mainmenu::Input()
{
	const std::array<int, 5> vKeys{ 0x41, 0x57, 0x53, 0x44, 0x45 };

	if (InputComponent* inputComponent = ECS::Get<InputComponent>(Entities::PLAYER))
	{
		int i = 0;

		for (i; i < vKeys.size(); i++)
		{
			if (Application::Input(vKeys[i]))
			{
				inputComponent->command = toascii(vKeys[i]);
				return;
			}
		}
		if (i == vKeys.size())
		{
			inputComponent->command = ' ';
		}
	}
}

void Mainmenu::Collision()
{
	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<SpriteComponent>(),
			ECS::GetAllIDFrom<CollisionComponent>()
		});

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(ENTITIES[e]);
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);
		CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(ENTITIES[e]);

		if (spriteComponent->isActive)
		{
			for (int x = 0; x < spriteComponent->sprite.size(); x++)
			{
				for (int y = 0; y < spriteComponent->sprite[x].size(); y++)
				{
					if (spriteComponent->color[x][y] != spriteComponent->colorKey)
					{
						mainCanvas->PutCollision(positionComponent->posX + x, positionComponent->posY + y, collisionComponent->collisionSetting);
					}
				}
			}
		}
	}
}

int Mainmenu::GetEntityAt(int const posX, int const posY, int const id)
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

bool Mainmenu::IsPositionFree(int const posX, int const posY, int const id, CollisionComponent* collisionComponent)
{
	short const collisionCanvas = mainCanvas->GetCollisionAt(posX, posY);

	if (collisionComponent->collisionSetting == CollisionTypes::SOLID &&
		(collisionCanvas == CollisionTypes::SOLID ||
			collisionCanvas == CollisionTypes::DYNAMIC ||
			collisionCanvas == CollisionTypes::KINETIC))
	{
		return false;
	}

	if (collisionComponent->collisionSetting == CollisionTypes::DYNAMIC &&
		(collisionCanvas == CollisionTypes::SOLID ||
			collisionCanvas == CollisionTypes::DYNAMIC))
	{
		return false;
	}

	return true;
}

void Mainmenu::Movement()
{
	float timePoint = Application::GetGlobalTimer();

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