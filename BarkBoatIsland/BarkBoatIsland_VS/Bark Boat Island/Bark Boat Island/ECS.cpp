#include "ecs.h"

#pragma region MOTION
MotionComponent::MotionComponent()
{
	this->up = 0;
	this->down = 0;
	this->left = 0;
	this->right = 0;
	this->movementRate = 0.0f;
	this->timeToMove = 0.0f;
	this->footprint = char();
	this->footprintColor = 15;
}

MotionComponent::MotionComponent(bool up, bool down, bool left, bool right, float movementRate, int footprintColor, char footprint)
{
	this->up = up;
	this->down = down;
	this->left = left;
	this->right = right;
	this->movementRate = movementRate;
	this->timeToMove = 0.0f;
	this->footprint = footprint;
	this->footprintColor = footprintColor;
}

#pragma endregion

#pragma region POSITION
PositionComponent::PositionComponent(int const x, int const y)
{
	this->posX = x;
	this->posY = y;
}
#pragma endregion

#pragma region SPRITE
SpriteComponent::SpriteComponent()
{
	this->sprite = ' ';
	this->color = 15;
	this->drawLayer = 0;
}
SpriteComponent::SpriteComponent(char const body, int const color, short const drawLayer)
{
	this->sprite = body;
	this->color = color;
	this->drawLayer = drawLayer;
}
#pragma endregion

#pragma region INPUT
InputComponent::InputComponent()
{
	this->command = ' ';
	this->hasClicked = false;
}
#pragma endregion

#pragma region SCENE
SceneComponent::SceneComponent(short nextScene)
{
	this->nextScene = nextScene;
}
#pragma endregion


#pragma region LOCK
LockComponent::LockComponent(int const key)
{
	this->key = key;
}
#pragma endregion

#pragma region NEARBY
NearbyComponent::NearbyComponent()
{

}
#pragma endregion

#pragma region COLLISION
CollisionComponent::CollisionComponent()
{
	this->collisionSetting = 0;
}

CollisionComponent::CollisionComponent(int setting)
{
	this->collisionSetting = setting;
}
#pragma endregion

#pragma region LIFE
LifeComponent::LifeComponent(int life)
{
	this->life = life;
}
#pragma endregion

#pragma region ATTACK
AttackComponent::AttackComponent(int damage)
{
	this->damage = damage;
}
#pragma endregion

namespace ECS
{
	void AssignScene(Scene& sceneToAssign)
	{
		scene = &sceneToAssign;
	}

	void Systems::ExecuteOrder66()
	{
		for (int i = killQueue.size()-1; !killQueue.empty(); i--)
		{
			int const id = killQueue[i];

			Destroy<PositionComponent>(id); //killQueue.emplace_back(ENTITIES[x]);
			Destroy<SpriteComponent>(id);
			Destroy<InputComponent>(id);
			Destroy<MotionComponent>(id);
			Destroy<NearbyComponent>(id);
			Destroy<BackpackComponent>(id);
			Destroy<BackpackItemComponent>(id);
			killQueue.pop_back();
		}
	}

	void Systems::Draw()
	{
		const std::vector<int> ENTITIES = Application::ExtractSameInts(
			{
				GetAllIDFrom<PositionComponent>(),
				GetAllIDFrom<SpriteComponent>()
			});


		for (short drawLayer = 0; drawLayer < scene->NUMBER_OF_DRAW_LAYERS; drawLayer++)
		{
			for (int e = 0; e < ENTITIES.size(); e++)
			{
				SpriteComponent* spriteComponent = Get<SpriteComponent>(ENTITIES[e]);
				PositionComponent* positionComponent = Get<PositionComponent>(ENTITIES[e]);

				if (spriteComponent->drawLayer == drawLayer)
				{
					scene->DrawSprite(spriteComponent->sprite, positionComponent->posX, positionComponent->posY, spriteComponent->color);
				}
			}
		}
	}

