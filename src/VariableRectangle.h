//
// Created by sriteja on 17/2/19.
//

#ifndef JETSTRIKE_VARIABLERECTANGLE_H
#define JETSTRIKE_VARIABLERECTANGLE_H

#include "main.h"

class VariableRectangle {
public:
    VariableRectangle() {}

    VariableRectangle(glm::vec3 position, float max_length, float max_breadth, color_t border_color, color_t fillup_color);
    void draw(glm::mat4 VP, float length, float breadth);
    float max_length;
    float max_breadth;
    glm::vec3 position;
    bool changed;
    color_t  border_color;
    color_t fill_up_color;
    glm::mat4 model_matrix;
private:
    VAO * object;
    VAO *border_object;
};


#endif //JETSTRIKE_VARIABLERECTANGLE_H
