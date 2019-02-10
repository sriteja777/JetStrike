//
// Created by sriteja on 2/2/19.
//

#ifndef JETSTRIKE_CUBOID_H
#define JETSTRIKE_CUBOID_H


#include "main.h"

class Cuboid {
public:
    Cuboid() {};
    Cuboid(glm::vec3 center, float width, float height, float depth, color_t color);
    void draw(glm::mat4 VP, glm::vec3 rotation_axis=glm::vec3(0, 0, 1));
    float width;
    float height;
    float depth;
    glm::vec3 center;
    float rotation;
    glm::vec3 scale;
private:
    VAO *object;
};


#endif //JETSTRIKE_CUBOID_H
