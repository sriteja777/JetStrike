//
// Created by sriteja on 2/2/19.
//

#include "Camera.h"

Camera::Camera(glm::vec3 eye, glm::vec3 target, glm::vec3 up) {
    this->eye = eye;
    this->target = target;
    this->up = up;
}