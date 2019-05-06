//
// Created by sriteja on 19/2/19.
//

#ifndef JETSTRIKE_CANON_H
#define JETSTRIKE_CANON_H

#include "main.h"
#include "Cuboid.h"
#include "Cylinder.h"
#include "Sphere.h"

class Canon {
public:
    Canon() {}
    Canon (glm::vec3 position);
    void draw(glm::mat4 VP);
    glm::vec3 position;
    Cuboid base;
    Sphere shooter;
    void shoot(glm::vec3 player_position);
    std::vector<Sphere> balls;
    std::vector<glm::vec3> ball_directions;
    void tick(glm::vec3 player_position);
};


#endif //JETSTRIKE_CANON_H
