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

	void DrawLight(struct PositionComponent * positionComponent, const int radius, const float angleRadStepSize);

	void ExecuteOrder66();

	void Draw();

	void Input();

	void Collision();

	int GetEntityAt(int const posX, int const posY, int const id);

	bool IsPositionFree(int const posX, int const posY, int const id, struct CollisionComponent * collisionComponent);

	void Movement();

	short nextScene;

	std::vector<int> killQueue;
	std::vector<std::string> consoleQueue;

	class Canvas* backgroundCanvas;
	class Canvas* mainCanvas;
	class Canvas* fogOfWarCanvas;
	class Canvas* playerBackpack;
	class Canvas* console;

	const enum drawLayers {
		NONE,
		ONE,
		TWO,
		THREE,
		NUMBER_OF_DRAW_LAYERS
	};
	
	const enum canvases {
		BACKGROUND = 1,
		FOG_OF_WAR,
		MAIN,
		NUMBER_OF_CANVASES
	};
};