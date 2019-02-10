//
// Created by sriteja on 10/2/19.
//

#include "Cone.h"

Cone::Cone(glm::vec3 position, float length, float radius, color_t color, float initial_rotation_angle,
           glm::vec3 rotation_axis) {
    this->position = position;
    this->length = length;
    this->radius = radius;
    this->rotation = initial_rotation_angle;
    this->rotation_axis = rotation_axis;
    GLfloat vertex_buffer_data[14000];

    int idx=0;
//    for(int i=0;i<=360;i++)
//    {
//        int j=i+1;
//        vertex_buffer_data[idx++] = radius*cos(M_PI*i/180);
//        vertex_buffer_data[idx++] = radius*sin(M_PI*i/180);
//        vertex_buffer_data[idx++] = 0;
//        vertex_buffer_data[idx++] = radius*cos(M_PI*i/180);
//        vertex_buffer_data[idx++] = radius*sin(M_PI*i/180);
//        vertex_buffer_data[idx++] = length;
//        vertex_buffer_data[idx++] = radius*cos(M_PI*j/180);
//        vertex_buffer_data[idx++] = radius*sin(M_PI*j/180);
//        vertex_buffer_data[idx++] = 0;
//        vertex_buffer_data[idx++] = radius*cos(M_PI*j/180);
//        vertex_buffer_data[idx++] = radius*sin(M_PI*j/180);
//        vertex_buffer_data[idx++] = 0;
//        vertex_buffer_data[idx++] = radius*cos(M_PI*i/180);
//        vertex_buffer_data[idx++] = radius*sin(M_PI*i/180);
//        vertex_buffer_data[idx++] = length;
//        vertex_buffer_data[idx++] = radius*cos(M_PI*j/180);
//        vertex_buffer_data[idx++] = radius*sin(M_PI*j/180);
//        vertex_buffer_data[idx++] = length;
//    }
    float angle = 0.0f;
    int n=360;
    for(int i=0,j=1;i<n;i++,j++) {
        vertex_buffer_data[idx++] = 0.0f;
        vertex_buffer_data[idx++] = 0.0f;
        vertex_buffer_data[idx++] = 0.0f;
        vertex_buffer_data[idx++] = radius*std::cos(glm::radians(angle));
        vertex_buffer_data[idx++] = radius*std::sin(glm::radians(angle));
        vertex_buffer_data[idx++] = length;
        angle += 1;
        vertex_buffer_data[idx++] = radius*std::cos(glm::radians(angle));
        vertex_buffer_data[idx++] = radius*std::sin(glm::radians(angle));
        vertex_buffer_data[idx++] = length;
    }

    this->object = create3DObject(GL_TRIANGLES, n*3, vertex_buffer_data, color);
}

void Cone::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 orient    = glm::rotate((float) (this->orientation * M_PI / 180.0f), glm::vec3(1,0,0));
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), this->rotation_axis);
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // this->new_Barrel_end=Matrices.model*this->Barrel_end;
    // printf("%f %f %f\n",this->new_Barrel_end.x,this->new_Barrel_end.y,this->new_Barrel_end.z);
    draw3DObject(this->object);
}
