#ifndef GL_WINDOW_H
#define GL_WINDOW_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <Camera.hpp>
#include <ManipulateMat.hpp>
class Window {
    public:
        Window();
        void processInput();
        unsigned int getError();
        GLFWwindow* getWindow();
        float clacDeltaTime();

         
    private: 
        unsigned int ERROR;
        GLFWwindow* window;
        float deltaTime;
        float lastFrame;
        
};

#endif