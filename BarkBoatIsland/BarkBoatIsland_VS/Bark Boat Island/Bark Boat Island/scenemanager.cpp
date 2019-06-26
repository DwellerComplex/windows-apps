#include "scenemanager.h"

namespace SceneManager
{
	void RegisterScene(SceneBase* scene)
	{
		delete currentRunnningScene;
		currentRunnningScene = scene;
	}

	void ExecuteScene()
	{
		if (currentRunnningScene)
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

	bool IsRunning()
	{
		return (currentRunnningScene != nullptr);
	}
}