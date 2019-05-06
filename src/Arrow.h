//
// Created by sriteja on 17/2/19.
//

#ifndef JETSTRIKE_ARROW_H
#define JETSTRIKE_ARROW_H

#include "main.h"
#include "TwoDPolygon.h"

class Arrow {
public:
    Arrow() {}
    Arrow(glm::vec3 position, glm::vec3 direction);
    void draw(glm::mat4 VP);
    void align();
    void tick();
    glm::vec3 position;
    glm::vec3 direction;
    TwoDPolygon body;
    TwoDPolygon head;
};


#endif //JETSTRIKE_ARROW_H
