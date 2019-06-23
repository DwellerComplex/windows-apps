#pragma once
#include "application.h"

struct BaseComponent
{
	bool registerPersistancy = false;
	bool isActive = true;
};

#pragma region COLLISION
const enum CollisionTypes
{
	NONE,
	//1: kinetic (ignore normal and kinetic items) 
	KINETIC,
	//2: solid (ignore no items, block all) 
	SOLID,
	//3: dynamic (ignore kinetic, interact with normal and solid, "pushable")
	DYNAMIC,
	NUMBER_OF_COLLISION_TYPES
};

struct CollisionComponent : public BaseComponent
{
public:
	CollisionComponent();
	CollisionComponent(int setting);

	short int collisionSetting;
	std::vector<std::vector<bool>> collisionBuffer;
};
#pragma endregion

#pragma region POSITION
struct PositionComponent : public BaseComponent
{
public:
	PositionComponent() {};
	PositionComponent(int const x, int const y);
	int posX, posY;
};

#pragma endregion

#pragma region SPRITE
//struct Sprite
//{
//	Sprite(char const body, int const color = 15)
//	{
//		this->sprite = body;
//		this->color = color;
//	};
//
//	char sprite;
//	int color;
//};

struct SpriteComponent : public BaseComponent
{
public:
	SpriteComponent() {};
	std::vector<std::vector<char>> sprite;
	std::vector<std::vector<short>> color;
	short canvasToDrawOn = 0;
	short colorKey;
	short drawLayer;
};

#pragma endregion

#pragma region INPUT
struct InputComponent : public BaseComponent
{
public:
	InputComponent();
	char command;
	bool hasClicked;
};

#pragma endregion

#pragma region MOTION
struct MotionComponent : public BaseComponent
{
public:
	MotionComponent();
	MotionComponent(bool up, bool down, bool left, bool right, float movementRate, int footprintColor = 15, char footprint = char());
	bool up, down, left, right;
	float movementRate;
	float timeToMove;
	char footprint;
	int footprintColor;
};

#pragma endregion

#pragma region SCENE
struct SceneComponent : public BaseComponent
{
public:
	SceneComponent() { };
	SceneComponent(short nextScene);
	short nextScene;
};

#pragma endregion

#pragma region LOCK
struct LockComponent : public BaseComponent
{
public:
	LockComponent() { };
	LockComponent(int const key);
	int key;
};

#pragma endregion

//Contains ids of backpack items
#pragma region BACKPACK
struct BackpackComponent : public BaseComponent
{
public:
	BackpackComponent() { };
	std::unordered_map<int,int> items;
};
#pragma endregion

//"type" specifies item type. Types are counted as ints in backpack, same type icreases same int.
#pragma region BACKPACKITEM
struct BackpackItemComponent : public BaseComponent
{
public:
	BackpackItemComponent() { type = 0; };
	BackpackItemComponent(int type) { this->type = type; };
	int type;
};
#pragma endregion

#pragma region LIFE

struct LifeComponent : public BaseComponent
{
public:
	LifeComponent() {};
	LifeComponent(int life);
	int life;
};

#pragma endregion

#pragma region ATTACK

struct AttackComponent : public BaseComponent
{
public:
	AttackComponent() {};
	AttackComponent(int damage);
	int damage;
};

#pragma endregion

#pragma region PERSISTENT

struct PersistencyComponent : public BaseComponent
{
public:
	PersistencyComponent() {};
};

#pragma endregion

#pragma region PLATFORM

struct PlatformComponent : public BaseComponent
{
public:
	PlatformComponent() {};
	bool up, down, left, right;
	float movementRate;
	float timeToMove;
	char footprint;
	bool occupied = false;
	MotionComponent backupMotionComponent;
};


struct PlatformRiderComponent : public BaseComponent
{
	PlatformRiderComponent() {};
};

#pragma endregion

#pragma region CONSOLEOUTPUT
struct ConsoleOutputComponent : public BaseComponent
{
	public:
		ConsoleOutputComponent();
		ConsoleOutputComponent(std::string const output);
		ConsoleOutputComponent(std::vector<std::string> const output);

		void setIterator(int iter);
		void iterate();
		int getOutputSize();
		int getIterator();
		std::string getOutput();

	private:
		std::vector<std::string> output;
		int iterator = 0;
};
#pragma endregion

namespace ECS
{
	template <typename T>
	std::vector<int> entities;

	template <typename T>
	std::unordered_map<int, T> components;

	template <typename T>
	T* Add(int id, T t = T())
	{
		if (std::find(entities<T>.begin(), entities<T>.end(), id) == entities<T>.end())
		{
			entities<T>.emplace_back(id);
			components<T>[id] = t;
		}

		return&components<T>[id];
	}

