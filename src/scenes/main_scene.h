#pragma once

#include <GL/glew.h>

#include <debugging/log.h>
#include <scene/scene.h>
#include <scene/scene_manager.h>
#include <input/input.h>
#include <engine.h>

class MainScene : public wase::scene::Scene
{
public:
	void start() override
	{
		WASE_CORE_INFO("Main scene here!");
		WASE_CORE_WARN("Test");
	}

	void update(const float deltaTime) override
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		if (m_Context.input->isKeyPressed(GLFW_KEY_SPACE))
			m_Context.sceneManager->setActiveScene("second");

		if (m_Context.input->isKeyPressed(GLFW_KEY_P))
			WASE_CORE_INFO("I wonder what the second scene looks like!");
	}
};