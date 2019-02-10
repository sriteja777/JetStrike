//
// Created by sriteja on 2/2/19.
//

#ifndef JETSTRIKE_CAMERA_H
#define JETSTRIKE_CAMERA_H

#include "main.h"
class Camera {
public:
    Camera() {}
    Camera(glm::vec3 eye, glm::vec3 target, glm::vec3 up);
    glm::vec3 eye;
    glm::vec3 target;
    glm::vec3 up;

};


#endif //JETSTRIKE_CAMERA_H
