//
// Created by sriteja on 18/2/19.
//

#ifndef JETSTRIKE_INDICATOR_H
#define JETSTRIKE_INDICATOR_H


#include "main.h"
#include "VariableRectangle.h"
#include "Alphabet.h"

class Indicator {
public:
    Indicator() {}
    Indicator(glm::vec3 position, char alphabet);
    void draw(glm::mat4 VP, float length, float breadth);
    glm::vec3 position;
    VariableRectangle box;
    Alphabet text;
};


#endif //JETSTRIKE_INDICATOR_H
