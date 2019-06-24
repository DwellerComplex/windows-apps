#pragma once
#include "SceneBase.h"
#include "scenemanager.h"

class Mainmenu : public SceneBase
{
public:
	Mainmenu();

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	void ProcessPlayerInput();

	void ExecuteOrder66();

	void Draw();

	void Input();

	void Collision();

	int GetEntityAt(int const posX, int const posY, int const id);

	bool IsPositionFree(int const posX, int const posY, int const id, struct CollisionComponent * collisionComponent);

	void Movement();

	short nextScene;

	std::vector<int> killQueue;

	class Canvas* backgroundCanvas;
	class Canvas* mainCanvas;
	class Canvas* textBox;
};