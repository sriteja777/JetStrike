//
// Created by sriteja on 17/2/19.
//

#ifndef JETSTRIKE_LINE_H
#define JETSTRIKE_LINE_H

#include "main.h"

class Line {
public:
    Line() {}
    Line(glm::vec3 position, glm::vec3 direction, float length, color_t color);
    void draw(glm::mat4 VP);
    void align();
    void update_position(glm::vec3 change);
    void rotate(glm::mat4 rotate_mat, glm::vec3 point = ORIGIN);
    void rotate(float angle, glm::vec3 point , glm::vec3 axis);
    glm::vec3 position;
    glm::vec3 direction;
    float length;
private:
    VAO *object;
    glm::mat4 model_matrix;
};


#endif //JETSTRIKE_BULLET_H
