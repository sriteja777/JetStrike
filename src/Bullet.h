//
// Created by sriteja on 17/2/19.
//

#ifndef JETSTRIKE_BULLET_H
#define JETSTRIKE_BULLET_H

#include "Jet.h"
#include "Line.h"

class Bullet {
public:
    Bullet() {}
    Bullet(Jet jet);
    void tick();
    void draw(glm::mat4 VP);

    glm::vec3 axis;
    Line left_bullet;
    Line right_bullet;
};


#endif //JETSTRIKE_BULLET_H
