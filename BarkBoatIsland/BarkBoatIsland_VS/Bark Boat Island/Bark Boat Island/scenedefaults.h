#pragma once
#include "scenemanager.h"

class SceneDefaults
{
public:
	SceneDefaults();
	~SceneDefaults();
	void PlayerInputMovement();
	void PlayerInteract();
	void PlayerInteractBackpack(int const other);
	void PlayerInteractDoors(int const other);
	void PlayerInteractTrees(int const other);
	int GetInteractableNearPlayer();
	void PlayerInputEscape();
	void ExecuteOrder66();
	void DrawEntities(class Canvas* mainCanvas);
	void DrawCanvas(class Canvas* canvas);
	void DrawCanvasOnCanvas(class Canvas * mainCanvas, class Canvas * otherCanvas);
	void DrawPlayerBackpack(class Canvas* playerBackpack);
	void DrawConsole();
	void ZeroCanvasBuffers(class Canvas* canvas);

	void ReadInput();
	void Collision(class Canvas* mainCanvas);
	void Movement(class Canvas* mainCanvas);

	void UpdateSpikeTraps(class Canvas * console);

	void PlayerRespawn();
	void UpdateEnemyPatrols();

	int GetEntityAt(int const posX, int const posY, int const id);

	bool IsPositionFree(int const posX, int const posY, int const id, struct CollisionComponent * collisionComponent, class Canvas* mainCanvas);

	std::vector<int> killQueue;
	std::vector<std::string> consoleQueue;
	class Canvas* console;

	short nextScene;
	bool continueUpdate;
	float playerSpawnTime;
};