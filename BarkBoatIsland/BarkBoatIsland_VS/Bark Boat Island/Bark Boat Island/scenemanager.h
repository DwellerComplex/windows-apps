#pragma once
#include "SceneBase.h"
#include <vector>
#include "application.h"

namespace SceneManager
{
	namespace
	{
		SceneBase* currentRunnningScene;
	}

	void RegisterScene(SceneBase* scene);
	void ExecuteScene();
	bool IsRunning();
};