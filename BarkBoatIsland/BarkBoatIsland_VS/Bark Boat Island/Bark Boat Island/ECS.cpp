#include "ECS.h"


//if (std::find(entities.begin(), entities.end(), &entity) == entities.end()) {

//}

#pragma region ENTITY
Entity::Entity(int id)
{
	this->id = id;
}

Entity::Entity(std::string name)
{
	this->name = name;
}

Entity::Entity(int id, std::string name)
{
	this->id = id;
	this->name = name;
}

void EntityManager::addEntity(Entity* entity)
{
	mapUniqueKey = 0;
	
	if (entity->id != 0)
	{
		mapUniqueKey = entity->id;
	}

	while(entityMap.count(mapUniqueKey) >= 1)
	{
		mapUniqueKey++;
	}

	entity->id = mapUniqueKey;
	entityMap.insert(eMapType(mapUniqueKey, entity));
}

Entity* EntityManager::getEntity(int entityID)
{
	if (entityMap.count(entityID) == 1)
	{
		return entityMap[entityID];
	}
	else
	{
		return nullptr;
	}
}

EntityManager::eMap* EntityManager::getMap()
{
	return &entityMap;
}

void EntityManager::destroyEntity(Entity* entity)
{
	theComponentManagers->theMotionManager.destroyComponent(entity->id);
	theComponentManagers->theSceneManager.destroyComponent(entity->id);
	theComponentManagers->theInputManager.destroyComponent(entity->id);
	theComponentManagers->theSpriteManager.destroyComponent(entity->id);
	theComponentManagers->thePositionManager.destroyComponent(entity->id);
	theComponentManagers->theNearbyManager.destroyComponent(entity->id);
	theComponentManagers->theInventoryManager.destroyComponent(entity->id);
	theComponentManagers->theLockManager.destroyComponent(entity->id);
	theComponentManagers->theInventoryItemManager.destroyComponent(entity->id);
	theComponentManagers->theConsoleOutputManager.destroyComponent(entity->id);
	theComponentManagers->theAttackManager.destroyComponent(entity->id);
	theComponentManagers->theLifeManager.destroyComponent(entity->id);
	theComponentManagers->theCollisionManager.destroyComponent(entity->id);
	theComponentManagers->thePlatformManager.destroyComponent(entity->id);
	
	if (this->getEntity(entity->id) != nullptr)
	{
		entityMap.erase(entity->id);
	}
}

void EntityManager::copyEntity(Entity* entity, Entity* copy)
{
	addEntity(copy);
	copy->name = entity->name;

	NearbyComponent* nearComp = theComponentManagers->theNearbyManager.getComponent(entity->id);
	PositionComponent* posComp = theComponentManagers->thePositionManager.getComponent(entity->id);
	SpriteComponent* spriteComp = theComponentManagers->theSpriteManager.getComponent(entity->id);
	InputComponent* inputComp = theComponentManagers->theInputManager.getComponent(entity->id);
	MotionComponent* motionComp = theComponentManagers->theMotionManager.getComponent(entity->id);
	SceneComponent* sceneComp = theComponentManagers->theSceneManager.getComponent(entity->id);
	InventoryComponent* invComp = theComponentManagers->theInventoryManager.getComponent(entity->id);
	LockComponent* lockComp = theComponentManagers->theLockManager.getComponent(entity->id);
	InventoryItemComponent* invItemComp = theComponentManagers->theInventoryItemManager.getComponent(entity->id);
	ConsoleOutputComponent* consoleOutComp = theComponentManagers->theConsoleOutputManager.getComponent(entity->id);
	LifeComponent* lifeComp = theComponentManagers->theLifeManager.getComponent(entity->id);
	AttackComponent* attackComp = theComponentManagers->theAttackManager.getComponent(entity->id);
	CollisionComponent* colComp = theComponentManagers->theCollisionManager.getComponent(entity->id);
	PlatformComponent* platformComp = theComponentManagers->thePlatformManager.getComponent(entity->id);

	if (nearComp != nullptr)
	{
		theComponentManagers->theNearbyManager.addComponent(copy, nearComp);
	}
	if (posComp != nullptr)
	{
		theComponentManagers->thePositionManager.addComponent(copy, posComp);
	}
	if (spriteComp != nullptr)
	{
		theComponentManagers->theSpriteManager.addComponent(copy, spriteComp);
	}
	if (inputComp != nullptr)
	{
		theComponentManagers->theInputManager.addComponent(copy, inputComp);
	}
	if (motionComp != nullptr)
	{
		theComponentManagers->theMotionManager.addComponent(copy, motionComp);
	}
	if (sceneComp != nullptr)
	{
		theComponentManagers->theSceneManager.addComponent(copy, sceneComp);
	}
	if (invComp != nullptr)
	{
		theComponentManagers->theInventoryManager.addComponent(copy, invComp);
	}
	if (lockComp != nullptr)
	{
		theComponentManagers->theLockManager.addComponent(copy, lockComp);
	}
	if (invItemComp != nullptr)
	{
		theComponentManagers->theInventoryItemManager.addComponent(copy, invItemComp);
	}
	if (consoleOutComp != nullptr)
	{
		theComponentManagers->theConsoleOutputManager.addComponent(copy, consoleOutComp);
	}
	if (lifeComp != nullptr)
	{
		theComponentManagers->theLifeManager.addComponent(copy, lifeComp);
	}
	if (attackComp != nullptr)
	{
		theComponentManagers->theAttackManager.addComponent(copy, attackComp);
	}
	if (colComp != nullptr)
	{
		theComponentManagers->theCollisionManager.addComponent(copy, colComp);
	}
	if (platformComp != nullptr)
	{
		theComponentManagers->thePlatformManager.addComponent(copy, platformComp);
	}
}
#pragma endregion

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
SceneComponent::SceneComponent(std::string const nextSceneName)
{
	this->nextName = nextSceneName;
}
#pragma endregion

