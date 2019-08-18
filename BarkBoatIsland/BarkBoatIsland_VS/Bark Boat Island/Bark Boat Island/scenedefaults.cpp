#include "scenedefaults.h"
#include "ecs.h"
#include "globalenums.h"
#include "canvas.h"

SceneDefaults::SceneDefaults()
{
	continueUpdate = true;
	playerSpawnTime = 0;
}

void SceneDefaults::PlayerInputMovement()
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
	}
}

void SceneDefaults::PlayerInteractBackpack()
{
	if (int const other = PlayerNearInteractable())
	{
		//Backpack items
		if (BackpackComponent * backpackComponent = ECS::Get<BackpackComponent>(Entities::PLAYER))
		{
			if (BackpackItemComponent * backpackItemComponent = ECS::Get<BackpackItemComponent>(other))
			{
				backpackItemComponent->isInBackpack = true;

				PositionComponent* positionComponent = ECS::Get<PositionComponent>(other);
				positionComponent->isActive = false;

				if (SpriteComponent * spriteComponent = ECS::Get<SpriteComponent>(other))
				{
					spriteComponent->isActive = false;
				}
				if (CollisionComponent * collisionComponent = ECS::Get<CollisionComponent>(other))
				{
					collisionComponent->isActive = false;
				}

				backpackComponent->items[backpackItemComponent->type]++;
			}
		}
	}
}

void SceneDefaults::PlayerInteractDoors()
{
	if (int const other = PlayerNearInteractable())
	{
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
								continueUpdate = false;
								break;
							}
						}
					}
				}
				else
				{
					nextScene = sceneComponent->nextScene;
					continueUpdate = false;
				}
			}
			else
			{
				nextScene = sceneComponent->nextScene;
				continueUpdate = false;
			}
		}
	}
}

void SceneDefaults::PlayerInteractTrees(Canvas* console)
{
	float timePoint = Application::GetGlobalTimer();

	if (int const other = PlayerNearInteractable())
	{
		if (TreeComponent * treeComponent = ECS::Get<TreeComponent>(other))
		{

			if (treeComponent->timeToChop > timePoint)
			{
				return;
			}
			
			if (BackpackComponent * backpackComponent = ECS::Get<BackpackComponent>(Entities::PLAYER))
			{
				for (int i = 0; i < backpackComponent->items.size(); i++)
				{
					if (backpackComponent->items[AXE])
					{
						treeComponent->timeToChop = timePoint + treeComponent->chopInterval;

						switch (treeComponent->chops)
						{
						case 0:
							if (SpriteComponent * spriteComponent = ECS::Get<SpriteComponent>(other))
							{
								spriteComponent->isActive = false;
							}
							if (CollisionComponent * collisionComponent = ECS::Get<CollisionComponent>(other))
							{
								collisionComponent->isActive = false;
							}
							if (PositionComponent * positionComponent = ECS::Get<PositionComponent>(other))
							{
								positionComponent->isActive = false;
							}

							consoleQueue.insert(consoleQueue.begin(), "Take logs.");
							console->SetDrawThisTick(true);

							treeComponent->chops--;
							//place nrLogs in inv
							return;
						case 1:
							if (SpriteComponent * spriteComponent = ECS::Get<SpriteComponent>(other))
							{
								spriteComponent->sprite = { { '#' } };
							}

							consoleQueue.insert(consoleQueue.begin(), "(chop)");
							console->SetDrawThisTick(true);

							treeComponent->chops--;
							return;
						case 2:
							if (SpriteComponent * spriteComponent = ECS::Get<SpriteComponent>(other))
							{
								spriteComponent->sprite = { { '.' } };

								if (PositionComponent * positionComponent = ECS::Get<PositionComponent>(other))
								{
									positionComponent->posY++;
								}
							}

							consoleQueue.insert(consoleQueue.begin(), "Take logs.");
							console->SetDrawThisTick(true);

							treeComponent->chops--;
							//place nrLogs in inv
							return;
						case 3:
							if (SpriteComponent * spriteComponent = ECS::Get<SpriteComponent>(other))
							{
								spriteComponent->sprite[0][0] = '#';

								spriteComponent->color[0][0] = 0x06;
							}

							consoleQueue.insert(consoleQueue.begin(), "(chop)");
							console->SetDrawThisTick(true);

							treeComponent->chops--;
							return;
						case 4:
							if (SpriteComponent * spriteComponent = ECS::Get<SpriteComponent>(other))
							{
								spriteComponent->sprite[0][0] = char(240);
								spriteComponent->sprite[0][1] = '.';
							}

							consoleQueue.insert(consoleQueue.begin(),"(chop)");
							console->SetDrawThisTick(true);

							treeComponent->chops--;
							return;
						}
					}
				}
			}
		}
	}
}

