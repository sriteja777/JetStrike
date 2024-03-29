//
// Created by sriteja on 10/2/19.
//

#ifndef JETSTRIKE_CYLINDER_H
#define JETSTRIKE_CYLINDER_H

#include "main.h"

class Cylinder {
public:
    Cylinder() {}
    Cylinder(glm::vec3 position, float, float, color_t, glm::vec3 scale = {1,1,1});
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    float length,radius;
    glm::mat4 model_matrix;
    void update_position(glm::vec3 change);
    void rotate(float angle, glm::vec3 point , glm::vec3 axis);
    void rotate(glm::mat4 rotate_mat, glm::vec3 point = ORIGIN);
    void align();
private:
    VAO *object;
};


#endif //JETSTRIKE_CYLINDER_H
