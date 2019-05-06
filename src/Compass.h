//
// Created by sriteja on 19/2/19.
//

#ifndef JETSTRIKE_COMPASS_H
#define JETSTRIKE_COMPASS_H

#include "main.h"
#include "TwoDPolygon.h"
#include "Circle.h"
#include "Alphabet.h"

class Compass {
public:
    Compass() {}
    Compass(glm::vec3 position);
    void draw(glm::mat4 VP);
    void rotate(float angle);
    void align(glm::vec3 player_axis);
    glm::vec3 position;
    Circle border;
    Alphabet  north;
    TwoDPolygon up_arrow;
    TwoDPolygon down_arrow;
};


#endif //JETSTRIKE_COMPASS_H