int SceneDefaults::PlayerNearInteractable()
{
	if (InputComponent * inputComponent = ECS::Get<InputComponent>(Entities::PLAYER))
	{
		if (inputComponent->command == 'E' && playerSpawnTime + 1 < Application::GetGlobalTimer())
		{
			if (PositionComponent * positionComponent = ECS::Get<PositionComponent>(Entities::PLAYER))
			{
				for (short x = -1; x != 2; x++)
				{
					for (short y = -1; y != 2; y++)
					{
						if (x == 0 && y == 0)//abs(x) * abs(y) || 
						{
							continue;
						}

						if (int const other = GetEntityAt(positionComponent->posX + x, positionComponent->posY + y, Entities::PLAYER))
						{
							return other;
						}
					}
				}
			}
		}
	}

	return 0;
}

void SceneDefaults::PlayerInputEscape()
{
	if (InputComponent* inputComponent = ECS::Get<InputComponent>(Entities::PLAYER))
	{
		if (inputComponent->command == VK_ESCAPE)
		{
			nextScene = Scenes::MAINMENU;
			continueUpdate = false;
		}
	}
}

void SceneDefaults::ExecuteOrder66()
{
	for (int i = (int)killQueue.size() - 1; !killQueue.empty(); i--)
	{
		int const id = killQueue[i];

		ECS::Destroy<PositionComponent>(id);
		ECS::Destroy<SpriteComponent>(id);
		ECS::Destroy<InputComponent>(id);
		ECS::Destroy<MotionComponent>(id);
		ECS::Destroy<BackpackComponent>(id);
		ECS::Destroy<BackpackItemComponent>(id);
		ECS::Destroy<LockComponent>(id);
		ECS::Destroy<SpikeTrapComponent>(id);

		killQueue.pop_back();
	}
}

void SceneDefaults::DrawEntities(Canvas * mainCanvas)
{
	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<SpriteComponent>()
		});
	
	for (short drawLayer = 0; drawLayer < DrawLayers::NUMBER_OF_DRAW_LAYERS; drawLayer++)
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
						if (spriteComponent->color[x][y] != spriteComponent->colorKey)
						{
							mainCanvas->PutChar(spriteComponent->sprite[x][y], positionComponent->posX + x, positionComponent->posY + y, spriteComponent->color[x][y]);
						}
					}
				}
			}
		}
	}
}

void SceneDefaults::DrawCanvas(Canvas * canvas)
{
	canvas->Draw();
}

void SceneDefaults::DrawCanvasOnCanvas(Canvas * mainCanvas, Canvas * otherCanvas)
{
	mainCanvas->CombineWith(otherCanvas);
}

void SceneDefaults::DrawPlayerBackpack(Canvas * playerBackpack)
{
	if (playerBackpack->GetDrawThisTick() == true)
	{
		if (BackpackComponent* backpackComponent = ECS::Get<BackpackComponent>(PLAYER))
		{
			if (backpackComponent->items[SILVER_KEY]) { playerBackpack->PutString("Silver Keys: " + std::to_string(backpackComponent->items[SILVER_KEY]), 1, 3, 6, false); }
			if (backpackComponent->items[GOLD_KEY]) { playerBackpack->PutString("Gold Keys: " + std::to_string(backpackComponent->items[GOLD_KEY]), 1, 4, 6, false); }
		}
		playerBackpack->Draw();
		playerBackpack->SetDrawThisTick(false);
	}
}

