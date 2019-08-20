#pragma once
#include "../SceneBase.h"
#include "../scenedefaults.h"

class World1_3 : public SceneBase, SceneDefaults
{
public:
	World1_3();
	virtual ~World1_3() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	Canvas backgroundCanvas;
	Canvas mainCanvas;
};