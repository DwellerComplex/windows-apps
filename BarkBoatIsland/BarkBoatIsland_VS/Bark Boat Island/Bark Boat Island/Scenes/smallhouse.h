#pragma once
#include "../SceneBase.h"
#include "../scenemanager.h"
#include "../scenedefaults.h"

class SmallHouse : public SceneBase, SceneDefaults
{
public:
	SmallHouse();

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:

	class Canvas* backgroundCanvas;
	class Canvas* mainCanvas;
	class Canvas* playerBackpack;
	class Canvas* console;
};