	void Systems::Input()
	{
		const std::array<int, 5> vKeys {0x41, 0x57, 0x53, 0x44, 0x45};

		const std::vector<int> ENTITIES = GetAllIDFrom<InputComponent>();
	
		for (int e = 0; e < ENTITIES.size(); e++)
		{
			InputComponent* inputComponent = Get<InputComponent>(ENTITIES[e]);

			//Read input
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

			//Process input
			
			if(MotionComponent* motionComponent = Get<MotionComponent>(ENTITIES[e]))
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

			if (NearbyComponent* nearbyComponent = Get<NearbyComponent>(ENTITIES[e]))
			{
				if (inputComponent->command == 'E')
				{
					if (BackpackComponent* backpackComponent = Get<BackpackComponent>(ENTITIES[e]))
					{
						if (Get<BackpackItemComponent>(nearbyComponent->nbrUp))
						{
							backpackComponent->items.emplace_back(nearbyComponent->nbrUp);
							PositionComponent* positionComponent = Get<PositionComponent>(nearbyComponent->nbrUp);
							scene->DrawSprite(scene->GetFloor(), positionComponent->posX, positionComponent->posY, scene->GetFloorColor());
							Destroy<PositionComponent>(nearbyComponent->nbrUp);
						}
						else if (Get<BackpackItemComponent>(nearbyComponent->nbrDown))
						{
							backpackComponent->items.emplace_back(nearbyComponent->nbrDown);
							PositionComponent* positionComponent = Get<PositionComponent>(nearbyComponent->nbrDown);
							scene->DrawSprite(scene->GetFloor(), positionComponent->posX, positionComponent->posY, scene->GetFloorColor());
							Destroy<PositionComponent>(nearbyComponent->nbrDown);
						}
						else if (Get<BackpackItemComponent>(nearbyComponent->nbrLeft))
						{
							backpackComponent->items.emplace_back(nearbyComponent->nbrLeft);
							PositionComponent* positionComponent = Get<PositionComponent>(nearbyComponent->nbrLeft);
							scene->DrawSprite(scene->GetFloor(), positionComponent->posX, positionComponent->posY, scene->GetFloorColor());
							Destroy<PositionComponent>(nearbyComponent->nbrLeft);
						}
						else if (Get<BackpackItemComponent>(nearbyComponent->nbrRight))
						{
							backpackComponent->items.emplace_back(nearbyComponent->nbrRight);
							PositionComponent* positionComponent = Get<PositionComponent>(nearbyComponent->nbrRight);
							scene->DrawSprite(scene->GetFloor(), positionComponent->posX, positionComponent->posY, scene->GetFloorColor());
							Destroy<PositionComponent>(nearbyComponent->nbrRight);
						}

						if (SceneComponent* sceneComponent = Get<SceneComponent>(nearbyComponent->nbrRight))
						{
							if (LockComponent* lockComponent = Get<LockComponent>(nearbyComponent->nbrRight))
							{
								for (int i = 0; i < backpackComponent->items.size(); i++)
								{
									if (lockComponent->key == ECS::Get<BackpackItemComponent>(backpackComponent->items[i])->type)
									{
										scene->SetNextSceneName(sceneComponent->nextScene);
										scene->SetIsPlaying(false);
									}
								}
							}
							else
							{
								scene->SetNextSceneName(sceneComponent->nextScene);
								scene->SetIsPlaying(false);
							}
						}
						if (SceneComponent* sceneComponent = Get<SceneComponent>(nearbyComponent->nbrLeft))
						{
							if (LockComponent* lockComponent = Get<LockComponent>(nearbyComponent->nbrLeft))
							{
								for (int i = 0; i < backpackComponent->items.size(); i++)
								{
									if (lockComponent->key == ECS::Get<BackpackItemComponent>(backpackComponent->items[i])->type)
									{
										scene->SetNextSceneName(sceneComponent->nextScene);
										scene->SetIsPlaying(false);
									}
								}
							}
							else
							{
								scene->SetNextSceneName(sceneComponent->nextScene);
								scene->SetIsPlaying(false);
							}
						}
						if (SceneComponent* sceneComponent = Get<SceneComponent>(nearbyComponent->nbrDown))
						{
							if (LockComponent* lockComponent = Get<LockComponent>(nearbyComponent->nbrDown))
							{
								for (int i = 0; i < backpackComponent->items.size(); i++)
								{
									if (lockComponent->key == ECS::Get<BackpackItemComponent>(backpackComponent->items[i])->type)
									{
										scene->SetNextSceneName(sceneComponent->nextScene);
										scene->SetIsPlaying(false);
									}
								}
							}
							else
							{
								scene->SetNextSceneName(sceneComponent->nextScene);
								scene->SetIsPlaying(false);
							}
						}
						if (SceneComponent* sceneComponent = Get<SceneComponent>(nearbyComponent->nbrUp))
						{
							if (LockComponent* lockComponent = Get<LockComponent>(nearbyComponent->nbrUp))
							{
								for (int i = 0; i < backpackComponent->items.size(); i++)
								{
									if (lockComponent->key == ECS::Get<BackpackItemComponent>(backpackComponent->items[i])->type)
									{
										scene->SetNextSceneName(sceneComponent->nextScene);
										scene->SetIsPlaying(false);
									}
								}
							}
							else
							{
								scene->SetNextSceneName(sceneComponent->nextScene);
								scene->SetIsPlaying(false);
							}
						}
					}
				}
			}
		}
	}

