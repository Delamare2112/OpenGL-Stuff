#pragma once
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

class FPSInput
{
private:
    float previousMouseY, previousMouseX, yaw, pitch;
    bool firstMouse;

    static void MouseCallback(GLFWwindow* window, double xpos, double ypos);

public:
    static FPSInput* currentHandler;

    float movementSpeed;
    float mouseSensitivity;

    FPSInput();
    void Tick();
};
