//
// Created by sriteja on 20/2/19.
//

#ifndef JETSTRIKE_MISSILE_H
#define JETSTRIKE_MISSILE_H

#include "main.h"
#include "Cylinder.h"
#include "Cone.h"

class Missile {
public:
    Missile() {}
    Missile(glm::vec3 position, glm::vec3 direction);
    glm::vec3 position;
    glm::vec3 axis;
    Cone head;
    Cylinder body;
    void draw(glm::mat4 VP);
    void tick();
    void align(glm::vec3 direction);
    void move();

};


#endif //JETSTRIKE_MISSILE_H
