#include "scenedefaults.h"
#include "ecs.h"
#include "globalenums.h"
#include "rectanglebuffers.h"

SceneDefaults::SceneDefaults()
{
	continueUpdate = true;
	playerSpawnTime = 0;

	RectangleBuffers consoleBuffers = RectangleBuffers(char(32), char(205), char(186), char(201), char(187), char(188), char(200), Application::GetConsoleWidth(), 6, 8, 3);
	console = Canvas(0, Application::GetConsoleHeight() - 6, 0, *consoleBuffers.GetCharBuffer(), *consoleBuffers.GetColorBuffer());

	RectangleBuffers statsBuffers = RectangleBuffers(char(147), char(147), char(147), char(147), char(147), char(147), char(147), Application::GetConsoleWidth(), 2, 8, 8);
	playerStats = Canvas(0, Application::GetConsoleHeight() - 8, 15, *statsBuffers.GetCharBuffer(), *statsBuffers.GetColorBuffer());
}

SceneDefaults::~SceneDefaults()
{
	console.Erase();
	playerStats.Erase();
}

void SceneDefaults::PlayerInputMovement()
{
	if (MotionComponent* motionComponent = ECS::Get<MotionComponent>(Entities::PLAYER))
	{
		motionComponent->up = 0;
		motionComponent->down = 0;
		motionComponent->left = 0;
		motionComponent->right = 0;

		if (inputCommand == ' ')
		{
			isInputBlockerActive = false;
		}
		else
		{
			if (isInputBlockerActive == false)
			{
				motionComponent->timeToMove = 0;
				isInputBlockerActive = true;
			}
		}
		if (inputCommand == 'W')
		{
			motionComponent->up = 1;
		}
		if (inputCommand == 'A')
		{
			motionComponent->left = 1;
		}
		if (inputCommand == 'S')
		{
			motionComponent->down = 1;
		}
		if (inputCommand == 'D')
		{
			motionComponent->right = 1;
		}
	}
}

void SceneDefaults::PlayerInteract()
{
	int const other = GetInteractableNearPlayer();

	if (other)
	{
		PlayerInteractBackpack(other);
		PlayerInteractDoors(other);
		PlayerInteractTrees(other);
	}
}

void SceneDefaults::PlayerInteractBackpack(int const other)
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

void SceneDefaults::PlayerInteractDoors(int const other)
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

void SceneDefaults::PlayerInteractTrees(int const other)
{
	float timePoint = Application::GetGlobalTimer();

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
						console.SetDrawThisTick(true);

						treeComponent->chops--;
							
						backpackComponent->items[LOG]++;

						return;
					case 1:
						if (SpriteComponent * spriteComponent = ECS::Get<SpriteComponent>(other))
						{
							spriteComponent->sprite = { { '#' } };
						}

						consoleQueue.insert(consoleQueue.begin(), "(chop)");
						console.SetDrawThisTick(true);

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
						console.SetDrawThisTick(true);

						treeComponent->chops--;
							
						backpackComponent->items[LOG]++;

						return;
					case 3:
						if (SpriteComponent * spriteComponent = ECS::Get<SpriteComponent>(other))
						{
							spriteComponent->sprite[0][0] = '#';

							spriteComponent->color[0][0] = 0xA6;
						}

						consoleQueue.insert(consoleQueue.begin(), "(chop)");
						console.SetDrawThisTick(true);

						treeComponent->chops--;
						return;
					case 4:
						if (SpriteComponent * spriteComponent = ECS::Get<SpriteComponent>(other))
						{
							spriteComponent->sprite[0][0] = char(240);
							spriteComponent->sprite[0][1] = '.';
						}

						consoleQueue.insert(consoleQueue.begin(),"(chop)");
						console.SetDrawThisTick(true);

						treeComponent->chops--;
						return;
					}
				}
			}
		}
	}
}

