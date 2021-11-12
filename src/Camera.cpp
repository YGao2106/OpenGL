#include <Camera.hpp>
extern Window* win;
Camera::Camera() {
    this->cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    this->worldUp = this->cameraUp;
    this->cameraSpeed = 0.02f;
    
    this->yaw = -90.0f;
    this->pitch = 0.0f;
    this->mouseSensitivity = 0.1f;
    this->zoom = 45.0f;
    this->updateVectors();
    this->view = glm::lookAt(this->cameraPos, this->cameraPos+ this->cameraFront, this->cameraUp);
}
void Camera::cameraRotate() {
    const float  radius = 10.0f;
    float camX = sin(glfwGetTime()) *radius;
    float camZ = cos(glfwGetTime())* radius;
    this->cameraPos = glm::vec3(camX, 0.0f, camZ);
    this->cameraUpdate();
    
}
void Camera::cameraUpdate() {
    
    this->view = glm::lookAt(this->cameraPos, this->cameraPos+ this->cameraFront, this->cameraUp);
}

void Camera::updateVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    front.y = sin(glm::radians(this->pitch));
    front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->cameraFront = glm::normalize(front);
    this->cameraRight = glm::normalize(glm::cross(this->cameraFront, this->worldUp));
    this->cameraUp = glm::normalize(glm::cross(this->cameraRight, this->cameraFront));
}
float Camera::getZoom() {return this->zoom;}
glm::mat4 Camera::getView() {return this->view;}
glm::vec3 Camera::getCameraPos() {return this->cameraPos;}
glm::vec3 Camera::getCameraFront() {return this->cameraFront;}
glm::vec3 Camera::getCameraUp() {return this->cameraUp;}
float Camera::getCameraSpeed() {return this->cameraSpeed;}
void Camera::setCameraSpeed(float speed) {
    this->cameraSpeed = speed;
    return;
}
void Camera::setCameraPos(glm::vec3 position) {
    this->cameraPos = position;
    return;
}
void Camera::setCameraRight(glm::vec3 right) {
    this->cameraRight = right;
    return;
}
void Camera::processKeyboard() {}

void Camera::processMouseMovement(float xOffset, float yOffset) {
    xOffset *= this->mouseSensitivity;
    yOffset *= this->mouseSensitivity;
    this->yaw += xOffset;
    this->pitch += yOffset;

    if(this->pitch>89.0f) this->pitch = 89.0f;
    if(this->pitch < -89.0f) this->pitch = -89.0f;

    this->updateVectors();
}
void Camera::processMouseScroll(float yOffset) {
    this->zoom -= (float)yOffset;
    if (this->zoom < 1.0f) this->zoom = 1.0f;
    if (this->zoom > 45.0f) this->zoom = 45.0f; 
}
