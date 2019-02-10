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
//    GLfloat wing_coordinates[] = {
//            0.4f, 0.1f, 0.0f,
//            -0.4f, 0.1f, 0.0f,
//            -0.4f, -0.1f, 0.0f,
//            0.4f, -0.1f, 0.0f,
//    };

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

    this->left_horizontal_stabiliser = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x, position.y+0.15, position.z + fuselage_length+0.1), COLOR_DARK_ORANGE, glm::vec3(3, 2, 1), -90, glm::vec3(1,0,0));
    this->right_horizontal_stabiliser = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x, position.y+0.15, position.z + fuselage_length+0.1), COLOR_DARK_ORANGE, glm::vec3(3, 2, 1), -90, glm::vec3(1,0,0));

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

void Jet::update_position_x(float x) {

    this->position.x += x;
    this->fuselage.position.x +=x;
    this->cockpit.position.x += x;
    this->left_wing.position.x += x;
    this->right_wing.position.x += x;
    this->tail.position.x += x;
    this->left_horizontal_stabiliser.position.x += x;
    this->right_horizontal_stabiliser.position.x += x;
    this->vertical_stabiliser.position.x += x;
//    cam.eye.x += x;
//    cam.target.x +=x;
}

void Jet::update_position_y(float y) {

    this->position.y += y;
    this->fuselage.position.y +=y;
    this->cockpit.position.y += y;
    this->left_wing.position.y += y;
    this->right_wing.position.y += y;
    this->tail.position.y += y;
    this->left_horizontal_stabiliser.position.y += y;
    this->right_horizontal_stabiliser.position.y += y;
    this->vertical_stabiliser.position.y += y;
    //    cam.eye.y -= y;
//    cam.target.y += y;
}
void Jet::update_position_z(float z) {

    this->position.z += z;
    this->fuselage.position.z +=z;
    this->cockpit.position.z += z;
    this->left_wing.position.z += z;
    this->right_wing.position.z += z;
    this->tail.position.z += z;
    this->left_horizontal_stabiliser.position.z += z;
    this->right_horizontal_stabiliser.position.z += z;
    this->vertical_stabiliser.position.z += z;
}

void Jet::update_rotation(float rotate) {
//    this->body.rotation += rotate;
}

void Jet::roll() {

}

void Jet::move_left() {
//    this.bod34
}

void Jet::tick() {
//    update_position_z(-0.05f);
//    cam.eye.z -=0.05f;
//    cam.target.z -=0.05f;
}