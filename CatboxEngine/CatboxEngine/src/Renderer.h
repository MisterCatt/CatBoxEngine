#pragma once
#include <vector>
#include <memory>

//Keeps track of our render passes and renders our scene

class EngineContext;
class Scene;
class Renderer
{
public:
	virtual void Init() = 0;
	virtual void BeginFrame(Scene& aScene) = 0;
	virtual void RenderScene(Scene& aScene) = 0;
	virtual void EndFrame() = 0;
	EngineContext* myContext;

protected:
	std::vector<std::unique_ptr<RenderPass>> myPasses;
};

class RenderPass 
{

};
