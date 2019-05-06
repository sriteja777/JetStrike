//
// Created by sriteja on 12/2/19.
//

#ifndef JETSTRIKE_MOUNTAIN_H
#define JETSTRIKE_MOUNTAIN_H

#include "main.h"
#include "Cone.h"
#include "ObliqueCone.h"

class Mountain {
public:
    Mountain() {}
    Mountain(glm::vec3 position, float length, float radius);
    void draw(glm::mat4 VP);
    std::vector<ObliqueCone> summits;
    ObliqueCone t;
    glm::vec3 position;

};


#endif //JETSTRIKE_MOUNTAIN_H
