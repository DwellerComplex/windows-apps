#include "scenemanager.h"

namespace SceneManager
{
	void RegisterScene(SceneBase* scene)
	{
		EraseScene();
		currentRunnningScene = scene;
	}

	void ExecuteScene()
	{
		if (IsRunning())
		{
			currentRunnningScene->Start();

			double tick = Application::GetGlobalTimer();
			double newTick = tick;

			while (currentRunnningScene->update)
			{
				newTick = Application::GetGlobalTimer();

				if (tick < newTick)
				{
					currentRunnningScene->Update();

					tick = newTick + 1 / 60;
				}
			}

			currentRunnningScene->End();
		}
	}

	void EraseScene()
	{
		delete currentRunnningScene;
	}

	bool IsRunning()
	{
		return (currentRunnningScene);
	}
}