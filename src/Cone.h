//
// Created by sriteja on 10/2/19.
//

#ifndef JETSTRIKE_CONE_H
#define JETSTRIKE_CONE_H

#include "main.h"


class Cone {
public:
    Cone() {}
    Cone(glm::vec3 position, float length, float radius, color_t color, float initial_rotation_angle=0.0f,
             glm::vec3 rotation_axis = glm::vec3(0, 0, 1));

    glm::vec3 position;  // Cone vertex  position
    float radius;
    float length;
    float rotation;
    glm::vec3 rotation_axis;

    void draw(glm::mat4 VP);
private:
    VAO * object;
};


#endif //JETSTRIKE_CONE_H
