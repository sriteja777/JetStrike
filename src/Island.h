//
// Created by sriteja on 20/2/19.
//

#ifndef JETSTRIKE_ISLAND_H
#define JETSTRIKE_ISLAND_H

#include "main.h"
#include "Cuboid.h"
#include "Canon.h"
#include "Arrow.h"

class Island {
public:
    Island() {}
    Island(glm::vec3 position);
    void draw(glm::mat4 VP);
    glm::vec3 position;
    Cuboid ground;
    Canon enemy;
    Arrow arrow;
    void tick(glm::vec3 player_position);

};


#endif //JETSTRIKE_ISLAND_H
