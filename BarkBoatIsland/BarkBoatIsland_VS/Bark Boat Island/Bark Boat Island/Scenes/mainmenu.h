#pragma once
#include "../SceneBase.h"
#include "../scenemanager.h"
#include "../scenedefaults.h"

class Mainmenu : public SceneBase, SceneDefaults
{
public:
	Mainmenu();

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	class Canvas* backgroundCanvas;
	class Canvas* mainCanvas;
	class Canvas* textBox;
};