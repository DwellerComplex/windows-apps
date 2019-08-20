#pragma once
#include "scenemanager.h"
#include "canvas.h"


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
	void DrawEntities(Canvas* mainCanvas);
	void DrawCanvas(Canvas* canvas);
	void DrawCanvasOnCanvas(Canvas * mainCanvas, Canvas * otherCanvas);
	void DrawPlayerBackpack(Canvas* playerBackpack);
	void DrawConsole();
	void ZeroCanvasBuffers(Canvas* canvas);

	void ReadInput();
	void Collision(Canvas* mainCanvas);
	void Movement(Canvas* mainCanvas);

	void UpdateSpikeTraps();

	void PlayerRespawn();
	void UpdateEnemyPatrols();

	int GetEntityAt(int const posX, int const posY, int const id);

	bool IsPositionFree(int const posX, int const posY, int const id, struct CollisionComponent * collisionComponent, class Canvas* mainCanvas);

	std::vector<int> killQueue;
	std::vector<std::string> consoleQueue;
	Canvas console;

	short nextScene;
	bool continueUpdate;
	float playerSpawnTime;
};