void SceneDefaults::DrawConsole(Canvas * console)
{
	if (console->GetDrawThisTick() == true)
	{
		while (consoleQueue.size() > console->GetHeight() - 2)
		{
			consoleQueue.pop_back();
		}

		for (int i = 0; i != consoleQueue.size(); i++)
		{
			console->PutString(std::string(console->GetWidth() - 2, ' '), 1, 1 + i, 0x0A, false);

			if (i == 0)
			{
				console->PutString(consoleQueue[i], 1, 1 + i, 0x0A, false);
			}
			else
			{
				console->PutString(consoleQueue[i], 1, 1 + i, 8, false);
			}
		}

		console->Draw();
		console->SetDrawThisTick(false);
	}
}

void SceneDefaults::ZeroCanvasBuffers(Canvas * canvas)
{
	canvas->SetBuffersToZero();
}

void SceneDefaults::ReadInput()
{
	const std::array<int, 6> vKeys{ 0x41, 0x57, 0x53, 0x44, 0x45, VK_ESCAPE };

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

void SceneDefaults::Collision(Canvas* mainCanvas)
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

int SceneDefaults::GetEntityAt(int const posX, int const posY, int const id)
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

bool SceneDefaults::IsPositionFree(int const posX, int const posY, int const id, CollisionComponent* collisionComponent, Canvas* mainCanvas)
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

void SceneDefaults::Movement(Canvas* mainCanvas)
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
							if (this->IsPositionFree(positionComponent->posX + x, positionComponent->posY + y - 1, ENTITIES[e], collisionComponent, mainCanvas) == false)
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
							if (this->IsPositionFree(positionComponent->posX + x, positionComponent->posY + y + 1, ENTITIES[e], collisionComponent, mainCanvas) == false)
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
							if (this->IsPositionFree(positionComponent->posX + x + 1, positionComponent->posY + y, ENTITIES[e], collisionComponent, mainCanvas) == false)
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
							if (this->IsPositionFree(positionComponent->posX + x - 1, positionComponent->posY + y, ENTITIES[e], collisionComponent, mainCanvas) == false)
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

void SceneDefaults::UpdateSpikeTraps(Canvas * console)
{
	float timePoint = Application::GetGlobalTimer();

	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<SpikeTrapComponent>(),
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<SpriteComponent>(),
			ECS::GetAllIDFrom<CollisionComponent>(),
			ECS::GetAllIDFrom<ConsoleOutputComponent>()
		});

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		SpikeTrapComponent* spikeTrapComponent = ECS::Get<SpikeTrapComponent>(ENTITIES[e]);
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);
		SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(ENTITIES[e]);
		CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(ENTITIES[e]);
		ConsoleOutputComponent* consoleOutputComponent = ECS::Get<ConsoleOutputComponent>(ENTITIES[e]);

		PositionComponent* playerPositionComponent = ECS::Get<PositionComponent>(PLAYER);
		LifeComponent* playerLifeComponent = ECS::Get<LifeComponent>(PLAYER);

		if (spikeTrapComponent &&
			spikeTrapComponent->isActive &&
			positionComponent && 
			positionComponent->isActive &&
			playerPositionComponent &&
			playerPositionComponent->isActive &&
			spriteComponent &&
			spriteComponent->isActive &&
			collisionComponent &&
			collisionComponent->isActive 
			)
		{
			if (playerPositionComponent->posX == positionComponent->posX &&
				playerPositionComponent->posY == positionComponent->posY)
			{
				if (spikeTrapComponent->activated == false)
				{
					spikeTrapComponent->activated = true;
					spikeTrapComponent->timeToAttack = timePoint + spikeTrapComponent->attackDelay;
				}
			}			
			if (spikeTrapComponent->timeToAttack < timePoint)
			{
				if (spikeTrapComponent->activated == false)
				{
					collisionComponent->collisionSetting = CollisionTypes::NONE;
					spriteComponent->sprite[0] = { 'O' };
				}
				else
				{
					collisionComponent->collisionSetting = CollisionTypes::SOLID;
					spriteComponent->sprite[0] = { '^' };

					if (playerPositionComponent->posX == positionComponent->posX &&
						playerPositionComponent->posY == positionComponent->posY &&
						playerLifeComponent && playerLifeComponent->isActive)
					{
						if (consoleOutputComponent && consoleOutputComponent->isActive)
						{
							consoleQueue.insert(consoleQueue.begin(), consoleOutputComponent->output[consoleOutputComponent->iterator]);
							console->SetDrawThisTick(true);
						}

						playerLifeComponent->life--;
					}
					spikeTrapComponent->activated = false;
				}	

				spikeTrapComponent->timeToAttack = timePoint + spikeTrapComponent->activeTime;
			}
		}
	}
}

