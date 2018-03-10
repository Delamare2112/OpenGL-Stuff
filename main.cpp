#include <glm/gtc/type_ptr.hpp>
#include "Engine/Game.hpp"
#include "Engine/Entity.hpp"
#include "Cube.hpp"
#include "Engine/Camera.hpp"
#include "FPSInput.h"

int main()
{
	std::cout << "Sanity Check!\n";
	assert(Game::Init(800, 600));

//	Shader& happyBox = Game::shaderLibrary["HappyColors"]; // Make new shader called HappyColors
//	happyBox.Create("Engine/texVertex.glsl", "Engine/texFragment.glsl"); // Create the new shader
//	happyBox.AddTexture("container.jpg", "ourTexture1"); // Add some textures
//	happyBox.AddTexture("awesomeface.png", "ourTexture2");

	Shader& defaultShader = Game::shaderLibrary["default"];
	defaultShader.Create("Engine/defaultVertexShader.glsl", "Engine/uniformColoredFragmentShader.glsl");

	Material& defaultMaterial = Game::materialLibrary["default"];
	defaultMaterial.SetShader(&defaultShader);
	defaultMaterial.SetUniform("ourColor", 0.f, 0.8f, 0.2f);

	Mesh& cubeMesh = Game::meshLibrary["cube"];
	cubeMesh.Init("Engine/Cube.obj");

	unsigned int i = 0;
	auto* rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3( 0.0f,  0.0f,  0.0f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);
	rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3( 2.0f,  5.0f, -15.0f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);
	rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3(-1.5f, -2.2f, -2.5f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);
	rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3(-3.8f, -2.0f, -12.3f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);
	rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3( 2.4f, -0.4f, -3.5f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);
	rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3(-1.7f,  3.0f, -7.5f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);
	rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3( 1.3f, -2.0f, -2.5f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);
	rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3( 1.5f,  2.0f, -2.5f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);
	rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3( 1.5f,  0.2f, -1.5f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);
	rect = new Cube;
	rect->transform.model = glm::translate(rect->transform.model, glm::vec3(-1.3f,  1.0f, -1.5f));
	rect->transform.model = glm::rotate(rect->transform.model, glm::radians(20.f * i), glm::vec3(1.f, 0.3f, 0.5f));
	rect->materialInstance.SetUniform("ourColor", i * 0.1f, 0.8f, 0.2f);

    (new Camera())->transform.position = (glm::vec3(0.f, 0.f, 3.f));

	Game::SetClearColor({0.2f, 0.3f, 0.3f, 1.f});

	FPSInput input;
	input.movementSpeed = 2.5f;
	input.mouseSensitivity = 0.1f;

	// Game loop
	while(!glfwWindowShouldClose(Game::GetWindow()))
	{
		Game::Tick();
		input.Tick();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear buffer and fill with ClearColor
		for(std::pair<std::string, Shader> shader : Game::shaderLibrary)
		{
			shader.second.Use();
			auto viewLoc = glGetUniformLocation(shader.second.GetProgram(), "view");
			auto modelLoc = glGetUniformLocation(shader.second.GetProgram(), "model");
			auto projectionLoc = glGetUniformLocation(shader.second.GetProgram(), "projection");
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(Camera::currentCamera->getView()));
			glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(Camera::currentCamera->getProjection()));
			for (Mesh* mesh : shader.second.referencedMeshes)
			{
				mesh->BindVerts();
				for (Material* material : mesh->referencedMaterials)
				{
					material->Apply();
					for (glm::mat4* model : material->referencedTransforms)
					{
						glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(*model));
						glDrawElements(GL_TRIANGLES, mesh->numIndicies, GL_UNSIGNED_INT, nullptr);
					}
				}
			}
		}
		glBindVertexArray(0);

		glfwSwapBuffers(Game::GetWindow());
	}
	Game::Exit();

	std::cout << "Byebye!" << std::endl;
	return 0;
}
