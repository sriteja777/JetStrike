//
// Created by sriteja on 17/2/19.
//

#include "Ring.h"

Ring::Ring(glm::vec3 position, float radius) {
    this->position = position;
    this->radius = radius;
    float x1, y1, z1, angle =0;
    z1 = position.z;
    int n=360;
    for (int i=0;i<n;i++)
    {
        x1 = this->position.x + this->radius*std::cos(glm::radians(angle));
        y1 = this->position.y + this->radius*std::sin(glm::radians(angle));
        strips.emplace_back(Cylinder({x1, y1, z1}, 1, 0.7, COLOR_YELLOW));
        strips[i].rotate(90, ORIGIN, Y_AXIS);
        strips[i].rotate(angle, ORIGIN, Z_AXIS);
        angle += 1;
    }
}


void Ring::draw(glm::mat4 VP) {
    for (auto &strip : strips)
        strip.draw(VP);
}