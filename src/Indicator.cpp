//
// Created by sriteja on 18/2/19.
//

#include "Indicator.h"

Indicator::Indicator(glm::vec3 position, char alphabet) {
    this->position = position;
    box = VariableRectangle(position, 1, 1, COLOR_SADDLE_BROWN, COLOR_RED);
    text = Alphabet({position.x-0.2, 0.03, 0}, alphabet, COLOR_BLACK);
}

void Indicator::draw(glm::mat4 VP, float length, float breadth) {
    box.draw(VP, length, breadth);
    text.draw(VP);
}
