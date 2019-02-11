//
// Created by sriteja on 2/2/19.
//

#ifndef JETSTRIKE_JET_H
#define JETSTRIKE_JET_H

#include "main.h"
#include "Cuboid.h"
#include "Cylinder.h"
#include "Cone.h"
#include "TwoDPolygon.h"
#include "ObliqueCone.h"
class Jet {
public:
    Jet() {}
    Jet(glm::vec3 position);
    void draw(glm::mat4 VP);
    glm::vec3 position;

    Cylinder fuselage;
    Cone cockpit;
    ObliqueCone tail;
    TwoDPolygon left_wing;
    TwoDPolygon left_horizontal_stabiliser;
    TwoDPolygon right_horizontal_stabiliser;
    TwoDPolygon vertical_stabiliser;
    TwoDPolygon right_wing;

    // Displacements

//    glm::vec3 dis_cockpit;
//    glm::vec3 dis_fuselage;
//    glm::vec3 dis_left_wing;
//    glm::vec3 dis_right_wing;
//    glm::vec3 dis_left_horizontal_stab;
//    glm::vec3 dis_right_horizontal_stab;
//    glm::vec3 dis_vertical_stab;
//    glm::vec3 dis_tail;
    void update_position_x(float x);
    void update_position_y(float y);
    void update_position_z(float z);
    void update_rotation(float rotate);
    void move_left();
    void yaw(int sign);
    void roll(int sign);
    void pitch(int sign);
    void tick();
    void rotate(float angle, glm::vec3 axis);
    void translate(glm::vec3 diff);
};


#endif //JETSTRIKE_JET_H
