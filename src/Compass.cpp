//
// Created by sriteja on 19/2/19.
//

#include "Compass.h"
#include "Jet.h"

//extern Jet player;

Compass::Compass(glm::vec3 position) {
    this->position = position;
    GLfloat coor[] = {
            -0.03f, 0, 0,
            0.03f, 0, 0,
            0, 0.1, 0
    };
//    position.y -= 1;
//    position.x -=1;
//    position.z -= 1;
//    print_mat4(down_arrow.model_matrix);
//
//    print_mat4(down_arrow.model_matrix);
//    exit(0);
//position.y += 1.f;
    up_arrow = TwoDPolygon(3, coor, position, COLOR_RED);
    down_arrow = TwoDPolygon(3, coor, position, COLOR_SADDLE_BROWN);
    down_arrow.reflect( X_AXIS);
    border = Circle(position, 0.12, COLOR_THISTLE);
    north = Alphabet({position.x-0.01, position.y + 0.15, position.z}, 'N', COLOR_SADDLE_BROWN);
}

void Compass::draw(glm::mat4 VP) {
//    up_arrow.rotate(glm::degrees(acos(-player.jet_axis.z)), ORIGIN, Z_AXIS);
    border.draw(VP);
    this->up_arrow.draw(VP);
    this->down_arrow.draw(VP);
    this->north.draw(VP);
}

void Compass::rotate(float angle) {
    up_arrow.rotate(angle, ORIGIN, Z_AXIS);
    down_arrow.rotate(angle, ORIGIN, Z_AXIS);
}

void Compass::align(glm::vec3 player_axis) {
    glm::mat4 rot;
//    rot[1] = glm::vec4(0)
}