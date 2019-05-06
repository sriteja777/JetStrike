//
// Created by sriteja on 17/2/19.
//

#ifndef JETSTRIKE_RING_H
#define JETSTRIKE_RING_H

#include "main.h"
#include "Cylinder.h"

class Ring {
public:
    Ring() {}
    Ring(glm::vec3 position, float radius);
    glm::vec3 position;
    float radius;
    void draw(glm::mat4 VP);
    std::vector <Cylinder> strips;
};


#endif //JETSTRIKE_RING_H
