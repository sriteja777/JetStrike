//
// Created by sriteja on 4/2/19.
//

#ifndef JETSTRIKE_SPHERE_H
#define JETSTRIKE_SPHERE_H

#include "main.h"
#include "Circle.h"

class Sphere {
public:
    Sphere() {};
    Sphere(glm::vec3 center, float radius);
    unsigned int sphereVAO = 0;
    unsigned int indexCount;
    void draw(glm::mat4 VP);
    glm::vec3 center;
    float radius;
    std::vector<Circle> circles;

};


#endif //JETSTRIKE_SPHERE_H
