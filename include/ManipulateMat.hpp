#ifndef GL_MANIPULATEMAT_H
#define GL_MANIPULATEMAT_H
#include <GL/glew.h>
#include <string>
#include <Camera.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

template<typename T>
void setMatx(const std::string &name, const T &mat, unsigned int ID) {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

template<typename T1> class Calc {
    public:
        Calc(T1 vector) {
            this->vector = vector;
        }
        void setVector(T1 vector) {
            this->vector = vector;
        }
        T1 operator^(Calc<T1>* other)  {
            return glm::normalize(glm::cross(this->vector, other->vector));
        }

    private:
        T1 vector;
};

#endif