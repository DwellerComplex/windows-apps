#pragma once
#include "../SceneBase.h"
#include "../scenedefaults.h"

class Mainmenu : public SceneBase, SceneDefaults
{
public:
	Mainmenu();
	virtual ~Mainmenu() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	Canvas backgroundCanvas;
	Canvas mainCanvas;
	Canvas textBox;
};