	void Systems::Movement()
	{
		float timePoint = Application::GetGlobalTimer();

		const std::vector<int> ENTITIES_NEARBY = GetAllIDFrom<PositionComponent>();

		const std::vector<int> ENTITIES = Application::ExtractSameInts(
			{
				GetAllIDFrom<CollisionComponent>(),
				GetAllIDFrom<NearbyComponent>(),
				GetAllIDFrom<PositionComponent>(),
				GetAllIDFrom<MotionComponent>()
			});

		for (int e = 0; e < ENTITIES.size(); e++)
		{
			CollisionComponent* collisionComponent = Get<CollisionComponent>(ENTITIES[e]);
			PositionComponent* positionComponent = Get<PositionComponent>(ENTITIES[e]);
			NearbyComponent* nearbyComponent = Get<NearbyComponent>(ENTITIES[e]);
			MotionComponent* motionComponent = Get<MotionComponent>(ENTITIES[e]);

			//Define nearby entities
			//Check world first
			nearbyComponent->nbrRight = (scene->TryPositionIsFloor(positionComponent->posX + 1, positionComponent->posY)) ? (scene->floorID) : (scene->wallID);
			nearbyComponent->nbrLeft = (scene->TryPositionIsFloor(positionComponent->posX - 1, positionComponent->posY)) ? (scene->floorID) : (scene->wallID);
			nearbyComponent->nbrDown = (scene->TryPositionIsFloor(positionComponent->posX, positionComponent->posY + 1)) ? (scene->floorID) : (scene->wallID);
			nearbyComponent->nbrUp = (scene->TryPositionIsFloor(positionComponent->posX, positionComponent->posY - 1)) ? (scene->floorID) : (scene->wallID);

			//Check other entities
			PositionComponent* nearbyPositionComponent = nullptr;
			for (int eN = 0; eN < ENTITIES_NEARBY.size(); eN++)
			{
				if (eN != e)
				{
					nearbyPositionComponent = Get<PositionComponent>(ENTITIES_NEARBY[eN]);

					if (positionComponent->posX == nearbyPositionComponent->posX)
					{
						if (positionComponent->posY - 1 == nearbyPositionComponent->posY)
						{
							nearbyComponent->nbrUp = ENTITIES_NEARBY[eN];
						}
						else if (positionComponent->posY + 1 == nearbyPositionComponent->posY)
						{
							nearbyComponent->nbrDown = ENTITIES_NEARBY[eN];
						}
					}
					else if (positionComponent->posY == nearbyPositionComponent->posY)
					{
						if (positionComponent->posX - 1 == nearbyPositionComponent->posX)
						{
							nearbyComponent->nbrLeft = ENTITIES_NEARBY[eN];
						}
						else if (positionComponent->posX + 1 == nearbyPositionComponent->posX)
						{
							
							nearbyComponent->nbrRight = ENTITIES_NEARBY[eN];
						}
					}
				}
			}

			if (motionComponent->movementRate == 0.0f || motionComponent->timeToMove < timePoint)
			{
				if (motionComponent->footprint == char())
				{
					motionComponent->footprint = scene->GetFloor();
				}

				if (motionComponent->up != 0)
				{
					CollisionComponent* nearbyCollisionComponent = Get<CollisionComponent>(nearbyComponent->nbrUp);
					NearbyComponent* nearbyNearbyComponent = Get<NearbyComponent>(nearbyComponent->nbrUp);

					if (nearbyComponent->nbrUp == scene->floorID ||
						(nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting != 2 && nearbyCollisionComponent->collisionSetting != 3 && (collisionComponent->collisionSetting == 1 || nearbyCollisionComponent->collisionSetting == 1)) ||
						(nearbyCollisionComponent == nullptr && nearbyComponent->nbrUp > 0))
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posY -= motionComponent->up;
					}
					else if (nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting == 3 && nearbyPositionComponent != nullptr && nearbyNearbyComponent != nullptr && nearbyNearbyComponent->nbrUp == scene->floorID)
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posY -= motionComponent->up;
						nearbyPositionComponent->posY -= motionComponent->up;
					}
				}
				if (motionComponent->down != 0)
				{
					CollisionComponent* nearbyCollisionComponent = Get<CollisionComponent>(nearbyComponent->nbrDown);
					NearbyComponent* nearbyNearbyComponent = Get<NearbyComponent>(nearbyComponent->nbrDown);

					if (nearbyComponent->nbrDown == scene->floorID ||
						(nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting != 2 && nearbyCollisionComponent->collisionSetting != 3 && (collisionComponent->collisionSetting == 1 || nearbyCollisionComponent->collisionSetting == 1)) ||
						(nearbyCollisionComponent == nullptr && nearbyComponent->nbrDown > 0))
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posY += motionComponent->down;
					}
					else if (nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting == 3 && nearbyPositionComponent != nullptr && nearbyNearbyComponent != nullptr && nearbyNearbyComponent->nbrDown == scene->floorID)
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posY += motionComponent->down;
						nearbyPositionComponent->posY += motionComponent->down;
					}
				}
				if (motionComponent->left != 0)
				{
					CollisionComponent* nearbyCollisionComponent = Get<CollisionComponent>(nearbyComponent->nbrLeft);
					NearbyComponent* nearbyNearbyComponent = Get<NearbyComponent>(nearbyComponent->nbrLeft);

					if (nearbyComponent->nbrLeft == scene->floorID ||
						(nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting != 2 && nearbyCollisionComponent->collisionSetting != 3 && (collisionComponent->collisionSetting == 1 || nearbyCollisionComponent->collisionSetting == 1)) ||
						(nearbyCollisionComponent == nullptr && nearbyComponent->nbrLeft > 0))
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posX -= motionComponent->left;
					}
					else if (nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting == 3 && nearbyPositionComponent != nullptr && nearbyNearbyComponent != nullptr && nearbyNearbyComponent->nbrLeft == scene->floorID)
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posX -= motionComponent->left;
						nearbyPositionComponent->posX -= motionComponent->left;
					}
				}
				if (motionComponent->right != 0)
				{
					CollisionComponent* nearbyCollisionComponent = Get<CollisionComponent>(nearbyComponent->nbrRight);
					NearbyComponent* nearbyNearbyComponent = Get<NearbyComponent>(nearbyComponent->nbrRight);
					
					if (nearbyComponent->nbrRight == scene->floorID ||
						(nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting != 2 && nearbyCollisionComponent->collisionSetting != 3 && (collisionComponent->collisionSetting == 1 || nearbyCollisionComponent->collisionSetting == 1)) ||
						(nearbyCollisionComponent == nullptr && nearbyComponent->nbrRight > 0))
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posX += motionComponent->right;
					}
					else if (nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting == 3 && nearbyPositionComponent != nullptr && nearbyNearbyComponent != nullptr && nearbyNearbyComponent->nbrRight == scene->floorID)
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posX += motionComponent->right;
						nearbyPositionComponent->posX += motionComponent->right;
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
}




