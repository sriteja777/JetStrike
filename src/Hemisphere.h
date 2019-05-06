//
// Created by sriteja on 20/2/19.
//

#ifndef JETSTRIKE_HEMISPHERE_H
#define JETSTRIKE_HEMISPHERE_H

#include "main.h"

class Hemisphere {
public:
    Hemisphere() {}
    Hemisphere(glm::vec3 center, float radius, color_t color, int n = 360);
    void draw(glm::mat4 VP);
    glm::vec3 center;
    float radius;
    glm::mat4 model_matrix;
    void rotate(float angle, glm::vec3 point, glm::vec3 axis);

private:
    VAO *object;
};


#endif //JETSTRIKE_HEMISPHERE_H