int SceneDefaults::GetInteractableNearPlayer()
{
	float const timePoint = Application::GetGlobalTimer();

	if (inputCommand == 'E' && playerSpawnTime + 0.2f < timePoint && interactTime < timePoint)
	{
		if (PositionComponent * positionComponent = ECS::Get<PositionComponent>(Entities::PLAYER))
		{
			for (short x = -1; x != 2; x++)
			{
				for (short y = -1; y != 2; y++)
				{
					if (x == 0 && y == 0)
					{
						continue;
					}

					if (int other = GetEntityAt(positionComponent->posX + x, positionComponent->posY + y, Entities::PLAYER))
					{
						if (ConsoleOutputComponent * consoleOutputComponent = ECS::Get<ConsoleOutputComponent>(other))
						{
							consoleQueue.insert(consoleQueue.begin(), consoleOutputComponent->output[consoleOutputComponent->iterator]);
								
							if (consoleOutputComponent->iterator < consoleOutputComponent->output.size() - 1)
							{
								ECS::Get<MotionComponent>(PLAYER)->isActive = false;
								consoleOutputComponent->iterator++;
							}
							else
							{
								ECS::Get<MotionComponent>(PLAYER)->isActive = true;
								consoleOutputComponent->reachedEnd = true;
							}

							console.SetDrawThisTick(true);
						}

						interactTime = timePoint + 1.0f;

						return other;
					}
				}
			}
		}
	}

	return 0;
}

void SceneDefaults::PlayerInputEscape()
{
	if (inputCommand == VK_ESCAPE)
	{
		nextScene = Scenes::MAINMENU;
		continueUpdate = false;
	}
}

