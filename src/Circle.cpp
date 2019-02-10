#include "Circle.h"
#include "main.h"
#define PI 3.14159265


Circle::Circle(glm::vec3 center, float radius, color_t color, glm::vec3 rotation_axis, float initial_rotation_angle,
               float circle_angle) {
    this->center = center;
    this->rotation = initial_rotation_angle;
    this->rotation_axis = rotation_axis;
    speed = 0.01;
    this->radius = radius;
    int n=30;
    construct(n, circle_angle);
    this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_data, color, GL_FILL);
}


void Circle::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->center);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), rotation_axis);
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Circle::tick() {

}


void Circle:: construct(int n=15, float circle_angle) {

    float each_angle = (float)360/(float)n;
    // float side = 0.5;
    float val = static_cast<float>(PI / 180.0);
    // float cos_val = cos(each_angle*val);
    // float denom = sqrt(2*(1-cos_val));
    // float radius = side/denom;
    // printf("radis -> %f\n",radius );

    float start_angle = 0;
    float x_coor = 0;
    float y_coor = 0;

    int i=0;
    int j=0;
    while (start_angle < circle_angle)
    {
        if (j%3 == 0) {
            vertex_data[i++] = 0.0;
            vertex_data[i++] = 0.0;
            vertex_data[i++] = 0.0;
            if (j!=0) {
                vertex_data[i++] = x_coor;
                vertex_data[i++] = y_coor;
                vertex_data[i++] = 0.0;
                j++;
            }
            j++;
        }
        x_coor = radius*cos(start_angle*val);
        y_coor = radius*sin(start_angle*val);
        vertex_data[i++] = x_coor;
        vertex_data[i++] = y_coor;
        vertex_data[i++] = 0.0;

        j++;

        start_angle += each_angle;
//        printf("%f, %f\n",x_coor, y_coor );
    }
//    printf("i->%d\n",i );
    vertex_data[i++] = 0.0;
    vertex_data[i++] = 0.0;
    vertex_data[i++] = 0.0;
    vertex_data[i++] = x_coor;
    vertex_data[i++] = y_coor;
    vertex_data[i++] = 0.0;
    vertex_data[i++] = vertex_data[3];
    vertex_data[i++] = vertex_data[4];
    vertex_data[i++] = vertex_data[5];
//    print_array(n);
}



