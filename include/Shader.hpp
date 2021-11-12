#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <Camera.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
extern Camera* camera;

class Shader {
    public:        
        Shader(const char* vertexPath, const char* fragmentPath);
        void use();
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
        void setMat4(const std::string &name, const glm::mat4 &mat) const;
        
    private:
        void checkCompileErrors(unsigned int shader, std::string type);
    protected:
        unsigned int ID;
};


#endif