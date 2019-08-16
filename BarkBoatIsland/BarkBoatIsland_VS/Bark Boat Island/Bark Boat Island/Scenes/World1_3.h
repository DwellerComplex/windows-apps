#pragma once
#include "../SceneBase.h"
#include "../scenedefaults.h"

class World1_3 : public SceneBase, SceneDefaults
{
public:
	World1_3();
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	class Canvas* backgroundCanvas;
	class Canvas* mainCanvas;
};