#pragma region CONSOLEOUTPUT
ConsoleOutputComponent::ConsoleOutputComponent()
{
}

ConsoleOutputComponent::ConsoleOutputComponent(std::string const output)
{
	this->output.resize(1);
	this->output[0] = output;
}

ConsoleOutputComponent::ConsoleOutputComponent(std::vector<std::string> const output)
{
	this->output = output;
}

void ConsoleOutputComponent::setIterator(int iter)
{
	this->iterator = iter;
}

void ConsoleOutputComponent::iterate()
{
	this->iterator++;
}

int ConsoleOutputComponent::getIterator()
{
	return this->iterator;
}

std::string ConsoleOutputComponent::getOutput()
{
	return this->output[this->iterator];
}

int ConsoleOutputComponent::getOutputSize()
{
	return (int)this->output.size();
}

//void ConsoleOutputComponent::setActive(bool const status)
//{
//	this->active = status;
//}
//
//bool ConsoleOutputComponent::getActive()
//{
//	return this->active;
//}
#pragma endregion

#pragma region INVENTORY
void InventoryComponent::add(Entity& entity)
{
	//if(hasEntity(entity) == false)
	//{
	//	Entity* copy = new Entity(entity.name);
	//	theEntityManager.copyEntity(entity, *copy);
	//	entities.push_back(copy);

	//	theInventoryItemManager.getComponent(copy->id)->inInventory = true;

	//	theEntityManager.destroyEntity(entity);
	//}
	entities.push_back(&entity);

}

void InventoryComponent::remove(Entity& entity)
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->name == entity.name)
		{
			delete entities[i];
			entities.erase(std::find(entities.begin(), entities.end(), &entity));
		}
	}
}

bool InventoryComponent::hasEntity(Entity& entity)
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->name == entity.name)
		{
			return true;
		}
	}
	return false;
}

size_t InventoryComponent::size()
{
	return entities.size();
}

Entity* InventoryComponent::getEntity(int const entityID)
{
	return entities[entityID];
}
#pragma endregion

#pragma region LOCK
LockComponent::LockComponent(std::string const key)
{
	this->key = key;
}
#pragma endregion

