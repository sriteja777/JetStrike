//
// Created by sriteja on 20/2/19.
//

#include "Missile.h"

Missile::Missile(glm::vec3 position, glm::vec3 direction) {
    this->position = position;
    this->axis = -Z_AXIS;
    head = Cone(position, .3, .1, COLOR_PERU);
    body = Cylinder(position + glm::vec3 (0, 0,head.length), 1, head.radius, COLOR_SILVER);
    align(direction);
}



void Missile::draw(glm::mat4 VP) {
    head.draw(VP);
    body.draw(VP);
}

void Missile::tick() {
    float speed = 0.7;
    head.update_position(axis * speed);
    body.update_position(axis * speed);
}

void Missile::align(glm::vec3 direction) {
    glm::vec3 store = this->axis;
    this->axis = direction;
    glm::mat4 rot (1.0f);

    rot[2] = glm::vec4(-axis.x, -axis.y, -axis.z, 0);
    glm::vec3 temp;
    if (glm::all(glm::equal(direction, X_AXIS))) {
        temp = glm::cross(axis, Y_AXIS);
    }
    else {
        temp = glm::cross(axis, X_AXIS);
    }
    rot[0] = glm::vec4(temp.x, temp.y, temp.z, 0);
    glm::vec3 temp2 = glm::cross(axis, temp);
    rot[1] = glm::vec4 (temp2.x, temp2.y, temp2.z, 0);


    head.rotate(rot);
    body.rotate(rot, store * head.length);

}

//void Missile::move() {
//    this->po
//    head.update_position(axis * 1.f);
//    body.update_position(axis * 1.f);
//}
