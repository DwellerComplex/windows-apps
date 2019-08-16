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

//#pragma region SPRITE
//SpriteComponent::SpriteComponent()
//{
//	this->sprite = ' ';
//	this->color = 15;
//	this->drawLayer = 0;
//}
//SpriteComponent::SpriteComponent(char const body, int const color, short const drawLayer)
//{
//	this->sprite = body;
//	this->color = color;
//	this->drawLayer = drawLayer;
//}
//#pragma endregion

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

//#pragma region NEARBY
//NearbyComponent::NearbyComponent()
//{
//
//}
//#pragma endregion

#pragma region COLLISION
CollisionComponent::CollisionComponent()
{
	//this->collisionSetting = CollisionTypes::NORMAL;
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

#pragma region CONSOLEOUTPUT
ConsoleOutputComponent::ConsoleOutputComponent()
{
}

ConsoleOutputComponent::ConsoleOutputComponent(std::string const output)
{
	this->output.emplace_back(output);
}

ConsoleOutputComponent::ConsoleOutputComponent(std::vector<std::string> const output)
{
	this->output = output;
}

#pragma endregion

EnemyPatrolComponent::EnemyPatrolComponent(short aX, short aY, short bX, short bY, float attackInterval, float timeToAttack)
{
	this->aX = aX;
	this->aY = aY;
	this->bX = bX;
	this->bY = bY;
	this->attackInterval = attackInterval;
	this->timeToAttack = timeToAttack;
}

SpriteComponent::SpriteComponent(std::vector<std::vector<char>> sprite, std::vector<std::vector<short>> color, short canvasToDrawOn, short colorKey, short drawLayer)
{
	this->sprite = sprite;
	this->color = color;
	this->canvasToDrawOn = canvasToDrawOn;
	this->colorKey = colorKey;
	this->drawLayer = drawLayer;
}
