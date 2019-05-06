//
// Created by sriteja on 19/2/19.
//

#ifndef JETSTRIKE_BOMB_H
#define JETSTRIKE_BOMB_H

#include "main.h"
#include "Sphere.h"
#include "Jet.h"

class Bomb {
public:
    Bomb() {}
    Bomb(Jet plane);
    void draw(glm::mat4 VP);
    void tick();
    void move_down();
    glm::vec3 position;
    Sphere body;

};


#endif //JETSTRIKE_BOMB_H
