#pragma once
#include "../SceneBase.h"
#include "../scenemanager.h"
#include "../scenedefaults.h"

class Amberstrand : public SceneBase, SceneDefaults
{
public:
	Amberstrand();

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

	void DrawLight(struct PositionComponent * positionComponent, const int radius, const float angleRadStepSize);

private:

	class Canvas* backgroundCanvas;
	class Canvas* mainCanvas;
	class Canvas* playerBackpack;
	class Canvas* console;
	class Canvas* fogOfWarCanvas;
};