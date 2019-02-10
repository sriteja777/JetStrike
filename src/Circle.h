#include "main.h"

#ifndef JETSTRIKE_CIRCLE_H
#define JETSTRIKE_CIRCLE_H


class Circle {
public:
    Circle() {}
    Circle(glm::vec3 center, float radius, color_t color, glm::vec3 rotation_axis = glm::vec3(0.0f, 0.f, 1.0f),
               float initial_rotation_angle = 0.0f, float circle_angle = 360.0f);
    glm::vec3 center;
    float radius;
    float rotation;
    glm::vec3 rotation_axis;
    void draw(glm::mat4 VP);

    void tick();
    double speed;
    void construct(int n, float circle_angle = 360.0f);
//    double speed_y;
private:
    GLfloat vertex_data[10000];
    VAO *object;
};

#endif // JETSTRIKE_CIRCLE_H

