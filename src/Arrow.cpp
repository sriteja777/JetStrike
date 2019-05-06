//
// Created by sriteja on 17/2/19.
//

#include "Arrow.h"
#include "TwoDPolygon.h"


Arrow::Arrow(glm::vec3 position, glm::vec3 direction) {
    this->position = position;
    this->direction = glm::normalize(direction);

    GLfloat  body_coor[] = {
            1.0f, 1.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0, 1.0f, 0.0f
    };

    GLfloat head_coor[] = {
            0, 0, 0,
            1, 0.5, 0,
            2, 0, 0
    };

    body = TwoDPolygon(4, body_coor, position, COLOR_GREEN);
    head = TwoDPolygon(3, head_coor, {position.x-0.5, position.y+1, position.z}, COLOR_GREEN);
    auto unit_vec = glm::normalize(direction);
    align();
//    head.rotate(std::acos(direction.y), {0.5, -1, 0}, Y_AXIS);
//    head.rotate(std::acos(direction.x), {0.5, -1, 0}, X_AXIS);
//    head.rotate(std::acos(direction.z), {0.5, -1, 0}, Z_AXIS);
//    body.rotate(std::acos(direction.y), ORIGIN, Y_AXIS);
//    body.rotate(std::acos(direction.x), ORIGIN, X_AXIS);
//    body.rotate(std::acos(direction.z), ORIGIN, Z_AXIS);


}


void Arrow::align() {
    glm::vec3 axis = direction;
    glm::mat4 rot (1.0f);

    rot[1] = glm::vec4(axis.x, axis.y, axis.z, 0);
    glm::vec3 temp = glm::cross(axis, glm::vec3(1, 0, 0));
    rot[0] = glm::vec4(temp.x, temp.y, temp.z, 0);
    glm::vec3 temp2 = glm::cross(axis, temp);
    head.rotate(rot, {1, -1, 0});
    body.rotate(rot, {0.5, 0, 0});
//    this->head.model_matrix = this->head.model_matrix *
//    glm::mat4 rotate_x = glm::rotate(glm::radians(1.0f), glm::vec3(1,0,0));

}


void Arrow::draw(glm::mat4 VP) {
    this->head.draw(VP);
    this->body.draw(VP);
}

void Arrow::tick() {
    float angle = glm::radians(45.0f);
    head.rotate(angle, {1, -1, 0}, direction);
    body.rotate(angle, {0.5, 0, 0}, direction);

}