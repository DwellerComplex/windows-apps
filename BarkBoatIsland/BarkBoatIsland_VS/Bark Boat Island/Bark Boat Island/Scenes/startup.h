#pragma once
#include "../SceneBase.h"
#include "../scenemanager.h"
#include "../scenedefaults.h"

class Startup : public SceneBase, SceneDefaults
{
public:
	Startup();

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	void DrawLight(struct PositionComponent * positionComponent, const int radius, const float angleRadStepSize);

	class Canvas* backgroundCanvas;
	class Canvas* mainCanvas;
	class Canvas* fogOfWarCanvas;
	class Canvas* playerBackpack;
	class Canvas* console;
};