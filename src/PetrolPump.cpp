//
// Created by sriteja on 18/2/19.
//

#include "PetrolPump.h"


PetrolPump::PetrolPump(glm::vec3 position) {
    this->position = position;

//    GLfloat inner_vertices[] = {
//            0, 0, 0,
//            2, 0, 0,
//            2, 0.2, 0,
//            0, 0.2, 0
//    };

    GLfloat inner_vert[] ={
            0, 0, 0,
            0.4, 0, 0,
            0.4, 0.33, 0,
            0, 0.33, 0
    };
    outer_box = Cuboid(position, 0.5, 0.7, 0.2, COLOR_GREEN);
//    inner = TwoDPolygon(4, inner_vertices, position, COLOR_YELLOW);
    inner = TwoDPolygon(4, inner_vert, glm::vec3(position.x-0.2, position.y+0.01, position.z + 0.1+0.02), COLOR_WHITE);
}


void PetrolPump::draw(glm::mat4 VP) {
    this->inner.draw(VP);
//    this->outer.draw(VP);
    this->outer_box.draw(VP);
}