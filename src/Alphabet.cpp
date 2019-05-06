//
// Created by sriteja on 18/2/19.
//

#include "Alphabet.h"


Alphabet::Alphabet(glm::vec3 position, char alphabet, color_t color) {
    this->position = position;
    this->alphabet = alphabet;
    this->color = color;
    if (this->alphabet == 'H') {
//        printf("came\n");
//        exit(0);
        lines.emplace_back(Line(position, Y_AXIS, 0.1, color));
        lines.emplace_back(Line({position.x+1.3, position.y, position.z}, Y_AXIS, 0.1, color));
        lines.emplace_back(Line({position.x, position.y+0.05, position.z}, X_AXIS, 1.3, color));

    }

    if (this->alphabet == 'F') {
        lines.emplace_back(Line(position, Y_AXIS, 0.1, color));
        lines.emplace_back(Line({position.x, position.y+0.1, position.z}, X_AXIS, 1.3, color));
        lines.emplace_back(Line({position.x, position.y+0.06, position.z}, X_AXIS, 1, color));

    }

    if (this->alphabet == 'V') {

        lines.emplace_back(Line(position, glm::vec3(1,-1,0), 0.07, color));
        lines.emplace_back(Line({position.x + 0.05, position.y-0.05, position.z}, glm::vec3(1,1,0), 0.07, color));
    }
    if (this->alphabet == 'N') {
        lines.emplace_back(Line(position, Y_AXIS, 0.07, color));
        lines.emplace_back((Line({position.x, position.y + 0.07, position.z}, glm::vec3( 0.2f, -0.9, 0), 0.08, color)));
        lines.emplace_back(Line({position.x+0.02, position.y, position.z}, Y_AXIS, 0.07, color));
    }
//    model_matrix = glm::mat4(1);
//    model_matrix *= glm::translate(position);
}

void Alphabet::draw(glm::mat4 VP) {
    for (auto &line : lines) {
        line.draw(VP);
    }
}