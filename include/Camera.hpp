#ifndef GL_CAMERA_H
#define GL_CAMERA_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Window.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
    public:
        Camera();
        void cameraRotate();
        void cameraUpdate();
        void processKeyboard();
        void processMouseMovement(float xOffset, float yOffset);
        void processMouseScroll(float yOffset);
        void updateVectors();
        float getZoom();
        glm::mat4 getView();
        glm::vec3 getCameraPos();
        glm::vec3 getCameraFront();
        glm::vec3 getCameraUp();
        float getCameraSpeed();
        void setCameraSpeed(float speed);
        void setCameraPos(glm::vec3 position);
        void setCameraRight(glm::vec3 right);
        
    private:
        float cameraSpeed;
        float yaw;
        float pitch;
        float mouseSensitivity;
        float zoom;
        glm::vec3 cameraPos;
        glm::vec3 cameraFront;
        glm::vec3 cameraUp;
        glm::mat4 view;
        glm::vec3 cameraRight;
        glm::vec3 worldUp;

};

#endif