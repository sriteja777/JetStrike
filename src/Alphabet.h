//
// Created by sriteja on 18/2/19.
//

#ifndef JETSTRIKE_ALPHABET_H
#define JETSTRIKE_ALPHABET_H

#include "main.h"
#include "Line.h"

class Alphabet {
public:
    Alphabet() {}
    Alphabet(glm::vec3 position, char alphabet, color_t color);
    void draw(glm::mat4 VP);
    char alphabet;
    glm::vec3 position;
    std::vector <Line> lines;
    color_t color;
};


#endif //JETSTRIKE_ALPHABET_H
