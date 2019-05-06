//
// Created by sriteja on 10/2/19.
//

#include "Cylinder.h"

Cylinder::Cylinder(glm::vec3 position, float l,float r,color_t color, glm::vec3 scale)
{
    this->position = position;
    this->rotation = 0;
    this->length = l;
    this->radius = r;
    GLfloat vertex_buffer_data[14000];
    int idx=0;
    for(int i=0;i<=360;i++)
    {
        int j=i+1;
        vertex_buffer_data[idx++] = r*cos(M_PI*i/180);
        vertex_buffer_data[idx++] = r*sin(M_PI*i/180);
        vertex_buffer_data[idx++] = 0;
        vertex_buffer_data[idx++] = r*cos(M_PI*i/180);
        vertex_buffer_data[idx++] = r*sin(M_PI*i/180);
        vertex_buffer_data[idx++] = l;
        vertex_buffer_data[idx++] = r*cos(M_PI*j/180);;
        vertex_buffer_data[idx++] = r*sin(M_PI*j/180);;
        vertex_buffer_data[idx++] = 0;
        vertex_buffer_data[idx++] = r*cos(M_PI*j/180);
        vertex_buffer_data[idx++] = r*sin(M_PI*j/180);
        vertex_buffer_data[idx++] = 0;
        vertex_buffer_data[idx++] = r*cos(M_PI*i/180);
        vertex_buffer_data[idx++] = r*sin(M_PI*i/180);
        vertex_buffer_data[idx++] = l;
        vertex_buffer_data[idx++] = r*cos(M_PI*j/180);;
        vertex_buffer_data[idx++] = r*sin(M_PI*j/180);;
        vertex_buffer_data[idx++] = l;
    }
    this->object = create3DObject(GL_TRIANGLES, 360*3*2, vertex_buffer_data, color);

    model_matrix = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 orient    = glm::rotate((float) (this->orientation * M_PI / 180.0f), glm::vec3(1,0,0));
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,1,0));
    glm::mat4 scale_mat = glm::scale(scale);
    model_matrix *= (translate*rotate*scale_mat);

}
void Cylinder::draw(glm::mat4 VP) {
//    Matrices.model = glm::mat4(1.0f);
//    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
//    // glm::mat4 orient    = glm::rotate((float) (this->orientation * M_PI / 180.0f), glm::vec3(1,0,0));
//    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,1,0));
//    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
//    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
//    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * model_matrix;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // this->new_Barrel_end=Matrices.model*this->Barrel_end;
    // printf("%f %f %f\n",this->new_Barrel_end.x,this->new_Barrel_end.y,this->new_Barrel_end.z);
    draw3DObject(this->object);
}

void Cylinder::update_position(glm::vec3 change) {
    if (DEBUG) printf("start->%f\n",change.x);
    this->position += change;
    glm::mat4 translate = glm::translate (change);

    this->model_matrix = translate * this->model_matrix;

//    exit(0);
}

void Cylinder::rotate(float angle, glm::vec3  point, glm::vec3 axis) {
    glm::mat4 translate = glm::translate(-point-this->position);
    glm::mat4 rotate_mat = glm::rotate(glm::radians(angle), axis);
    glm::mat4 translate_inv = glm::translate(point+this->position);
    glm::mat4 total = translate_inv * rotate_mat * translate;

    model_matrix = total * model_matrix;
    glm::vec4 temp =  total * glm::vec4(position.x, position.y, position.z, 1);
    if (DEBUG) {
        printf("start\n%f %f %f %f\n", temp.x, temp.y, temp.z, temp.w);
        printf("start\n%f %f %f\n", position.x, position.y, position.z);
    }
    //    exit(0);

}

void Cylinder::rotate(glm::mat4 rotate_mat, glm::vec3 point) {
    glm::mat4 translate = glm::translate(-point-this->position);
//    glm::mat4 rotate_mat = glm::rotate(glm::radians(angle), axis);
    glm::mat4 translate_inv = glm::translate(point+this->position);

    glm::mat4 total = translate_inv * rotate_mat * translate;
//    glm::mat4 translate_inv = glm::inverse(translate);
    model_matrix = total * model_matrix;
}

//void