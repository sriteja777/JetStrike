//
// Created by sriteja on 17/2/19.
//

#include "VariableRectangle.h"


VariableRectangle::VariableRectangle(glm::vec3 position, float max_length, float max_breadth, color_t border_color, color_t fillup_color) {
    this->position = position;
    this->max_length = max_length;
    this->max_breadth = max_breadth;
    this->border_color = border_color;
    this->fill_up_color = fillup_color;

    GLfloat vert[] = {
            0, 0, 0,
            max_length, 0, 0,
            max_length, max_breadth, 0,
            0,max_breadth,0
    };

    this->border_object = create3DObject(GL_LINE_LOOP, 4, vert, border_color, GL_FILL);

    this->model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(position)*model_matrix;
}


void VariableRectangle::draw(glm::mat4 VP, float length, float breadth) {
    if (breadth <= max_breadth) {
        GLfloat vertices_buffer[] = {
                0, 0, 0,
                length, 0, 0,
                0, breadth, 0,
                0, breadth, 0,
                length, breadth, 0,
                length, 0, 0
        };
        this->object = create3DObject(GL_TRIANGLES, 6, vertices_buffer, fill_up_color, GL_FILL);
    }

    glm::mat4 MVP = VP*model_matrix;

    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
//    print_array(this-)
    draw3DObject(this->object);
    draw3DObject(this->border_object);
}