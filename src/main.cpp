#include <GL/glew.h> // needs to be included before glfw
#include <GLFW/glfw3.h>
#include <iostream>
#include <Window.hpp>
#include <Cube.hpp>

#include <Camera.hpp>
Camera* camera;
Window* win;
Calc<glm::vec3>* vecFront; 
Calc<glm::vec3>* vecUp; 

int main(int argc, char* argv[]) {
  win = new Window();
  if(!win->getError()) return 1;
  
  camera = new Camera();
  Cube* cube = new Cube("../Shader_src/Coordinate.vs", "../Shader_src/Texture.fs");
  cube->bindArray();
  cube->bindTexture();
  vecFront = new Calc<glm::vec3>(camera->getCameraFront());
  vecUp = new Calc<glm::vec3>(camera->getCameraUp());
  // application main loop
  while (!glfwWindowShouldClose(win->getWindow())) {
    win->processInput();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear screen
    glClearColor(0.2f, 0.3f, 0.3f, 1); // fill screen with green color
 
    cube->viewCube();
    //Swap buffer
    glfwSwapBuffers(win->getWindow()); // tell glfw to go to next frame
    glfwPollEvents();
  }


  // window was closed, so let's exit.
  glfwDestroyWindow(win->getWindow());
  glfwTerminate();
  return 0;
}
