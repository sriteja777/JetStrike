//
// Created by sriteja on 20/2/19.
//

#include "Island.h"



Island::Island(glm::vec3 position) {
    this->position = position;
    ground = Cuboid(position, 10, 4, 10, COLOR_SANDY_BROWN);
    float canon_radius = 1;
    enemy = Canon(glm::vec3 (position.x + ground.width/2 -2*canon_radius, position.y + ground.height/2 - 2*canon_radius, position.z + ground.depth/2 - 2*canon_radius));
    arrow = Arrow(glm::vec3 (position.x, position.y + 20, position.z), -Y_AXIS);

}

void Island::draw(glm::mat4 VP) {
    ground.draw(VP);
    enemy.draw(VP);
    arrow.draw(VP);
}

void Island::tick(glm::vec3 player_position) {

    enemy.tick(player_position);
}