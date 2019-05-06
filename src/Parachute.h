//
// Created by sriteja on 20/2/19.
//

#ifndef JETSTRIKE_PARACHUTE_H
#define JETSTRIKE_PARACHUTE_H

#include "main.h"
#include "Hemisphere.h"
#include "Cuboid.h"
#include "Cylinder.h"
#include "Line.h"
#include "Missile.h"


class Parachute {
public:
    Parachute() {}
    Parachute(glm::vec3 position);
    void draw(glm::mat4 VP);
    glm::vec3 position;
    Hemisphere canopy;
    Cuboid payload;
    Cylinder link;
    std::vector<Line> suspension_lines;
    std::vector<Missile> missiles;
    std::vector<glm::vec3> missile_directions;
    void shoot(glm::vec3 player_position);
    void tick(glm::vec3 player_position);


};


#endif //JETSTRIKE_PARACHUTE_H
