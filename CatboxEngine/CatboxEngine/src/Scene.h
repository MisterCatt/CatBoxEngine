#pragma once
#include <memory>
#include "Renderable.h"
#include "Camera.h"
#include "FrameBuffer.h"

//Main purpose of Scene is to hold all renderable objects and the main camera
//The camera is need as a context for the objects
class Scene
{
public:
	Scene(FrameBuffer* aFrameBuffer);

	void AddRenderable(std::unique_ptr<Renderable> render);

	std::unique_ptr<Camera> mainCamera;
	FrameBuffer* frameBuffer;

private:
	std::vector<std::unique_ptr<Renderable>> renders;

};