#pragma region INVENTORYITEM
InventoryItemComponent::InventoryItemComponent()
{
	
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
#pragma endregion

ECS::ECS()
{
	theEntityManager.theComponentManagers = &theComponentManagers;
}

void ECS::Attack(Room &room)
{
	typedef std::map<int, Entity*>::const_iterator const_map_iter;
	const_map_iter entityIterator = theEntityManager.getMap()->begin();
	const_map_iter otherIterator = theEntityManager.getMap()->begin();

	LifeComponent* lifeComp;
	PositionComponent* posComp;

	PositionComponent* otherPosComp;
	AttackComponent* otherAttackComp;

	while (entityIterator != theEntityManager.getMap()->end()) {

		lifeComp = theComponentManagers.theLifeManager.getComponent(entityIterator->first);
		posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);

		if (posComp != nullptr &&
			lifeComp != nullptr)
		{
			while (otherIterator != theEntityManager.getMap()->end()) {
				otherPosComp = theComponentManagers.thePositionManager.getComponent(otherIterator->first);
				otherAttackComp = theComponentManagers.theAttackManager.getComponent(otherIterator->first);

				if (otherPosComp != nullptr &&
					otherAttackComp != nullptr &&
					posComp->posX == otherPosComp->posX &&
					posComp->posY == otherPosComp->posY &&
					otherIterator->first != entityIterator->first)
				{
					lifeComp->life -= otherAttackComp->damage;
				}
				++otherIterator;
			}
			otherIterator = theEntityManager.getMap()->begin();

			if (lifeComp->life <= 0)
			{
				room.DrawSprite(char(32), posComp->posX, posComp->posY);
				theEntityManager.destroyEntity(theEntityManager.getEntity(entityIterator->first));
				entityIterator = theEntityManager.getMap()->begin();
			}
		}
		++entityIterator;
	}
}

void ECS::Display(Room &room) 
{
	typedef std::map<int, Entity*>::const_iterator const_map_iter;
	const_map_iter entityIterator = theEntityManager.getMap()->begin();

	SpriteComponent* spriteComp;
	PositionComponent* posComp;

	short numbDrawLayers = 0;
	while (entityIterator != theEntityManager.getMap()->end()) {
		spriteComp = theComponentManagers.theSpriteManager.getComponent(entityIterator->first);
		posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);

		if (posComp != nullptr &&
			spriteComp != nullptr)
		{
			if (spriteComp->drawLayer > numbDrawLayers)
			{
				numbDrawLayers = spriteComp->drawLayer;
			}
		}
		++entityIterator;
	}

	for (short drawLayer = 0; drawLayer <= numbDrawLayers; drawLayer++)
	{
		entityIterator = theEntityManager.getMap()->begin();

		while (entityIterator != theEntityManager.getMap()->end()) {
			spriteComp = theComponentManagers.theSpriteManager.getComponent(entityIterator->first);
			posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);

			if (posComp != nullptr &&
				spriteComp != nullptr)
			{
				if (spriteComp->drawLayer == drawLayer)
				{
					room.DrawSprite(spriteComp->sprite, posComp->posX, posComp->posY, spriteComp->color);
				}
			}
			++entityIterator;
		}
	}
}

void ECS::MovementInput()
{
	typedef std::map<int, Entity*>::const_iterator const_map_iter;
	const_map_iter entityIterator = theEntityManager.getMap()->begin();

	InputComponent* inputComp;
	MotionComponent* motionComp;

	while (entityIterator != theEntityManager.getMap()->end()) {

		inputComp = theComponentManagers.theInputManager.getComponent(entityIterator->first);
		motionComp = theComponentManagers.theMotionManager.getComponent(entityIterator->first);

		if (motionComp != nullptr &&
			inputComp != nullptr)
		{
			if (inputComp->command == 'W')
			{
				motionComp->up = 1;
			}
			if (inputComp->command == 'A')
			{
				motionComp->left = 1;
			}
			if (inputComp->command == 'S')
			{
				motionComp->down = 1;
			}
			if (inputComp->command == 'D')
			{
				motionComp->right = 1;
			}
		}

		++entityIterator;
	}
}

