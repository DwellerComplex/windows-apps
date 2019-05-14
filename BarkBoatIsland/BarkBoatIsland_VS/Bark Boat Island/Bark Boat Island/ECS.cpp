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
	this->collisionSetting = CollisionTypes::NORMAL;
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

			if (PersistencyComponent* persistencyComponent = Get<PersistencyComponent>(id))
			{
				if (PositionComponent* positionComponent = Get<PositionComponent>(id)) { if (!positionComponent->registerPersistancy) { Destroy<PositionComponent>(id); } }; //killQueue.emplace_back(ENTITIES[x]);
				if (SpriteComponent* spriteComponent = Get<SpriteComponent>(id)) { if (!spriteComponent->registerPersistancy) { Destroy<SpriteComponent>(id); } };
				if (InputComponent* inputComponent = Get<InputComponent>(id)) { if (!inputComponent->registerPersistancy) { Destroy<InputComponent>(id); } };
				if (MotionComponent* motionComponent = Get<MotionComponent>(id)) { if (!motionComponent->registerPersistancy) { Destroy<MotionComponent>(id); } };
				if (NearbyComponent* nearbyComponent = Get<NearbyComponent>(id)) { if (!nearbyComponent->registerPersistancy) { Destroy<NearbyComponent>(id); } };
				if (BackpackComponent* backpackComponent = Get<BackpackComponent>(id)) { if (!backpackComponent->registerPersistancy) { Destroy<BackpackComponent>(id); } };
				if (BackpackItemComponent* backpackItemComponent = Get<BackpackItemComponent>(id)) { if (!backpackItemComponent->registerPersistancy) { Destroy<BackpackItemComponent>(id); } };
			}
			else
			{
				Destroy<PositionComponent>(id);
				Destroy<SpriteComponent>(id);
				Destroy<InputComponent>(id);
				Destroy<MotionComponent>(id);
				Destroy<NearbyComponent>(id);
				Destroy<BackpackComponent>(id);
				Destroy<BackpackItemComponent>(id);
			}

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

				if (spriteComponent->drawLayer == drawLayer && spriteComponent->isActive)
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
					//if (Application::Input(0x10)) //Controlled walk with SHIFT
					//{
						if (inputComponent->hasClicked == false)
						{
							inputComponent->command = toascii(vKeys[i]);
							inputComponent->hasClicked = true;
						}
						break;
					//}
					//else //Fast walk
					//{
					//	inputComponent->command = toascii(vKeys[i]);
					//	inputComponent->hasClicked = true;
					//	break;
					//}
				}
			}
			if (i == vKeys.size() && inputComponent->hasClicked == true)
			{
				inputComponent->hasClicked = false;
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
			if (nearbyComponent->isActive)
			{
				nearbyComponent->neighbors[3] = (scene->TryPositionIsFloor(positionComponent->posX + 1, positionComponent->posY)) ? (scene->floorID) : (scene->wallID);
				nearbyComponent->neighbors[2] = (scene->TryPositionIsFloor(positionComponent->posX - 1, positionComponent->posY)) ? (scene->floorID) : (scene->wallID);
				nearbyComponent->neighbors[1] = (scene->TryPositionIsFloor(positionComponent->posX, positionComponent->posY + 1)) ? (scene->floorID) : (scene->wallID);
				nearbyComponent->neighbors[0] = (scene->TryPositionIsFloor(positionComponent->posX, positionComponent->posY - 1)) ? (scene->floorID) : (scene->wallID);
			}

			
			//Check other entities
			PositionComponent* nearbyPositionComponent = nullptr;
			for (int eN = 0; eN < ENTITIES_NEARBY.size(); eN++)
			{
				if (eN != e)
				{
					nearbyPositionComponent = Get<PositionComponent>(ENTITIES_NEARBY[eN]);

					if (nearbyPositionComponent->isActive)
					{
						if (positionComponent->posX == nearbyPositionComponent->posX)
						{
							if (positionComponent->posY - 1 == nearbyPositionComponent->posY)
							{
								nearbyComponent->neighbors[0] = ENTITIES_NEARBY[eN];
							}
							else if (positionComponent->posY + 1 == nearbyPositionComponent->posY)
							{
								nearbyComponent->neighbors[1] = ENTITIES_NEARBY[eN];
							}
						}
						else if (positionComponent->posY == nearbyPositionComponent->posY)
						{
							if (positionComponent->posX - 1 == nearbyPositionComponent->posX)
							{
								nearbyComponent->neighbors[2] = ENTITIES_NEARBY[eN];
							}
							else if (positionComponent->posX + 1 == nearbyPositionComponent->posX)
							{
								nearbyComponent->neighbors[3] = ENTITIES_NEARBY[eN];
							}
						}
					}
				}
			}

			if (motionComponent->isActive && (motionComponent->movementRate == 0.0f || motionComponent->timeToMove < timePoint))
			{
				if (motionComponent->footprint == char())
				{
					motionComponent->footprint = scene->GetFloor();
					motionComponent->footprintColor = scene->GetFloorColor();
				}

				if (motionComponent->up != 0)
				{
					CollisionComponent* nearbyCollisionComponent = Get<CollisionComponent>(nearbyComponent->neighbors[0]);
					NearbyComponent* nearbyNearbyComponent = Get<NearbyComponent>(nearbyComponent->neighbors[0]);

					if (nearbyComponent->neighbors[0] == scene->floorID ||
						(nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting != CollisionTypes::SOLID && nearbyCollisionComponent->collisionSetting != CollisionTypes::DYNAMIC && (collisionComponent->collisionSetting == CollisionTypes::KINEMATIC || nearbyCollisionComponent->collisionSetting == CollisionTypes::KINEMATIC)) ||
						(nearbyCollisionComponent == nullptr && nearbyComponent->neighbors[0] > 0))
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posY -= motionComponent->up;
					}
					else if (nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting == CollisionTypes::DYNAMIC && nearbyPositionComponent != nullptr && nearbyNearbyComponent != nullptr && nearbyComponent->neighbors[0] == scene->floorID)
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posY -= motionComponent->up;
						nearbyPositionComponent->posY -= motionComponent->up;
					}
				}
				if (motionComponent->down != 0)
				{
					CollisionComponent* nearbyCollisionComponent = Get<CollisionComponent>(nearbyComponent->neighbors[1]);
					NearbyComponent* nearbyNearbyComponent = Get<NearbyComponent>(nearbyComponent->neighbors[1]);

					if (nearbyComponent->neighbors[1] == scene->floorID ||
						(nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting != CollisionTypes::SOLID && nearbyCollisionComponent->collisionSetting != CollisionTypes::DYNAMIC && (collisionComponent->collisionSetting == CollisionTypes::KINEMATIC || nearbyCollisionComponent->collisionSetting == CollisionTypes::KINEMATIC)) ||
						(nearbyCollisionComponent == nullptr && nearbyComponent->neighbors[1] > 0))
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posY += motionComponent->down;
					}
					else if (nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting == CollisionTypes::DYNAMIC && nearbyPositionComponent != nullptr && nearbyNearbyComponent != nullptr && nearbyComponent->neighbors[1] == scene->floorID)
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posY += motionComponent->down;
						nearbyPositionComponent->posY += motionComponent->down;
					}
				}
				if (motionComponent->left != 0)
				{
					CollisionComponent* nearbyCollisionComponent = Get<CollisionComponent>(nearbyComponent->neighbors[2]);
					NearbyComponent* nearbyNearbyComponent = Get<NearbyComponent>(nearbyComponent->neighbors[2]);

					if (nearbyComponent->neighbors[2] == scene->floorID ||
						(nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting != CollisionTypes::SOLID && nearbyCollisionComponent->collisionSetting != CollisionTypes::DYNAMIC && (collisionComponent->collisionSetting == CollisionTypes::KINEMATIC || nearbyCollisionComponent->collisionSetting == CollisionTypes::KINEMATIC)) ||
						(nearbyCollisionComponent == nullptr && nearbyComponent->neighbors[2] > 0))
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posX -= motionComponent->left;
					}
					else if (nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting == CollisionTypes::DYNAMIC && nearbyPositionComponent != nullptr && nearbyNearbyComponent != nullptr && nearbyComponent->neighbors[2] == scene->floorID)
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posX -= motionComponent->left;
						nearbyPositionComponent->posX -= motionComponent->left;
					}
				}
				if (motionComponent->right != 0)
				{
					CollisionComponent* nearbyCollisionComponent = Get<CollisionComponent>(nearbyComponent->neighbors[3]);
					NearbyComponent* nearbyNearbyComponent = Get<NearbyComponent>(nearbyComponent->neighbors[3]);
					
					if (nearbyComponent->neighbors[3] == scene->floorID ||
						(nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting != CollisionTypes::SOLID && nearbyCollisionComponent->collisionSetting != CollisionTypes::DYNAMIC && (collisionComponent->collisionSetting == CollisionTypes::KINEMATIC || nearbyCollisionComponent->collisionSetting == CollisionTypes::KINEMATIC)) ||
						(nearbyCollisionComponent == nullptr && nearbyComponent->neighbors[3] > 0))
					{
						scene->DrawSprite(motionComponent->footprint, positionComponent->posX, positionComponent->posY, motionComponent->footprintColor);
						positionComponent->posX += motionComponent->right;
					}
					else if (nearbyCollisionComponent != nullptr && nearbyCollisionComponent->collisionSetting == CollisionTypes::DYNAMIC && nearbyPositionComponent != nullptr && nearbyNearbyComponent != nullptr && nearbyComponent->neighbors[3] == scene->floorID)
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