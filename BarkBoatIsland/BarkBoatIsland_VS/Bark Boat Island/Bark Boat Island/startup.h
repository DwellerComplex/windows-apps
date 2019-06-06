#pragma once
#include "SceneBase.h"
#include "scenemanager.h"

class Startup : public SceneBase
{
public:
	Startup();

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	void ProcessPlayerInput();
	void DrawLight(struct SpriteComponent * spriteComponent, struct PositionComponent * positionComponent, const int radius, const float angleRadStepSize, const int idOwner);
	void ExecuteOrder66();

	void Draw();

	void Input();

	int GetEntityAt(int const posX, int const posY, int const id);

	bool IsPositionFree(int const posX, int const posY, int const id, struct CollisionComponent * collisionComponent);

	void Movement();

	std::vector<int> killQueue;
	class Canvas* canvas;
	class Canvas* playerBackpack;
};