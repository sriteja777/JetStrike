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
    glm::vec3 rotation;
    Cylinder fuselage;
    Cone cockpit;
    ObliqueCone tail;
    TwoDPolygon left_wing;
    TwoDPolygon left_horizontal_stabiliser;
    TwoDPolygon right_horizontal_stabiliser;
    TwoDPolygon vertical_stabiliser;
    TwoDPolygon right_wing;
    Cylinder left_bullet_launcher;
    Cylinder right_bullet_launcher;

    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 jet_axis;
    glm::vec3 jet_per_axis;

    float altitude;
    float fuel;

    void update_position_x(float x);
    void update_position_y(float y);
    void update_position_z(float z);
    void update_rotation(float rotate);
    void move_left();
    void move_front();
    void move_right();
    void yaw(int sign, float angle=2.f);
    void roll(int sign, float angle=2.f);
    void pitch(int sign, float angle=2.f);
    void tick();
    void rotate(float angle, glm::vec3 axis);
    void translate(glm::vec3 diff);

    // Displacements

    //    glm::vec3 dis_cockpit;
    //    glm::vec3 dis_fuselage;
    //    glm::vec3 dis_left_wing;
    //    glm::vec3 dis_right_wing;
    //    glm::vec3 dis_left_horizontal_stab;
    //    glm::vec3 dis_right_horizontal_stab;
    //    glm::vec3 dis_vertical_stab;
    //    glm::vec3 dis_tail;
    glm::vec3 dis_lbl;
    glm::vec3 dis_rbl;


    bool barrel_rolling;
    float barrel_angle;
    float barrel_radius;
    void barrel_roll();
};


#endif //JETSTRIKE_JET_H