void ECS::Movement(Room &room)
{
	Application& app = Application::get_instance();

	typedef std::map<int, Entity*>::const_iterator const_map_iter;
	const_map_iter entityIterator = theEntityManager.getMap()->begin();

	CollisionComponent* colComp;
	NearbyComponent* nearComp;
	PositionComponent* posComp;
	MotionComponent* motionComp;

	Entity* otherEntity;
	CollisionComponent* colUpComp;
	CollisionComponent* colDownComp;
	CollisionComponent* colLeftComp;
	CollisionComponent* colRightComp;

	while (entityIterator != theEntityManager.getMap()->end()) {

		nearComp = theComponentManagers.theNearbyManager.getComponent(entityIterator->first);
		posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);
		motionComp = theComponentManagers.theMotionManager.getComponent(entityIterator->first);
		colComp = theComponentManagers.theCollisionManager.getComponent(entityIterator->first);

		if (motionComp != nullptr &&
			posComp != nullptr &&
			nearComp != nullptr &&
			colComp != nullptr)
		{			
			if (motionComp->movementRate == 0.0f || app.GetGlobalTimer() >= motionComp->timeToMove)
			{
				if (motionComp->footprint == char())
				{
					motionComp->footprint = room.GetFloor();
				}

				if (motionComp->up != 0)
				{
					otherEntity = theEntityManager.getEntity(nearComp->nbrUp);
					colUpComp = theComponentManagers.theCollisionManager.getComponent(nearComp->nbrUp);

					if (nearComp->nbrUp == room.floorID ||
						(colUpComp != nullptr && colUpComp->collisionSetting != 2 && (colComp->collisionSetting == 1 || colUpComp->collisionSetting == 1)) ||
						(colUpComp == nullptr && otherEntity != nullptr))
					{
						room.DrawSprite(motionComp->footprint, posComp->posX, posComp->posY, room.GetFloorColor());
						posComp->posY -= motionComp->up;
					}
				}
				if (motionComp->down != 0)
				{
					otherEntity = theEntityManager.getEntity(nearComp->nbrDown);
					colDownComp = theComponentManagers.theCollisionManager.getComponent(nearComp->nbrDown);

					if (nearComp->nbrDown == room.floorID ||
						(colDownComp != nullptr && colDownComp->collisionSetting != 2 && (colComp->collisionSetting == 1 || colDownComp->collisionSetting == 1)) ||
						(colDownComp == nullptr && otherEntity != nullptr))
					{
						room.DrawSprite(motionComp->footprint, posComp->posX, posComp->posY, room.GetFloorColor());
						posComp->posY += motionComp->down;
					}
				}
				if (motionComp->left != 0)
				{
					otherEntity = theEntityManager.getEntity(nearComp->nbrLeft);
					colLeftComp = theComponentManagers.theCollisionManager.getComponent(nearComp->nbrLeft);

					if (nearComp->nbrLeft == room.floorID ||
						(colLeftComp != nullptr && colLeftComp->collisionSetting != 2 && (colComp->collisionSetting == 1 || colLeftComp->collisionSetting == 1)) ||
						(colLeftComp == nullptr && otherEntity != nullptr))
					{
						room.DrawSprite(motionComp->footprint, posComp->posX, posComp->posY, room.GetFloorColor());
						posComp->posX -= motionComp->left;
					}
				}
				if (motionComp->right != 0)
				{
					otherEntity = theEntityManager.getEntity(nearComp->nbrRight);
					colRightComp = theComponentManagers.theCollisionManager.getComponent(nearComp->nbrRight);

					if (nearComp->nbrRight == room.floorID ||
						(colRightComp != nullptr && colRightComp->collisionSetting != 2 && (colComp->collisionSetting == 1 || colRightComp->collisionSetting == 1)) ||
						(colRightComp == nullptr && otherEntity != nullptr))
					{
						room.DrawSprite(motionComp->footprint, posComp->posX, posComp->posY, room.GetFloorColor());
						posComp->posX += motionComp->right;
					}
				}

				if (motionComp->movementRate == 0.0f)
				{
					motionComp->up = 0;
					motionComp->down = 0;
					motionComp->left = 0;
					motionComp->right = 0;
				}
				else
				{
					motionComp->timeToMove = app.GetGlobalTimer() + (1.0f / motionComp->movementRate);
				}
			}
		}
		++entityIterator;
	}
}

