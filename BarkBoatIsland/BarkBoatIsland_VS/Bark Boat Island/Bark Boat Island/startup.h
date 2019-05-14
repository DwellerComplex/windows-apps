#pragma once
#include "SceneBase.h"
#include "scenemanager.h"

class Startup : public SceneBase
{
public:
	Startup();

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	void ProcessPlayerInput();

	class Scene* scene;
};