void SceneDefaults::PlayerRespawn() 
{
	SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(PLAYER_SPAWNPOINT);
	LifeComponent* playerLifeComponent = ECS::Get<LifeComponent>(PLAYER);

	if (playerSpawnTime + 2 < Application::GetGlobalTimer() && spriteComponent)
	{
		spriteComponent->isActive = false;
	}

	if (playerLifeComponent && playerLifeComponent->isActive && playerLifeComponent->life < 1 && spriteComponent)
	{
		playerLifeComponent->life = playerLifeComponent->maxLife;
		ECS::Get<PositionComponent>(PLAYER)->posX = ECS::Get<PositionComponent>(PLAYER_SPAWNPOINT)->posX;
		ECS::Get<PositionComponent>(PLAYER)->posY = ECS::Get<PositionComponent>(PLAYER_SPAWNPOINT)->posY;
		playerSpawnTime = Application::GetGlobalTimer();
		spriteComponent->isActive = true;
	}
}

void SceneDefaults::UpdateEnemyPatrols()
{
	float timePoint = Application::GetGlobalTimer();

	const std::vector<int> ENTITIES = Application::ExtractSameInts(
		{
			ECS::GetAllIDFrom<EnemyPatrolComponent>(),
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<SpriteComponent>(),
			ECS::GetAllIDFrom<CollisionComponent>(),
			ECS::GetAllIDFrom<MotionComponent>()
		});

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		EnemyPatrolComponent* enemyPatrolComponent = ECS::Get<EnemyPatrolComponent>(ENTITIES[e]);
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);
		SpriteComponent* spriteComponent = ECS::Get<SpriteComponent>(ENTITIES[e]);
		CollisionComponent* collisionComponent = ECS::Get<CollisionComponent>(ENTITIES[e]);
		MotionComponent* motionComponent = ECS::Get<MotionComponent>(ENTITIES[e]);

		PositionComponent* playerPositionComponent = ECS::Get<PositionComponent>(PLAYER);
		LifeComponent* playerLifeComponent = ECS::Get<LifeComponent>(PLAYER);

		if (enemyPatrolComponent &&
			enemyPatrolComponent->isActive &&
			positionComponent &&
			positionComponent->isActive &&
			playerPositionComponent &&
			playerPositionComponent->isActive &&
			spriteComponent &&
			spriteComponent->isActive &&
			collisionComponent &&
			collisionComponent->isActive &&
			motionComponent &&
			motionComponent->isActive
			)
		{
			if (enemyPatrolComponent->aY - enemyPatrolComponent->bY != 0)
			{
				if (positionComponent->posY == enemyPatrolComponent->aY)
				{
					motionComponent->down = 1;
					motionComponent->up = 0;
				}
				else if (positionComponent->posY == enemyPatrolComponent->bY)
				{
					motionComponent->down = 0;
					motionComponent->up = 1;
				}
			}
			else if(enemyPatrolComponent->aX - enemyPatrolComponent->bX != 0)
			{
				if (positionComponent->posX == enemyPatrolComponent->aX)
				{
					motionComponent->right = 1;
					motionComponent->left = 0;
				}
				else if (positionComponent->posX == enemyPatrolComponent->bX)
				{
					motionComponent->right = 0;
					motionComponent->left = 1;
				}
			}

			if (enemyPatrolComponent->timeToAttack < timePoint)
			{
				if (playerPositionComponent->posX == positionComponent->posX &&
					playerPositionComponent->posY == positionComponent->posY)
				{
					playerLifeComponent->life--;
					enemyPatrolComponent->timeToAttack = timePoint + enemyPatrolComponent->attackInterval;
				}
			}
		}
	}
}
