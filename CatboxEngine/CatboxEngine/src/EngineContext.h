#pragma once
#include "Renderer.h"
#include "Scene.h"

class EngineContext
{
public:
	EngineContext(Renderer* aRenderer, DebugConsole* aDebugConsole);
	void Draw();
	void DrawConsole();
	void SetScene();
	Scene* GetScene();
private:
	Scene* myScene = nullptr;
	Renderer* renderer;
	DebugConsole* console;

};

