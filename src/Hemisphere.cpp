//
// Created by sriteja on 20/2/19.
//

#include "Hemisphere.h"


Hemisphere::Hemisphere(glm::vec3 center, float radius, color_t color, int n) {
    this->center = center;
    this->radius = radius;
//    glm:
    GLfloat vertex_buffer_data[600000];
    int idx=0,k;
    float a,b,c;
//    int n = 90;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=90;j++)
        {
            c=radius*cos(M_PI*j/180);
            a=radius*sin(M_PI*j/180)*cos(M_PI*i/180);
            b=radius*sin(M_PI*j/180)*sin(M_PI*i/180);
            vertex_buffer_data[idx++]=radius*sin(M_PI*j/180)*cos(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=radius*sin(M_PI*j/180)*sin(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=radius*cos(M_PI*j/180);
            vertex_buffer_data[idx++]=a;
            vertex_buffer_data[idx++]=b;
            vertex_buffer_data[idx++]=c;
            k=j+1;
            c=radius*cos(M_PI*k/180);
            a=radius*sin(M_PI*k/180)*cos(M_PI*i/180);
            b=radius*sin(M_PI*k/180)*sin(M_PI*i/180);
            vertex_buffer_data[idx++]=a;
            vertex_buffer_data[idx++]=b;
            vertex_buffer_data[idx++]=c;
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=90;j++)
        {
            c=radius*cos(M_PI*(j+1)/180);
            a=radius*sin(M_PI*(j+1)/180)*cos(M_PI*(i+1)/180);
            b=radius*sin(M_PI*(j+1)/180)*sin(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=radius*sin(M_PI*j/180)*cos(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=radius*sin(M_PI*j/180)*sin(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=radius*cos(M_PI*j/180);
            vertex_buffer_data[idx++]=a;
            vertex_buffer_data[idx++]=b;
            vertex_buffer_data[idx++]=c;
            k=j+1;
            c=radius*cos(M_PI*k/180);
            a=radius*sin(M_PI*k/180)*cos(M_PI*i/180);
            b=radius*sin(M_PI*k/180)*sin(M_PI*i/180);
            vertex_buffer_data[idx++]=a;
            vertex_buffer_data[idx++]=b;
            vertex_buffer_data[idx++]=c;
        }
    }

    this->object = create3DObject(GL_TRIANGLES, 91*(n+1)*3*2, vertex_buffer_data, color, GL_FILL);
    model_matrix = glm::mat4 (1.0f);
    model_matrix = glm::translate(this->center) * model_matrix;
}

void Hemisphere::draw(glm::mat4 VP) {
    glm::mat4 MVP = VP * model_matrix;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Hemisphere::rotate(float angle, glm::vec3 point, glm::vec3 axis) {
    glm::mat4 translate = glm::translate(-point-this->center);
    glm::mat4 rotate_mat = glm::rotate(glm::radians(angle), axis);
    glm::mat4 translate_inv = glm::translate(point+this->center);

    glm::mat4 total = translate_inv * rotate_mat * translate;
//    glm::mat4 translate_inv = glm::inverse(translate);
    model_matrix = total * model_matrix;
}