void SceneDefaults::ExecuteOrder66()
{
	for (int i = (int)killQueue.size() - 1; !killQueue.empty(); i--)
	{
		int const id = killQueue[i];

		ECS::Destroy<PositionComponent>(id);
		ECS::Destroy<SpriteComponent>(id);
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

void SceneDefaults::DrawConsole()
{
	if (console.GetDrawThisTick() == true)
	{
		while (consoleQueue.size() + 2 > console.GetHeight())
		{
			consoleQueue.pop_back();
		}

		for (int i = 0; i != consoleQueue.size(); i++)
		{
			console.PutString(std::string(console.GetWidth() - 2, ' '), 1, 1 + i, 0x0A, false);

			if (i == 0)
			{
				int cPos = 0;
				for (const char c : consoleQueue[i])
				{
					console.PutChar(c, 1 + cPos, 1 + i, 0x0A);
					console.Draw();
					Sleep(30);
					cPos++;
				}
				//console.PutString(consoleQueue[i], 1, 1 + i, 0x0A, false);
			}
			else
			{
				console.PutString(consoleQueue[i], 1, 1 + i, 8, false);
			}
		}

		console.Draw();
		console.SetDrawThisTick(false);
	}
}

void SceneDefaults::DrawPlayerStats()
{
	if (playerStats.GetDrawThisTick() == true)
	{
		float timePoint = Application::GetGlobalTimer();
		LifeComponent* lifeComponent = ECS::Get<LifeComponent>(PLAYER);

		if (lifeComponent->timeToDamage > timePoint)
		{
			playerStats.PutString(std::string(playerStats.GetWidth(), ' '), 0, 1, 0xCC, false);
			playerStats.Draw();
			return;
		}

		playerStats.SetBuffersToZero();

		playerStats.PutString("Health: " + std::to_string(lifeComponent->health) + "/" + std::to_string(lifeComponent->maxHealth), 1, 1, 0x0A, false);
		playerStats.PutString("Lives: " + std::to_string(lifeComponent->lives) + "/" + std::to_string(lifeComponent->maxLives), 21, 1, 0x0A, false);

		playerStats.Draw();

		playerStats.SetDrawThisTick(false);
	}
}

void SceneDefaults::HidePlayerStats()
{
	playerStats.PutString(std::string(playerStats.GetWidth(), ' '), 0, 1, 0x00, false);
	playerStats.Draw();
}

void SceneDefaults::ZeroCanvasBuffers(Canvas * canvas)
{
	canvas->SetBuffersToZero();
}

void SceneDefaults::ReadInput()
{
	int i = 0;

	for (i = 0; i < vKeys.size(); i++)
	{
		if (Application::InputAsync(vKeys[i]) & 0x8000)
		{
			if ((!vKeysAsync[i] && !vKeysPressed[i]) || vKeysAsync[i])
			{
				inputCommand = toascii(vKeys[i]);
				vKeysPressed[i] = true;
				return;
			}
		}
	}
	if (i == vKeys.size())
	{
		for (i = 0; i < vKeys.size(); i++)
		{
			vKeysPressed[i] = false;
		}

		inputCommand = ' ';
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

void SceneDefaults::MovementPathing(unsigned int const id)
{
	MotionComponent* motionComponent = ECS::Get<MotionComponent>(id);
	PositionComponent* positionComponent = ECS::Get<PositionComponent>(id);

	const std::vector<MotionComponent::PathNode>* path = &motionComponent->pathNodes;

	for (int n = 0; n < path->size(); n++)
	{
		MotionComponent::PathNode node = path->at(n);

		if (positionComponent->posX == node.position.posX &&
			positionComponent->posY == node.position.posY)
		{
			motionComponent->up = node.up;
			motionComponent->left = node.left;
			motionComponent->right = node.right;
			motionComponent->down = node.down;
		}
	}
}

void SceneDefaults::UpdateSpikeTraps()
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
		ConsoleOutputComponent* cconsoleOutputComponent = ECS::Get<ConsoleOutputComponent>(ENTITIES[e]);

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
						//if (consoleOutputComponent && consoleOutputComponent->isActive)
						//{
						//	consoleQueue.insert(consoleQueue.begin(), consoleOutputComponent->output[consoleOutputComponent->iterator]);
						//	console.SetDrawThisTick(true);
						//}

						playerLifeComponent->lives--;
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

	if (playerLifeComponent && playerLifeComponent->isActive && playerLifeComponent->health < 1 && spriteComponent)
	{
		if (ConsoleOutputComponent * consoleOutputComponent = ECS::Get<ConsoleOutputComponent>(PLAYER_SPAWNPOINT))
		{
			consoleQueue.insert(consoleQueue.begin(), consoleOutputComponent->output[consoleOutputComponent->iterator]);
			console.SetDrawThisTick(true);
		}

		playerStats.SetDrawThisTick(true);

		playerLifeComponent->health = playerLifeComponent->maxHealth;
		playerLifeComponent->lives--;

		if (playerLifeComponent->lives == 0)
		{
			nextScene = MAINMENU;
			continueUpdate = false;
		}

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
			ECS::GetAllIDFrom<MotionPatrolComponent>(),
			ECS::GetAllIDFrom<PositionComponent>(),
			ECS::GetAllIDFrom<MotionComponent>(),
			ECS::GetAllIDFrom<AttackComponent>()
		});

	for (int e = 0; e < ENTITIES.size(); e++)
	{
		MotionPatrolComponent* motionPatrolComponent = ECS::Get<MotionPatrolComponent>(ENTITIES[e]);
		PositionComponent* positionComponent = ECS::Get<PositionComponent>(ENTITIES[e]);
		MotionComponent* motionComponent = ECS::Get<MotionComponent>(ENTITIES[e]);
		AttackComponent* attackComponent = ECS::Get<AttackComponent>(ENTITIES[e]);

		PositionComponent* playerPositionComponent = ECS::Get<PositionComponent>(PLAYER);
		LifeComponent* playerLifeComponent = ECS::Get<LifeComponent>(PLAYER);

		if (motionPatrolComponent &&
			motionPatrolComponent->isActive &&
			positionComponent &&
			positionComponent->isActive &&
			playerPositionComponent &&
			playerPositionComponent->isActive &&
			motionComponent &&
			motionComponent->isActive &&
			attackComponent &&
			attackComponent->isActive
			)
		{
			if (motionPatrolComponent->aY - motionPatrolComponent->bY != 0)
			{
				if (positionComponent->posY == motionPatrolComponent->aY)
				{
					motionComponent->down = 1;
					motionComponent->up = 0;
				}
				else if (positionComponent->posY == motionPatrolComponent->bY)
				{
					motionComponent->down = 0;
					motionComponent->up = 1;
				}
			}
			else if(motionPatrolComponent->aX - motionPatrolComponent->bX != 0)
			{
				if (positionComponent->posX == motionPatrolComponent->aX)
				{
					motionComponent->right = 1;
					motionComponent->left = 0;
				}
				else if (positionComponent->posX == motionPatrolComponent->bX)
				{
					motionComponent->right = 0;
					motionComponent->left = 1;
				}
			}

			if (attackComponent->timeToAttack < timePoint)
			{
				if (playerPositionComponent->posX == positionComponent->posX &&
					playerPositionComponent->posY == positionComponent->posY && 
					playerLifeComponent->timeToDamage < timePoint)
				{
					playerLifeComponent->health -= attackComponent->damage;
					playerLifeComponent->timeToDamage = timePoint + playerLifeComponent->immunityTime;
					playerStats.SetDrawThisTick(true);
					attackComponent->timeToAttack = timePoint + attackComponent->attackInterval;
				}
			}
		}
	}
}
