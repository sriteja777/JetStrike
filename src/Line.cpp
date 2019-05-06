//
// Created by sriteja on 17/2/19.
//

#include "Line.h"


Line::Line(glm::vec3 position, glm::vec3 direction, float length, color_t color) {
    this->position  = position;
    this->direction = glm::normalize(direction);
    this->length = length;
    GLfloat line_buffer[] = {
            0, 0, 0,
            0, length, 0
    };
    this->object = create3DObject(GL_LINE_STRIP, 2, line_buffer, color);
    model_matrix = glm::mat4(1.0f);
    align();
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    model_matrix = translate * model_matrix;
//    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), rotation_axis);
}

void Line::draw(glm::mat4 VP) {
    glm::mat4 MVP = VP * model_matrix;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}


void Line::align() {
    glm::vec3 axis = direction;
    glm::mat4 rot (1.0f);

    rot[1] = glm::vec4(axis.x, axis.y, axis.z, 0);
    glm::vec3 temp = glm::cross(axis, glm::vec3(1, 0, 0));
    rot[0] = glm::vec4(temp.x, temp.y, temp.z, 0);
    glm::vec3 temp2 = glm::cross(axis, temp);
    model_matrix  = rot * model_matrix;
//    head.rotate(rot, {1, -1, 0});
//    body.rotate(rot, {0.5, 0, 0});
}


void Line::update_position(glm::vec3 change) {
    this->position += change;
    glm::mat4 translate = glm::translate (change);
    this->model_matrix = translate * this->model_matrix;
}


void Line::rotate(float angle, glm::vec3 point, glm::vec3 axis) {
    glm::mat4 translate = glm::translate(-point-this->position);
    glm::mat4 rotate_mat = glm::rotate(glm::radians(angle), axis);
    glm::mat4 translate_inv = glm::translate(point+this->position);
    glm::mat4 total = translate_inv * rotate_mat * translate;

    model_matrix = total * model_matrix;

}


void Line::rotate(glm::mat4 rotate_mat, glm::vec3 point) {
    glm::mat4 translate = glm::translate(-point-this->position);
    glm::mat4 translate_inv = glm::translate(point+this->position);

    glm::mat4 total = translate_inv * rotate_mat * translate;

    model_matrix = total * model_matrix;

    glm::vec4 temp =  total * glm::vec4(position.x, position.y, position.z, 1);
}