#pragma once
#include "../SceneBase.h"
#include "../scenedefaults.h"

class World1_2 : public SceneBase, SceneDefaults
{
public:
	World1_2();
	virtual ~World1_2() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	Canvas backgroundCanvas;
	Canvas mainCanvas;
};