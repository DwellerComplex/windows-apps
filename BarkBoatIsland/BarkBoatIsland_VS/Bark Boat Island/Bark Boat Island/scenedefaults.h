#pragma once
#include "scenemanager.h"

class SceneDefaults
{
public:
	SceneDefaults();
	void PlayerInputMovement();
	void PlayerInteractBackpack(class Canvas* playerBackpack, class Canvas* console);
	void PlayerInteractDoors();
	void PlayerInputEscape();
	void ExecuteOrder66();
	void DrawEntities(class Canvas* mainCanvas);
	void DrawMainCanvas(class Canvas* mainCanvas);
	void DrawCanvasOnMain(class Canvas * mainCanvas, class Canvas * otherCanvas);
	void DrawPlayerBackpack(class Canvas* playerBackpack);
	void DrawConsole(class Canvas* console);

	void Input();
	void Collision(class Canvas* mainCanvas);
	void Movement(class Canvas* mainCanvas);

	void UpdateSpikeTraps(class Canvas * console);

	void PlayerRespawn(class Canvas * console);

	int GetEntityAt(int const posX, int const posY, int const id);

	bool IsPositionFree(int const posX, int const posY, int const id, struct CollisionComponent * collisionComponent, class Canvas* mainCanvas);

	std::vector<int> killQueue;
	std::vector<std::string> consoleQueue;

	short nextScene;
	bool continueUpdate;
	float playerSpawnTime;
};