	template <typename T>
	T* Get(int id)
	{
		std::vector<int>::iterator idInEntities = std::find(entities<T>.begin(), entities<T>.end(), id);
		if (idInEntities != entities<T>.end())
		{
			return&components<T>[id];
		}
		else
		{
			return nullptr;
		}
	}

	template <typename T>
	void Destroy(int id)
	{
		std::vector<int>::iterator idInEntities = std::find(entities<T>.begin(), entities<T>.end(), id);
		if (idInEntities != entities<T>.end())
		{
			components<T>.erase(id);
			entities<T>.erase(idInEntities);
		}
	}

	template <typename T>
	const std::vector<int> GetAllIDFrom()
	{
		return entities<T>;
	}
};

//#ifndef __ECS_H_INCLUDED__
//#define __ECS_H_INCLUDED__
//
//#pragma once
//#include "application.h"
//#include "consolepanel.h"
//#include "room.h"
//#include <array>
////class Room;
////class InventoryPanel;
////class ConsolePanel;
//
//struct Entity
//{
//public:
//	Entity() {};
//	Entity(int id);
//	Entity(std::string name);
//	Entity(int id, std::string name);
//	int id = 0;
//	std::string name = "";
//};
//
//#pragma region COMPONENTMANAGER
//template<typename ComponentType> class ComponentManager {
//public:
//	typedef std::map<int, ComponentType*> cMap;
//	typedef std::pair<int, ComponentType*> cMapType;
//
//	void addComponent(Entity* entity, ComponentType* component);
//	ComponentType* getComponent(int entityID);
//	void destroyComponent(int entityID);
//
//private:
//
//	cMap entityMap;
//};
//
//template<typename ComponentType>
//void ComponentManager<ComponentType>::addComponent(Entity* entity, ComponentType* component)
//{
//	entityMap.insert(cMapType(entity->id, component));
//};
//
//template<typename ComponentType>
//ComponentType* ComponentManager<ComponentType>::getComponent(int entityID)
//{
//	if (entityMap.count(entityID) == 1)
//	{
//		return entityMap[entityID];
//	}
//	else
//	{
//		return nullptr;
//	}
//};
//
//template<typename ComponentType>
//void ComponentManager<ComponentType>::destroyComponent(int entityID)
//{
//	if (this->getComponent(entityID) != nullptr)
//	{
//		entityMap.erase(entityID);
//	}
//};
//
//#pragma endregion
//
//#pragma region NEARBY
//struct NearbyComponent
//{
//public:
//	NearbyComponent();
//	int nbrUp, nbrDown, nbrLeft, nbrRight;
//};
//#pragma endregion
//
//#pragma region COLLISION
//struct CollisionComponent
//{
//public:
//	CollisionComponent();
//	CollisionComponent(int setting);
//	//0: normal (ignore kinetic, interact with dynamic and solid, semi static, "move at own will") 
//	//1: kinetic (ignore normal and kinetic items) 
//	//2: solid (ignore no items, block all) 
//	//3: dynamic (ignore kinetic, interact with normal and solid, "pushable")
//	short int collisionSetting;
//};
//#pragma endregion
//
//#pragma region POSITION
//struct PositionComponent
//{
//public:
//	PositionComponent() {};
//	PositionComponent(int const x, int const y);
//	int posX, posY;
//};
//
//#pragma endregion
//
//#pragma region SPRITE
//struct SpriteComponent
//{
//public:
//	SpriteComponent() {};
//	SpriteComponent(char const body, int const color = 15, short const drawLayer = 0);
//	char sprite;
//	int color;
//	short drawLayer;
//};
//
//#pragma endregion
//
//#pragma region INPUT
//struct InputComponent
//{
//public:
//	InputComponent();
//	char command;
//	bool hasClicked;
//};
//
//#pragma endregion
//
//#pragma region MOTION
//struct MotionComponent
//{
//public:
//	MotionComponent();
//	MotionComponent(bool up, bool down, bool left, bool right, float movementRate, int footprintColor = 15, char footprint = char());
//	bool up, down, left, right;
//	float movementRate;
//	float timeToMove;
//	char footprint;
//	int footprintColor;
//};
//
//#pragma endregion
//
//#pragma region SCENE
//struct SceneComponent
//{
//public:
//	SceneComponent() { };
//	SceneComponent(std::string const nextSceneName);
//	std::string nextName;
//};
//
//#pragma endregion
//
//#pragma region INVENTORY
//struct InventoryComponent
//{
//public:
//	InventoryComponent() { };
//	void add(Entity& entity);
//	void remove(Entity& entity);
//	bool hasEntity(Entity& entity);
//	Entity* getEntity(int const entityID);
//	size_t size();
//
//private:
//	std::vector<Entity*> entities;
//};
//
//#pragma endregion
//
//#pragma region LOCK
//struct LockComponent
//{
//public:
//	LockComponent() { };
//	LockComponent(std::string const key);
//	std::string key;
//};
//
//#pragma endregion
//
//#pragma region INVENTORYITEM
//struct InventoryItemComponent
//{
//public:
//	InventoryItemComponent();
//	bool isInInventory = false;
//};
//#pragma endregion
//
//#pragma region LIFE
//
//struct LifeComponent
//{
//public:
//	LifeComponent() {};
//	LifeComponent(int life);
//	int life;
//};
//
//#pragma endregion
//
//#pragma region ATTACK
//
//struct AttackComponent
//{
//public:
//	AttackComponent() {};
//	AttackComponent(int damage);
//	int damage;
//};
//
//#pragma endregion
//
//#pragma region PLATFORM
//
//struct PlatformComponent
//{
//public:
//	PlatformComponent() {};
//	bool up, down, left, right;
//	float movementRate;
//	float timeToMove;
//	char footprint;
//	bool occupied = false;
//	MotionComponent backupMotionComponent;
//};
//
//
//struct PlatformRiderComponent
//{
//	PlatformRiderComponent() {};
//};
//
//#pragma endregion
//
//
//
////Bounce (on colliders) ?
//
////#pragma region COLLIDER
////
////struct ColliderComponent
////{
////public:
////	ColliderComponent() {};
////
////	
////};
////
////#pragma endregion
////
////#pragma region PUSHABLE
////
////struct PushableComponent
////{
////public:
////	PushableComponent() {};
////	bool hasCollided;
////};
//
////#pragma endregion
//
//#pragma region CONSOLEOUTPUT
//struct ConsoleOutputComponent
//{
//public:
//	ConsoleOutputComponent();
//	ConsoleOutputComponent(std::string const output);
//	ConsoleOutputComponent(std::vector<std::string> const output);
//
//	void setIterator(int iter);
//	void iterate();
//	int getOutputSize();
//	int getIterator();
//	std::string getOutput();
//
//private:
//	std::vector<std::string> output;
//	int iterator = 0;
//};
//
//#pragma endregion
//
//struct ComponentManagers
//{
//	ComponentManager<SceneComponent> theSceneManager;
//	ComponentManager<InventoryComponent> theInventoryManager;
//	ComponentManager<LockComponent> theLockManager;
//	ComponentManager<InventoryItemComponent> theInventoryItemManager;
//	ComponentManager<ConsoleOutputComponent> theConsoleOutputManager;
//	ComponentManager<MotionComponent> theMotionManager;
//	ComponentManager<InputComponent> theInputManager;
//	ComponentManager<NearbyComponent> theNearbyManager;
//	ComponentManager<PositionComponent> thePositionManager;
//	ComponentManager<SpriteComponent> theSpriteManager;
//	ComponentManager<AttackComponent> theAttackManager;
//	ComponentManager<LifeComponent> theLifeManager;
//	ComponentManager<CollisionComponent> theCollisionManager;
//	ComponentManager<PlatformComponent> thePlatformManager;
//	ComponentManager<PlatformRiderComponent> thePlatformRiderManager;
//};
//
//#pragma region ENTITY
//
//struct EntityManager
//{
//	typedef std::map<int, Entity*> eMap;
//	typedef std::pair<int, Entity*> eMapType;
//
//	void addEntity(Entity* entity);
//	Entity* getEntity(int entityID);
//	eMap* getMap();
//	void destroyEntity(Entity* entity);
//	//void copyEntity(Entity* entity, Entity* copy);
//
//	ComponentManagers* theComponentManagers;
//private:
//	int mapUniqueKey = 0;
//	
//	eMap entityMap;
//};
//#pragma endregion
//
//#pragma region SYSTEMS
//
//struct ECS
//{
//	ECS();
//	void Attack(Room &room);
//	void Display(Room &room);
//	void Movement(Room &room);
//	void MovementInput();
//	void Platform();
//	void Interact(Room & room, ConsolePanel * consolePanel);
//	void InteractAction(Room & room, int const entity, int const other, ConsolePanel * consolePanel);
//	void Input();
//
//	EntityManager theEntityManager;
//	ComponentManagers theComponentManagers;
//};
//
//
//#pragma endregion
//
//
//#endif