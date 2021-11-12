#include <Window.hpp>
#include <callback.hpp>
extern Calc<glm::vec3>* vecFront;
extern Calc<glm::vec3>* vecUp;
Window::Window()  {
    if (!glfwInit())
    {
        printf("Failed to initialize GLFW.\n");
        this->ERROR = 1;
        return;
    }

    // tell glfw that we want to use OpenGL 3.3+
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // tell glfw that the window should be floating on top of other windows
    glfwWindowHint(GLFW_FLOATING, GL_TRUE);

    // tell glfw that the window should not be resizable
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // 2. Create main window
    this->window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!this->window)
    {
        printf("Failed to create window.\n");
        this->ERROR = 1;
        return;
    }


    // tell GLFW that we want to draw on this specific window
    glfwMakeContextCurrent(this->window);
    glfwSetCursorPosCallback(this->window, mouse_callback);
    glfwSetScrollCallback(this->window, scoll_callback);
    
    // 3. Initialize GLEW (api to use OpenGL)
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "GLEW error: %s\n", glewGetErrorString(err));
        this->ERROR = 1;
        return;
    }

    glEnable(GL_DEPTH_TEST);

}

unsigned int Window::getError() {
    return this->ERROR;
}

GLFWwindow* Window::getWindow() {
    return this->window;
}

float Window::clacDeltaTime(){
    float currentFrame = glfwGetTime();
    this->deltaTime = currentFrame - this->lastFrame;
    this->lastFrame = currentFrame;
    return this->deltaTime;
}
void Window::processInput() {
    if(glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    camera->setCameraSpeed(2.5f * this->clacDeltaTime());
    if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS)
        camera->setCameraPos(camera->getCameraPos() + camera->getCameraSpeed() * camera->getCameraFront());
    if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS)
        camera->setCameraPos(camera->getCameraPos() - camera->getCameraSpeed() * camera->getCameraFront());
    if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS) {
        vecFront->setVector(camera->getCameraFront());
        vecUp->setVector(camera->getCameraUp());
        camera->setCameraPos(camera->getCameraPos() - ((*vecFront)^vecUp) *camera->getCameraSpeed());
    }
    if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS) {
        vecFront->setVector(camera->getCameraFront());
        vecUp->setVector(camera->getCameraUp());
        camera->setCameraPos(camera->getCameraPos() + ((*vecFront)^vecUp) *camera->getCameraSpeed());
    }
}