//void ECS::Attack(Room &room)
//{
//	typedef std::map<int, Entity*>::const_iterator const_map_iter;
//	const_map_iter entityIterator = theEntityManager.getMap()->begin();
//	const_map_iter otherIterator = theEntityManager.getMap()->begin();
//
//	LifeComponent* lifeComp;
//	PositionComponent* posComp;
//
//	PositionComponent* otherPosComp;
//	AttackComponent* otherAttackComp;
//
//	while (entityIterator != theEntityManager.getMap()->end()) {
//
//		lifeComp = theComponentManagers.theLifeManager.getComponent(entityIterator->first);
//		posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);
//
//		if (posComp != nullptr &&
//			lifeComp != nullptr)
//		{
//			while (otherIterator != theEntityManager.getMap()->end()) {
//				otherPosComp = theComponentManagers.thePositionManager.getComponent(otherIterator->first);
//				otherAttackComp = theComponentManagers.theAttackManager.getComponent(otherIterator->first);
//
//				if (otherPosComp != nullptr &&
//					otherAttackComp != nullptr &&
//					posComp->posX == otherPosComp->posX &&
//					posComp->posY == otherPosComp->posY &&
//					otherIterator->first != entityIterator->first)
//				{
//					lifeComp->life -= otherAttackComp->damage;
//
//					//special case for player
//					if (entityIterator->first == 1) 
//					{
//						theComponentManagers.thePositionManager.getComponent(1)->posX = theComponentManagers.thePositionManager.getComponent(2)->posX;
//						theComponentManagers.thePositionManager.getComponent(1)->posY = theComponentManagers.thePositionManager.getComponent(2)->posY;
//						room.SetNextRoomName(room.GetName());
//						room.SetIsPlaying(false);
//					}
//				}
//				++otherIterator;
//			}
//			otherIterator = theEntityManager.getMap()->begin();
//
//			if (lifeComp->life <= 0)
//			{
//				room.DrawSprite(char(32), posComp->posX, posComp->posY);
//				theEntityManager.destroyEntity(theEntityManager.getEntity(entityIterator->first));
//				entityIterator = theEntityManager.getMap()->begin();
//			}
//		}
//		++entityIterator;
//	}
//}
//
//
//void ECS::Platform()
//{
//	typedef std::map<int, Entity*>::const_iterator const_map_iter;
//	const_map_iter entityIterator = theEntityManager.getMap()->begin();
//	const_map_iter otherIterator = theEntityManager.getMap()->begin();
//
//	PlatformComponent* platformComp;
//	PositionComponent* posComp;
//	MotionComponent* motionComp;
//
//	PositionComponent* otherPosComp;
//	MotionComponent* otherMotionComp;
//	PlatformRiderComponent* otherPlatformRiderComp;
//
//	while (entityIterator != theEntityManager.getMap()->end()) {
//		
//		platformComp = theComponentManagers.thePlatformManager.getComponent(entityIterator->first);
//		posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);
//		motionComp = theComponentManagers.theMotionManager.getComponent(entityIterator->first);
//
//		if (platformComp != nullptr && 
//			posComp != nullptr &&
//			motionComp != nullptr)
//		{
//			while (otherIterator != theEntityManager.getMap()->end()) { 
//				otherPosComp = theComponentManagers.thePositionManager.getComponent(otherIterator->first);
//				otherMotionComp = theComponentManagers.theMotionManager.getComponent(otherIterator->first);
//				otherPlatformRiderComp = theComponentManagers.thePlatformRiderManager.getComponent(otherIterator->first);
//
//				if (otherPosComp != nullptr && entityIterator->first != otherIterator->first)
//				{
//					if (otherMotionComp != nullptr && otherPlatformRiderComp != nullptr)
//					{
//
//						if (otherPosComp->posX == posComp->posX &&
//							otherPosComp->posY == posComp->posY)
//						{
//							if (platformComp->occupied == false)
//							{
//								platformComp->backupMotionComponent.down = otherMotionComp->down;
//								platformComp->backupMotionComponent.up = otherMotionComp->up;
//								platformComp->backupMotionComponent.left = otherMotionComp->left;
//								platformComp->backupMotionComponent.right = otherMotionComp->right;
//								platformComp->backupMotionComponent.footprint = otherMotionComp->footprint;
//								platformComp->backupMotionComponent.movementRate = otherMotionComp->movementRate;
//								platformComp->backupMotionComponent.timeToMove = otherMotionComp->timeToMove;
//								platformComp->occupied = true;
//								otherMotionComp->down = motionComp->down;
//								otherMotionComp->up = motionComp->up;
//								otherMotionComp->left = motionComp->left;
//								otherMotionComp->right = motionComp->right;
//								otherMotionComp->footprint = motionComp->footprint;
//								otherMotionComp->movementRate = motionComp->movementRate;
//								otherMotionComp->timeToMove = motionComp->timeToMove;
//							}
//						}
//						else if(platformComp->occupied == true && 
//								(motionComp->down	!= otherMotionComp->down	|| 
//								motionComp->up		!= otherMotionComp->up		|| 
//								motionComp->left	!= otherMotionComp->left	|| 
//								motionComp->right	!= otherMotionComp->right))
//						{
//							otherMotionComp->down = platformComp->backupMotionComponent.down;
//							otherMotionComp->up = platformComp->backupMotionComponent.up;
//							otherMotionComp->left = platformComp->backupMotionComponent.left;
//							otherMotionComp->right = platformComp->backupMotionComponent.right;
//							otherMotionComp->footprint = platformComp->backupMotionComponent.footprint;
//							otherMotionComp->movementRate = platformComp->backupMotionComponent.movementRate;
//							otherMotionComp->timeToMove = platformComp->backupMotionComponent.timeToMove;
//							platformComp->occupied = false;
//						}
//					}
//				}
//
//				++otherIterator;
//			}
//			otherIterator = theEntityManager.getMap()->begin();
//		}
//		++entityIterator;
//	}
//}
//
//void ECS::InteractAction(Room &room, int const entity, int const other, ConsolePanel *consolePanel)
//{
//	SceneComponent* otherSceneComp = theComponentManagers.theSceneManager.getComponent(other);
//	LockComponent* otherLockComp = theComponentManagers.theLockManager.getComponent(other);
//	InventoryItemComponent* otherInventoryItemComp = theComponentManagers.theInventoryItemManager.getComponent(other);
//	ConsoleOutputComponent* otherConsoleOutComp = theComponentManagers.theConsoleOutputManager.getComponent(other);
//
//	InventoryComponent* inventoryComp = theComponentManagers.theInventoryManager.getComponent(entity);
//	
//	if (otherSceneComp != nullptr)
//	{
//		if (otherLockComp != nullptr)
//		{
//			if (inventoryComp != nullptr)
//			{
//				for (int i = 0; i < inventoryComp->size(); i++)
//				{
//					if(inventoryComp->getEntity(i)->name == otherLockComp->key)
//					{
//						if (otherConsoleOutComp != nullptr)
//						{
//							otherConsoleOutComp->setIterator(-1); //setActive(false);
//						}
//
//						room.SetNextRoomName(otherSceneComp->nextName);
//						room.SetIsPlaying(false);
//						break;
//					}
//				}
//			}
//		}
//		else
//		{
//			room.SetNextRoomName(otherSceneComp->nextName);
//			room.SetIsPlaying(false);
//		}
//	}	
//	//funkar men ändra kanske iterator - 1 till en bool				OutputDebugStringA(std::to_string(vKeys[i]).c_str());
//	if (otherConsoleOutComp != nullptr && otherConsoleOutComp->getIterator() >= 0) //otherConsoleOutComp->getActive())
//	{
//		consolePanel->enqueue(otherConsoleOutComp->getOutput());
//		otherConsoleOutComp->iterate();
//	//sätt iterator - 1 så att sista strängen visas igen om spelaren trycker flera ggr
//		if (otherConsoleOutComp->getOutputSize() <= otherConsoleOutComp->getIterator())
//		{	
//			otherConsoleOutComp->setIterator(otherConsoleOutComp->getOutputSize() - 1);
//		}
//	}
//
//	if (inventoryComp != nullptr &&
//		otherInventoryItemComp != nullptr)
//	{
//		if (inventoryComp->hasEntity(*theEntityManager.getEntity(other)) == false)
//		{
//			inventoryComp->add(*theEntityManager.getEntity(other));
//			theComponentManagers.theInventoryItemManager.getComponent(other)->isInInventory = true;
//			theComponentManagers.theSpriteManager.destroyComponent(other);
//			theComponentManagers.theCollisionManager.destroyComponent(other);
//			
//			room.DrawSprite(room.GetFloor(), theComponentManagers.thePositionManager.getComponent(other)->posX, theComponentManagers.thePositionManager.getComponent(other)->posY, room.GetFloorColor());
//			theComponentManagers.thePositionManager.destroyComponent(other);	
//		}
//	}
//}
//
//void ECS::Interact(Room &room, ConsolePanel *consolePanel)//, ConsolePanel* theConsolePanel, InventoryPanel* theInventoryPanel
//{
//	typedef std::map<int, Entity*>::const_iterator const_map_iter;
//	const_map_iter entityIterator = theEntityManager.getMap()->begin();
//	const_map_iter otherIterator = theEntityManager.getMap()->begin();
//
//	NearbyComponent* nearComp;
//	InputComponent* inputComp;
//	PositionComponent* posComp;
//
//	PositionComponent* otherPosComp;
//
//	while (entityIterator != theEntityManager.getMap()->end()) {
//
//		nearComp = theComponentManagers.theNearbyManager.getComponent(entityIterator->first);
//		inputComp = theComponentManagers.theInputManager.getComponent(entityIterator->first);
//		posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);
//		
//		if (nearComp != nullptr)
//		{
//			if (inputComp != nullptr &&
//				inputComp->command == 'E')
//			{
//				if (nearComp->nbrUp != room.floorID && nearComp->nbrUp != room.wallID)
//				{
//					InteractAction(room, entityIterator->first, nearComp->nbrUp, consolePanel);
//				}
//				else if (nearComp->nbrDown != room.floorID && nearComp->nbrDown != room.wallID)
//				{
//					InteractAction(room, entityIterator->first, nearComp->nbrDown, consolePanel);
//				}
//				else if (nearComp->nbrLeft != room.floorID && nearComp->nbrLeft != room.wallID)
//				{
//					InteractAction(room, entityIterator->first, nearComp->nbrLeft, consolePanel);
//				}
//				else if (nearComp->nbrRight != room.floorID && nearComp->nbrRight != room.wallID)
//				{
//					InteractAction(room, entityIterator->first, nearComp->nbrRight, consolePanel);
//				}
//			}
//
//			if (posComp != nullptr)
//			{
//				if (room.TryPositionIsFloor(posComp->posX + 1, posComp->posY))
//				{
//					nearComp->nbrRight = room.floorID;
//				}
//				else
//				{
//					nearComp->nbrRight = room.wallID;
//				}
//				if (room.TryPositionIsFloor(posComp->posX - 1, posComp->posY))
//				{
//					nearComp->nbrLeft = room.floorID;
//				}
//				else
//				{
//					nearComp->nbrLeft = room.wallID;
//				}
//				if (room.TryPositionIsFloor(posComp->posX, posComp->posY + 1))
//				{
//					nearComp->nbrDown = room.floorID;
//				}
//				else
//				{
//					nearComp->nbrDown = room.wallID;
//				}
//				if (room.TryPositionIsFloor(posComp->posX, posComp->posY - 1))
//				{
//					nearComp->nbrUp = room.floorID;
//				}
//				else
//				{
//					nearComp->nbrUp = room.wallID;
//				}
//
//				while (otherIterator != theEntityManager.getMap()->end())
//				{
//					otherPosComp = theComponentManagers.thePositionManager.getComponent(otherIterator->first);
//
//					if (otherPosComp != nullptr)
//					{
//						if (posComp->posX - 1 == otherPosComp->posX &&
//							posComp->posY == otherPosComp->posY)
//						{
//							nearComp->nbrLeft = otherIterator->first;
//						}
//						if (posComp->posX + 1 == otherPosComp->posX &&
//							posComp->posY == otherPosComp->posY)
//						{
//							nearComp->nbrRight = otherIterator->first;
//						}
//						if (posComp->posX == otherPosComp->posX &&
//							posComp->posY - 1 == otherPosComp->posY)
//						{
//							nearComp->nbrUp = otherIterator->first;
//						}
//						if (posComp->posX == otherPosComp->posX &&
//							posComp->posY + 1 == otherPosComp->posY)
//						{
//							nearComp->nbrDown = otherIterator->first;
//						}
//					}
//					++otherIterator;
//				}
//				otherIterator = theEntityManager.getMap()->begin();
//			}
//		}
//		++entityIterator;
//	}
//}
//
