//
// Created by sriteja on 10/2/19.
//

#ifndef JETSTRIKE_CYLINDER_H
#define JETSTRIKE_CYLINDER_H

#include "main.h"

class Cylinder {
public:
    Cylinder() {}
    Cylinder(float x, float y, float z, float, float, color_t);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    double length,radius;
private:
    VAO *object;
};


#endif //JETSTRIKE_CYLINDER_H
