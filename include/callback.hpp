#include <GLFW/glfw3.h>
#include <Camera.hpp>
extern Camera* camera;
float lastX = 300.0f;
float lastY = 400.0f;
bool firstMouse = true;
float fov = 45.0f;
void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if(firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    float xOffset = xpos - lastX;
    float yOffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;
    camera->processMouseMovement(xOffset, yOffset);
}

void scoll_callback (GLFWwindow* window, double xOffset, double yOffset)
{
    camera->processMouseScroll(yOffset);
}