//
// Created by sriteja on 10/2/19.
//

#ifndef JETSTRIKE_TWODPOLYGON_H
#define JETSTRIKE_TWODPOLYGON_H

#include "main.h"

class TwoDPolygon {
public:
    TwoDPolygon() {}
    TwoDPolygon(int num_of_sides, GLfloat *coordinates, glm::vec3 position, color_t color,
                    glm::vec3 scale_values = glm::vec3(1.0f), float rotation_angle = 0.0f,
                    glm::vec3 rotation_axis = glm::vec3(0.0f, 0.0f, 1.0f));
    int num_of_sides;
    color_t color;
    glm::vec3 position;
    glm::vec3 vertices[1000];
    float rotation;
    glm::vec3 rotation_axis;
    void construct(glm::vec3 vertices[]);
    void convertCoordinatesToVertices(GLfloat *coordinates, int n, glm::vec3 *vertices);
    void draw(glm::mat4 VP, bool reflect= false);
    glm::vec3 scale;
    void model(glm::vec3 axis = glm::vec3(1,0,0));
    void rotate(float angle, glm::vec3 point , glm::vec3 axis);
    void update_position(glm::vec3 change);
    void reflect(glm::vec3 axis);
    void rotate(glm::mat4 rotate_mat, glm::vec3 point = ORIGIN);
    glm::mat4 model_matrix;
private:
    glm::vec3 centroid;
    void copyVectorToArray(glm::vec3 vect, GLfloat *arr, int index);
    void findCentroid();
    void print_array(GLfloat *arr);
    GLfloat vertex_data[1000];
    VAO *object;

};


#endif //JETSTRIKE_TWODPOLYGON_H
