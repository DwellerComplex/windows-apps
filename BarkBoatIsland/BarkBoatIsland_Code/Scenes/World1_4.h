#pragma once
#include "../SceneBase.h"
#include "../scenedefaults.h"

class World1_4 : public SceneBase, SceneDefaults
{
public:
	World1_4();
	virtual ~World1_4() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	Canvas backgroundCanvas;
	Canvas mainCanvas;
};