void ECS::Platform()
{
	typedef std::map<int, Entity*>::const_iterator const_map_iter;
	const_map_iter entityIterator = theEntityManager.getMap()->begin();
	const_map_iter otherIterator = theEntityManager.getMap()->begin();

	PlatformComponent* platformComp;
	PositionComponent* posComp;
	MotionComponent* motionComp;

	PositionComponent* otherPosComp;
	MotionComponent* otherMotionComp;

	while (entityIterator != theEntityManager.getMap()->end()) {
		
		platformComp = theComponentManagers.thePlatformManager.getComponent(entityIterator->first);
		posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);
		motionComp = theComponentManagers.theMotionManager.getComponent(entityIterator->first);

		if (platformComp != nullptr && 
			posComp != nullptr &&
			motionComp != nullptr)
		{
			while (otherIterator != theEntityManager.getMap()->end()) {
				otherPosComp = theComponentManagers.thePositionManager.getComponent(otherIterator->first);
				otherMotionComp = theComponentManagers.theMotionManager.getComponent(otherIterator->first);

				if (otherPosComp != nullptr && entityIterator->first != otherIterator->first)
				{
					if (otherMotionComp != nullptr)
					{

						if (otherPosComp->posX == posComp->posX &&
							otherPosComp->posY == posComp->posY)
						{
							if (platformComp->occupied == false)
							{
								platformComp->backupMotionComponent.down = otherMotionComp->down;
								platformComp->backupMotionComponent.up = otherMotionComp->up;
								platformComp->backupMotionComponent.left = otherMotionComp->left;
								platformComp->backupMotionComponent.right = otherMotionComp->right;
								platformComp->backupMotionComponent.footprint = otherMotionComp->footprint;
								platformComp->backupMotionComponent.movementRate = otherMotionComp->movementRate;
								platformComp->backupMotionComponent.timeToMove = otherMotionComp->timeToMove;
								platformComp->occupied = true;
								otherMotionComp->down = motionComp->down;
								otherMotionComp->up = motionComp->up;
								otherMotionComp->left = motionComp->left;
								otherMotionComp->right = motionComp->right;
								otherMotionComp->footprint = motionComp->footprint;
								otherMotionComp->movementRate = motionComp->movementRate;
								otherMotionComp->timeToMove = motionComp->timeToMove;
							}
						}
						else if(platformComp->occupied == true && 
								(motionComp->down	!= otherMotionComp->down	|| 
								motionComp->up		!= otherMotionComp->up		|| 
								motionComp->left	!= otherMotionComp->left	|| 
								motionComp->right	!= otherMotionComp->right))
						{
							otherMotionComp->down = platformComp->backupMotionComponent.down;
							otherMotionComp->up = platformComp->backupMotionComponent.up;
							otherMotionComp->left = platformComp->backupMotionComponent.left;
							otherMotionComp->right = platformComp->backupMotionComponent.right;
							otherMotionComp->footprint = platformComp->backupMotionComponent.footprint;
							otherMotionComp->movementRate = platformComp->backupMotionComponent.movementRate;
							otherMotionComp->timeToMove = platformComp->backupMotionComponent.timeToMove;
							platformComp->occupied = false;
						}
					}
				}

				++otherIterator;
			}
			otherIterator = theEntityManager.getMap()->begin();
		}
		++entityIterator;
	}
}

void ECS::InteractAction(Room &room, int const entity, int const other, ConsolePanel *consolePanel)
{
	SceneComponent* otherSceneComp = theComponentManagers.theSceneManager.getComponent(other);
	LockComponent* otherLockComp = theComponentManagers.theLockManager.getComponent(other);
	InventoryItemComponent* otherInventoryItemComp = theComponentManagers.theInventoryItemManager.getComponent(other);
	ConsoleOutputComponent* otherConsoleOutComp = theComponentManagers.theConsoleOutputManager.getComponent(other);

	InventoryComponent* inventoryComp = theComponentManagers.theInventoryManager.getComponent(entity);
	
	if (otherSceneComp != nullptr)
	{
		if (otherLockComp != nullptr)
		{
			if (inventoryComp != nullptr)
			{
				for (int i = 0; i < inventoryComp->size(); i++)
				{
					if(inventoryComp->getEntity(i)->name == otherLockComp->key)
					{
						if (otherConsoleOutComp != nullptr)
						{
							otherConsoleOutComp->setIterator(-1); //setActive(false);
						}

						room.SetNextRoomName(otherSceneComp->nextName);
						room.SetIsPlaying(false);
						break;
					}
				}
			}
		}
		else
		{
			room.SetNextRoomName(otherSceneComp->nextName);
			room.SetIsPlaying(false);
		}
	}	
	//funkar men ändra kanske iterator - 1 till en bool
	if (otherConsoleOutComp != nullptr && otherConsoleOutComp->getIterator() >= 0) //otherConsoleOutComp->getActive())
	{
		consolePanel->enqueue(otherConsoleOutComp->getOutput());
		otherConsoleOutComp->iterate();
	//sätt iterator - 1 så att sista strängen visas igen om spelaren trycker flera ggr
		if (otherConsoleOutComp->getOutputSize() <= otherConsoleOutComp->getIterator())
		{	
			otherConsoleOutComp->setIterator(otherConsoleOutComp->getOutputSize() - 1);
		}
	}

	if (inventoryComp != nullptr &&
		otherInventoryItemComp != nullptr)
	{
		if (inventoryComp->hasEntity(*theEntityManager.getEntity(other)) == false)
		{
			inventoryComp->add(*theEntityManager.getEntity(other));
			theComponentManagers.theInventoryItemManager.getComponent(other)->isInInventory = true;
			theComponentManagers.theSpriteManager.destroyComponent(other);
			theComponentManagers.theCollisionManager.destroyComponent(other);
			
			room.DrawSprite(room.GetFloor(), theComponentManagers.thePositionManager.getComponent(other)->posX, theComponentManagers.thePositionManager.getComponent(other)->posY, room.GetFloorColor());
			theComponentManagers.thePositionManager.destroyComponent(other);	
		}
	}
}

