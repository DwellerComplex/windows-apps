#pragma once

class SceneBase
{
public:
	virtual void Start() = 0;

	virtual void Update() = 0;

	virtual void End() = 0;

	virtual ~SceneBase() {};

	bool update = true;
};