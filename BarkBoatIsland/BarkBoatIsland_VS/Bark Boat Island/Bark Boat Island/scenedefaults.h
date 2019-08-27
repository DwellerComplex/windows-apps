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
	void DrawPlayerStats();
	void HidePlayerStats();
	void ZeroCanvasBuffers(Canvas* canvas);

	void ReadInput();
	void Collision(Canvas* mainCanvas);
	void Movement(Canvas* mainCanvas);

	void PlayerRespawn();
	void UpdateEnemyPatrols();
	void UpdateSpikeTraps();

	int GetEntityAt(int const posX, int const posY, int const id);

	bool IsPositionFree(int const posX, int const posY, int const id, struct CollisionComponent * collisionComponent, class Canvas* mainCanvas);

	std::vector<int> killQueue;
	std::vector<std::string> consoleQueue;
	Canvas console;
	Canvas playerStats;

	short nextScene;
	bool continueUpdate;
	float playerSpawnTime;

	const std::array<int, 6> vKeys{ 0x41, 0x57, 0x53, 0x44, 0x45, VK_ESCAPE };
	std::array<bool, 6> vKeysPressed{ 0, 0, 0, 0, 0, 0 };
	std::array<bool, 6> vKeysAsync{ 1, 1, 1, 1, 0, 0 };
	float vKeysToggleTime;
};