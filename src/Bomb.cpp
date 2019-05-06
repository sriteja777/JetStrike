//
// Created by sriteja on 19/2/19.
//

#include "Bomb.h"


Bomb::Bomb(Jet plane) {
    this->position = glm::vec3 (plane.position.x, plane.position.y - 0.5, plane.position.z);
    body = Sphere(position, 0.1f, COLOR_PERU);

}

void Bomb::draw(glm::mat4 VP) {
    body.draw(VP);
}

void Bomb::tick() {

    move_down();
}

void Bomb::move_down() {
    body.update_position({0, -0.1, 0});
    this->position.y -= 0.1;
}