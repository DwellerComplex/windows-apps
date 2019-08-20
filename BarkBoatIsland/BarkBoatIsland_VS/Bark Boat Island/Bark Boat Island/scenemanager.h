#pragma once
#include "SceneBase.h"
#include "application.h"

namespace SceneManager
{
	namespace
	{
		SceneBase* currentRunnningScene;
	}

	void RegisterScene(SceneBase* scene);
	void ExecuteScene();
	void EraseScene();
	bool IsRunning();
};