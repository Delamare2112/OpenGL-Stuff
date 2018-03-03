#include "Engine/Camera.hpp"
#include "FPSInput.h"

FPSInput* FPSInput::currentHandler = nullptr;

FPSInput::FPSInput()
{
    firstMouse = true;
    previousMouseX = Game::width / 2;
    previousMouseY = Game::height / 2;

    glfwSetInputMode(Game::GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(Game::GetWindow(), FPSInput::MouseCallback);

    if (currentHandler == nullptr)
        currentHandler = this;
}

void FPSInput::MouseCallback(GLFWwindow* window, double xpos, double ypos)
{
    FPSInput& input = *currentHandler;
    if (input.firstMouse)
    {
        input.previousMouseX = xpos;
        input.previousMouseY = ypos;
        input.firstMouse = false;
    }

    input.yaw += (xpos - input.previousMouseX) * input.mouseSensitivity;
    input.pitch += (input.previousMouseY - ypos) * input.mouseSensitivity;

    if (input.yaw > 89.0f)
        input.yaw = 89.0f;
    if (input.pitch > 89.0f)
        input.pitch = 89.0f;

    Camera::currentCamera->front = glm::normalize(glm::vec3(
        cos(glm::radians(input.yaw)) * cos(glm::radians(input.pitch)),
        sin(glm::radians(input.pitch)),
        sin(glm::radians(input.yaw)) * cos(glm::radians(input.pitch))
    ));

    input.previousMouseX = xpos;
    input.previousMouseY = ypos;
}

void FPSInput::Tick()
{
    glfwPollEvents();
    const glm::vec3& cameraFront = Camera::currentCamera->front;

    glm::vec3 camPos = Camera::currentCamera->transform->GetPosition();

    const float speed = movementSpeed * Game::deltaTime;

    if (glfwGetKey(Game::GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
        camPos += speed * cameraFront;
    if (glfwGetKey(Game::GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
        camPos -= speed * cameraFront;
    if (glfwGetKey(Game::GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
        camPos -= glm::normalize(glm::cross(cameraFront, Transform::up)) * speed;
    if (glfwGetKey(Game::GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
        camPos += glm::normalize(glm::cross(cameraFront, Transform::up)) * speed;
    Camera::currentCamera->transform->SetPosition(camPos);
}

