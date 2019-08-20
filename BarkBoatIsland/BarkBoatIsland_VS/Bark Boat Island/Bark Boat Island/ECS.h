#pragma once
#include "application.h"

struct BaseComponent
{
	//bool registerPersistancy = false;
	bool isActive = true;
};

#pragma region COLLISION
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
	SpriteComponent(std::vector<std::vector<char>> sprite, std::vector<std::vector<short>> color, short canvasToDrawOn, short colorKey, short drawLayer);
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
	bool isHoldingKey;
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

#pragma region TREE
struct TreeComponent : public BaseComponent
{
public:
	TreeComponent() { };
	TreeComponent(short const nrLogs, short const nrShops, float const chopInterval, float const timeToChop) 
	{ 
		this->nrLogs = nrLogs; 
		this->chops = nrShops; 
		this->chopInterval = chopInterval; 
		this->timeToChop = timeToChop; 
	};
	short nrLogs;
	short chops;
	float chopInterval;
	float timeToChop;
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
	bool isInBackpack = false;
};
#pragma endregion

#pragma region LIFE

struct LifeComponent : public BaseComponent
{
public:
	LifeComponent() {};
	LifeComponent(int life);
	int life;
	int maxLife;
};

#pragma endregion


#pragma region SPIKETRAP

struct SpikeTrapComponent : public BaseComponent
{
public:
	SpikeTrapComponent() {};
	float attackDelay;
	float activeTime;
	bool activated;
	float timeToAttack;
};

#pragma endregion

struct EnemyPatrolComponent : public BaseComponent
{
public:
	EnemyPatrolComponent() {};
	EnemyPatrolComponent(short aX, short aY, short bX, short bY, float attackInterval, float timeToAttack);
	short aX, aY;
	short bX, bY;
	float attackInterval;
	float timeToAttack;
};

#pragma region ATTACK

struct AttackComponent : public BaseComponent
{
public:
	AttackComponent() {};
	AttackComponent(int damage);
	int damage;
};

#pragma endregion

//#pragma region PERSISTENT
//
//struct PersistencyComponent : public BaseComponent
//{
//public:
//	PersistencyComponent() {};
//};
//
//#pragma endregion

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