void ECS::Interact(Room &room, ConsolePanel *consolePanel)//, ConsolePanel* theConsolePanel, InventoryPanel* theInventoryPanel
{
	typedef std::map<int, Entity*>::const_iterator const_map_iter;
	const_map_iter entityIterator = theEntityManager.getMap()->begin();
	const_map_iter otherIterator = theEntityManager.getMap()->begin();

	NearbyComponent* nearComp;
	InputComponent* inputComp;
	PositionComponent* posComp;

	PositionComponent* otherPosComp;

	while (entityIterator != theEntityManager.getMap()->end()) {

		nearComp = theComponentManagers.theNearbyManager.getComponent(entityIterator->first);
		inputComp = theComponentManagers.theInputManager.getComponent(entityIterator->first);
		posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);
		
		if (nearComp != nullptr)
		{
			if (inputComp != nullptr &&
				inputComp->command == 'E')
			{
				if (nearComp->nbrUp != room.floorID && nearComp->nbrUp != room.wallID)
				{
					InteractAction(room, entityIterator->first, nearComp->nbrUp, consolePanel);
				}
				else if (nearComp->nbrDown != room.floorID && nearComp->nbrDown != room.wallID)
				{
					InteractAction(room, entityIterator->first, nearComp->nbrDown, consolePanel);
				}
				else if (nearComp->nbrLeft != room.floorID && nearComp->nbrLeft != room.wallID)
				{
					InteractAction(room, entityIterator->first, nearComp->nbrLeft, consolePanel);
				}
				else if (nearComp->nbrRight != room.floorID && nearComp->nbrRight != room.wallID)
				{
					InteractAction(room, entityIterator->first, nearComp->nbrRight, consolePanel);
				}
			}

			if (posComp != nullptr)
			{
				if (room.TryPositionIsFloor(posComp->posX + 1, posComp->posY))
				{
					nearComp->nbrRight = room.floorID;
				}
				else
				{
					nearComp->nbrRight = room.wallID;
				}
				if (room.TryPositionIsFloor(posComp->posX - 1, posComp->posY))
				{
					nearComp->nbrLeft = room.floorID;
				}
				else
				{
					nearComp->nbrLeft = room.wallID;
				}
				if (room.TryPositionIsFloor(posComp->posX, posComp->posY + 1))
				{
					nearComp->nbrDown = room.floorID;
				}
				else
				{
					nearComp->nbrDown = room.wallID;
				}
				if (room.TryPositionIsFloor(posComp->posX, posComp->posY - 1))
				{
					nearComp->nbrUp = room.floorID;
				}
				else
				{
					nearComp->nbrUp = room.wallID;
				}

				while (otherIterator != theEntityManager.getMap()->end())
				{
					otherPosComp = theComponentManagers.thePositionManager.getComponent(otherIterator->first);

					if (otherPosComp != nullptr)
					{
						if (posComp->posX - 1 == otherPosComp->posX &&
							posComp->posY == otherPosComp->posY)
						{
							nearComp->nbrLeft = otherIterator->first;
						}
						if (posComp->posX + 1 == otherPosComp->posX &&
							posComp->posY == otherPosComp->posY)
						{
							nearComp->nbrRight = otherIterator->first;
						}
						if (posComp->posX == otherPosComp->posX &&
							posComp->posY - 1 == otherPosComp->posY)
						{
							nearComp->nbrUp = otherIterator->first;
						}
						if (posComp->posX == otherPosComp->posX &&
							posComp->posY + 1 == otherPosComp->posY)
						{
							nearComp->nbrDown = otherIterator->first;
						}
					}
					++otherIterator;
				}
				otherIterator = theEntityManager.getMap()->begin();
			}
		}
		++entityIterator;
	}
}

