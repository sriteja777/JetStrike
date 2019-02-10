//
// Created by sriteja on 10/2/19.
//

#ifndef JETSTRIKE_OBLIQUECONE_H
#define JETSTRIKE_OBLIQUECONE_H

#include "main.h"

class ObliqueCone {
public:
    ObliqueCone() {}
    ObliqueCone(glm::vec3 position, glm::vec3 base_center, float length, float radius, color_t color,
                    float initial_rotation_angle = 0.0f, glm::vec3 rotation_axis = glm::vec3(0, 0, 1));

    glm::vec3 position;  // Cone vertex  position
    glm::vec3 vertex;
    glm::vec3 base_center; //Cone base center
    float radius;
    float length;
    float rotation;
    glm::vec3 rotation_axis;

    void draw(glm::mat4 VP);
private:
    VAO * object;

};


#endif //JETSTRIKE_OBLIQUECONE_H
