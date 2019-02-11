//
// Created by sriteja on 2/2/19.
//

#include "Jet.h"
#include "Camera.h"

extern Camera cam;
Jet::Jet(glm::vec3 position) {
    this->position = position;

    float fuselage_length = 1;
    float fuselage_radius = 0.25;
    float cockpit_length = 0.5;
    float tail_length = 0.5;


    GLfloat wing_coordinates[] = {
            0.0f, 0.0f, 0.0f,
            0.0f, -0.1f, 0.0f,
            -0.2f, -0.175f, 0.0f,
            -0.2f, -0.15f, 0.0f,
    };



    this->fuselage = Cylinder(position.x, position.y, position.z, fuselage_length, fuselage_radius, COLOR_RUST);

    this->cockpit = Cone(glm::vec3(position.x, position.y, position.z - cockpit_length), cockpit_length, fuselage_radius, COLOR_RUST, 0);
    this->tail = ObliqueCone(glm::vec3(position.x, position.y + fuselage_radius, position.z + fuselage_length + tail_length), position, tail_length, fuselage_radius, COLOR_RUST, 180, glm::vec3(0,1,0));

    this->left_wing = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x - fuselage_radius, position.y, position.z),
                                  COLOR_DARK_ORANGE, glm::vec3(6.0f, 4.0f, 0.0f), -90.0f, glm::vec3(1, 0, 0));
    this->right_wing = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x + fuselage_radius, position.y, position.z),
                                  COLOR_DARK_ORANGE, glm::vec3(6.0f, 4.0f, 0.0f), -90.0f, glm::vec3(1, 0, 0));
    right_wing.reflect(glm::vec3());
    this->left_horizontal_stabiliser = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x, position.y+0.15, position.z + fuselage_length+0.1), COLOR_DARK_ORANGE, glm::vec3(3, 2, 1), -90, glm::vec3(1,0,0));
    this->right_horizontal_stabiliser = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x, position.y+0.15, position.z + fuselage_length+0.1), COLOR_DARK_ORANGE, glm::vec3(3, 2, 1), -90, glm::vec3(1,0,0));
    right_horizontal_stabiliser.reflect(glm::vec3());
    GLfloat ver_coordinates[] = {
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.1f,
            0.0f, 0.2f, 0.175f,
            0.0f, 0.2f, 0.15f,
    };



    this->vertical_stabiliser = TwoDPolygon(4, ver_coordinates, glm::vec3(position.x, position.y+fuselage_radius, position.z + fuselage_length+0.1), COLOR_DARK_ORANGE, glm::vec3(1, 3, 2), 2, glm::vec3(0,0,1));
//    exit(0);
}

void Jet::draw(glm::mat4 VP) {

    this->fuselage.draw(VP);
    this->cockpit.draw(VP);
    this->left_wing.draw(VP);
    this->right_wing.draw(VP, true);
    this->left_horizontal_stabiliser.draw(VP);
    this->right_horizontal_stabiliser.draw(VP, true);
    this->tail.draw(VP);
    this->vertical_stabiliser.draw(VP);
}

void Jet::translate(glm::vec3 diff) {
    this->fuselage.update_position(diff);
    this->cockpit.update_position(diff);
    this->left_wing.update_position(diff);
    this->right_wing.update_position(diff);
    this->tail.update_position(diff);
    this->left_horizontal_stabiliser.update_position(diff);
    this->right_horizontal_stabiliser.update_position(diff);
    this->vertical_stabiliser.update_position(diff);
}

void Jet::update_position_x(float x) {
    glm::vec3 diff = glm::vec3(x,0,0);
    this->position.x += x;
    this->translate(diff);

//    cam.eye.x += x;
//    cam.target.x +=x;
}

void Jet::update_position_y(float y) {
    glm::vec3 diff = glm::vec3(0,y,0);
    this->position.y += y;
    this->translate(diff);
    //    cam.eye.y -= y;
//    cam.target.y += y;
}
void Jet::update_position_z(float z) {
    glm::vec3 diff = glm::vec3(0,z,0);
    this->position.z += z;
    this->translate(diff);
}

void Jet::update_rotation(float rotate) {
//    this->body.rotation += rotate;
}



void Jet::move_left() {

}


void Jet::rotate(float angle, glm::vec3 axis) {
    this->cockpit.rotate(angle, glm::vec3(0, 0, cockpit.length + fuselage.length/2), axis);
    this->fuselage.rotate(angle, glm::vec3(0,0,fuselage.length/2), axis);
    this->left_wing.rotate(angle, glm::vec3(fuselage.radius, 0, fuselage.length/2), axis);
    this->right_wing.rotate(angle, glm::vec3(-fuselage.radius, 0, fuselage.length/2), axis);
    this->left_horizontal_stabiliser.rotate(angle, glm::vec3(0, -0.15, -fuselage.length/2-0.1), axis);
    this->right_horizontal_stabiliser.rotate(angle, glm::vec3(0, -0.15, -fuselage.length/2-0.1), axis);
    this->vertical_stabiliser.rotate(angle, glm::vec3(0, -fuselage.radius, -fuselage.length/2-0.1), axis);
    this->tail.rotate(angle, glm::vec3(0, -fuselage.radius, -tail.length - fuselage.length/2)  ,axis);

}

void Jet::tick() {
//    update_position_z(-0.05f);
//    cam.eye.z -=0.05f;
//    cam.target.z -=0.05f;
}

void Jet::roll(int sign) {
    float angle = sign*0.5f;
    glm::vec3 axis (0,0,1);
    this->rotate(angle, axis);

}

void Jet::pitch(int sign) {
    float angle = sign*0.5f;
    glm::vec3 axis (1,0,0);
    this->rotate(angle, axis);

}

void Jet::yaw(int sign) {
    float angle = sign*0.5f;
    glm::vec3 axis(0,1,0);
    this->rotate(angle, axis);
}