void ECS::Input()
{
	Application& app = Application::get_instance();

	typedef std::map<int, Entity*>::const_iterator const_map_iter;
	const_map_iter entityIterator = theEntityManager.getMap()->begin();

	InputComponent* inputComp;

	const std::array<int, 5> vKeys {0x41, 0x57, 0x53, 0x44, 0x45};

	while (entityIterator != theEntityManager.getMap()->end()) {
		
		inputComp = theComponentManagers.theInputManager.getComponent(entityIterator->first);

		if (inputComp != nullptr)
		{
			inputComp->command = ' ';
			int i = 0;

			for(i ; i < vKeys.size() ; i++)
			{			
				if (app.input(vKeys[i]))
				{
					if (inputComp->hasClicked == false)
					{
						inputComp->command = toascii(vKeys[i]);
						inputComp->hasClicked = true;
					}
					break;
				}
			}
			if (i == vKeys.size() && inputComp->hasClicked == true)
			{
				inputComp->hasClicked = false;
			}
		}

		++entityIterator;
	}
}

//void ECS::UpdateRoomWithInventories(Room &room)
//{
//	typedef std::map<int, Entity*>::const_iterator const_map_iter;
//	const_map_iter entityIterator = theEntityManager.getMap()->cbegin();
//	const_map_iter otherIterator = theEntityManager.getMap()->cbegin();
//
//	InventoryItemComponent* invItemComp;
//	SpriteComponent* spriteComp;
//	PositionComponent* posComp;
//
//	int otherDuplicateID = -1;
//
//	while (entityIterator != theEntityManager.getMap()->end()) {
//		
//		invItemComp = theComponentManagers.theInventoryItemManager.getComponent(entityIterator->first);
//		posComp = theComponentManagers.thePositionManager.getComponent(entityIterator->first);
//		spriteComp = theComponentManagers.theSpriteManager.getComponent(entityIterator->first);
//
//		if (invItemComp != nullptr &&
//			invItemComp->isInInventory == true)
//		{
//			if (spriteComp != nullptr && posComp != nullptr)
//			{
//				room.DrawSprite(room.GetFloor(), posComp->posX, posComp->posY);
//				theComponentManagers.theSpriteManager.destroyComponent(entityIterator->first);
//			}
//			else if (spriteComp != nullptr)
//			{
//				theComponentManagers.theSpriteManager.destroyComponent(entityIterator->first);
//			}
//			if (posComp != nullptr)
//			{
//				theComponentManagers.thePositionManager.destroyComponent(entityIterator->first);
//			}
//
//			//Items are created every scene. 
//			//If inventory contains an item, destroy its duplicate an remove it from scene.
//			while (otherIterator != theEntityManager.getMap()->end()) {
//			
//				if (entityIterator->second->name == otherIterator->second->name &&
//					otherIterator->second->name != "" &&
//					entityIterator->second->id != otherIterator->second->id)
//				{
//					otherDuplicateID = otherIterator->second->id;
//				}
//				++otherIterator;
//			}
//			otherIterator = theEntityManager.getMap()->begin();
//		}
//		++entityIterator;
//	}
//
//	if (otherDuplicateID != -1)
//	{
//		posComp = theComponentManagers.thePositionManager.getComponent(otherDuplicateID);
//		if (posComp != nullptr)
//		{
//			room.DrawSprite(room.GetFloor(), posComp->posX, posComp->posY, room.GetFloorColor());
//			theEntityManager.destroyEntity(theEntityManager.getEntity(otherDuplicateID));
//		}
//	}
//}