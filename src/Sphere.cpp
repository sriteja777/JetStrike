//
// Created by sriteja on 4/2/19.
//

#include "Sphere.h"

Sphere::Sphere(glm::vec3 center, float radius, color_t color) {
    this->center = center;
    this->radius = radius;
    int n=250;
    float angle = 180.0f/n;
    float theta=0;
    for (int i=0;theta < 200;i++)
    {
        circles.emplace_back(center, this->radius, color, glm::vec3(0,1,0), theta);
        theta += angle;
    }

}

void Sphere::draw(glm::mat4 VP) {
    for (auto &circle : circles) {
        circle.draw(VP);
    }
}

void Sphere::update_position(glm::vec3 change) {
    for (auto &circle : circles) {
        circle.center += change;
    }
    center += change;
}