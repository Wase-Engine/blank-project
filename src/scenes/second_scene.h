#pragma once

#include <memory.h>

#include <GL/glew.h>

#include <debugging/log.h>
#include <scene/scene.h>
#include <scene/scene_manager.h>
#include <rendering/vao.h>
#include <rendering/ibo.h>
#include <rendering/vbo.h>
#include <rendering/shader.h>
#include <rendering/vertex_buffer_layout.h>

class SecondScene : public wase::scene::Scene
{
public:
	void start() override
	{
		WASE_CORE_INFO("Second scene here!");

		float vertices[] = {
			 0.5f,  0.5f,  // TR
			 0.5f, -0.5f,  // BR
			-0.5f, -0.5f,  // BL
			-0.5f,  0.5f   // TL 
		};

		unsigned int indices[]{
			0, 1, 3,
			1, 2, 3
		};
		
		m_VAO = std::make_unique<wase::rendering::VAO>();
		m_VAO->bind();
		
		m_VBO = std::make_unique<wase::rendering::VBO>();
		m_VBO->bind();
		m_VBO->setData(vertices, sizeof(vertices));

		m_IBO = std::make_unique<wase::rendering::IBO>();
		m_IBO->bind();
		m_IBO->setData(indices, sizeof(indices));

		wase::rendering::VertexBufferLayout layout;
		layout.pushFloat(2);
		
		m_VAO->addBuffer(*m_VBO, layout);

		m_Shader = std::make_shared<wase::rendering::Shader>("assets/shader.vert", "assets/shader.frag");
	}

	void update(const float deltaTime) override
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		if (m_Context.input->isKeyPressed(GLFW_KEY_SPACE))
			m_Context.sceneManager->setActiveScene("main");

		m_Shader->bind();
		m_VAO->bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

private:
	std::shared_ptr<wase::rendering::Shader> m_Shader;
	std::shared_ptr<wase::rendering::VAO> m_VAO;
	std::shared_ptr<wase::rendering::VBO> m_VBO;
	std::shared_ptr<wase::rendering::IBO> m_IBO;
};