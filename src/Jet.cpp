//
// Created by sriteja on 2/2/19.
//

#include "Jet.h"
#include "Camera.h"
#include "Compass.h"

extern Camera cam;
extern Compass compass;
extern float ocean_surface;
Jet::Jet(glm::vec3 position) {
    this->position = position;

    float fuselage_length = 1;
    float fuselage_radius = 0.25;
    float cockpit_length = 0.5;
    float tail_length = 0.5;
    float bullet_launcher_distance = 1;
    float bullet_laucher_radius = 0.05;
    float bullet_launcher_length = 0.2;

    this->altitude = (position.y - ocean_surface) * 10;
    this->fuel = 1000;
    printf("Altitude, fuel -> %f, %f", altitude, fuel);
//    exit(0);

    this->dis_lbl = glm::vec3(bullet_launcher_distance,bullet_laucher_radius,0.4);
    this->dis_rbl = glm::vec3(-bullet_launcher_distance,bullet_laucher_radius,0.4);

    jet_axis = glm::vec3(0, 0, -1);
    jet_per_axis = glm::vec3(1,0,0);


    GLfloat wing_coordinates[] = {
            0.0f, 0.0f, 0.0f,
            0.0f, -0.1f, 0.0f,
            -0.2f, -0.175f, 0.0f,
            -0.2f, -0.15f, 0.0f,
    };

    glm::vec3 scale_values = {0.25, 0.25, 0.25};

    this->fuselage = Cylinder(position, fuselage_length, fuselage_radius, COLOR_RUST);

    this->cockpit = Cone(glm::vec3(position.x, position.y, position.z - cockpit_length), cockpit_length, fuselage_radius, COLOR_RUST, 0, {0,0,1});
    this->tail = ObliqueCone(glm::vec3(position.x, position.y + fuselage_radius, position.z + fuselage_length + tail_length), position, tail_length, fuselage_radius, COLOR_RUST, 180, glm::vec3(0,1,0));

    this->left_wing = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x - fuselage_radius, position.y, position.z),
                                  COLOR_DARK_ORANGE, glm::vec3(6.0f, 4.0f, 0.0f), -90.0f, glm::vec3(1, 0, 0));
    this->right_wing = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x + fuselage_radius, position.y, position.z),
                                  COLOR_DARK_ORANGE, glm::vec3(6.0f, 4.0f, 0.0f), -90.0f, glm::vec3(1, 0, 0));
    right_wing.reflect(Y_AXIS);
    this->left_horizontal_stabiliser = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x, position.y+0.15, position.z + fuselage_length+0.1), COLOR_DARK_ORANGE, glm::vec3(3, 2, 1), -90, glm::vec3(1,0,0));
    this->right_horizontal_stabiliser = TwoDPolygon(4, wing_coordinates, glm::vec3(position.x, position.y+0.15, position.z + fuselage_length+0.1), COLOR_DARK_ORANGE, glm::vec3(3, 2, 1), -90, glm::vec3(1,0,0));
    right_horizontal_stabiliser.reflect(Y_AXIS);


    GLfloat ver_coordinates[] = {
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.1f,
            0.0f, 0.2f, 0.175f,
            0.0f, 0.2f, 0.15f,
    };



    this->vertical_stabiliser = TwoDPolygon(4, ver_coordinates, glm::vec3(position.x, position.y+fuselage_radius, position.z + fuselage_length+0.1), COLOR_DARK_ORANGE, glm::vec3(1, 3, 2), 2, glm::vec3(0,0,1));

    this->left_bullet_launcher = Cylinder(glm::vec3(position.x - bullet_launcher_distance, position.y - bullet_laucher_radius, position.z + dis_lbl.z),
                                          bullet_launcher_length, bullet_laucher_radius, COLOR_SADDLE_BROWN);

    this->right_bullet_launcher = Cylinder(glm::vec3(position.x + bullet_launcher_distance, position.y - bullet_laucher_radius, position.z + dis_lbl.z),
                                          bullet_launcher_length, bullet_laucher_radius, COLOR_SADDLE_BROWN);

    this->position = glm::vec3(position.x, position.y, position.z + fuselage_length/2);
    //    exit(0);

    barrel_rolling = false;
    barrel_radius = 2;
    barrel_angle = 0;

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
    this->left_bullet_launcher.draw(VP);
    this->right_bullet_launcher.draw(VP);
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
    this->left_bullet_launcher.update_position(diff);
    this->right_bullet_launcher.update_position(diff);

    fuel -= glm::length(diff)/1.5;
//    cam.eye.x += diff.x;
//    cam.eye.y += diff.y;
//    cam.eye.z += diff.z;
//    cam.target.x += diff.x;
//    cam.target.y += diff.y;
//    cam.target.z += diff.z;
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
    this->altitude += y*10;
    //    cam.eye.y -= y;
//    cam.target.y += y;
}
void Jet::update_position_z(float z) {
    glm::vec3 diff = glm::vec3(0,0,z);
    this->position.z += z;

    this->translate(diff);
}

void Jet::update_rotation(float rotate) {
//    this->body.rotation += rotate;
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
    this->left_bullet_launcher.rotate(angle, glm::vec3(dis_lbl.x, left_bullet_launcher.radius, fuselage.length/2-dis_lbl.z), axis);
    this->right_bullet_launcher.rotate(angle, glm::vec3(dis_rbl.x, dis_lbl.y, fuselage.length/2 - dis_rbl.z), axis);

    glm::mat4 rot = glm::rotate(glm::radians(angle), axis);
    if (DEBUG) print_mat4(rot);
    if (DEBUG) printf("\nbefore axis -> %f %f %f\n", jet_axis.x, jet_axis.y, jet_axis.z);
    jet_axis = glm::normalize(rot * glm::vec4 (jet_axis.x, jet_axis.y, jet_axis.z, 0));
    jet_per_axis = glm::normalize(rot * glm::vec4(jet_per_axis.x, jet_per_axis.y, jet_per_axis.z, 0));
    if (DEBUG) printf("\naxis -> %f %f %f\n", jet_axis.x, jet_axis.y, jet_axis.z);
//    exit(0);

    //Rotate Compass


}

void Jet::tick() {
//    update_position_z(-0.05f);
//    cam.eye.z -=0.05f;
//    cam.target.z -=0.05f;
    float s = 0.2f;
    if (DEBUG) printf("\naxis -> %f %f %f\n", jet_axis.x, jet_axis.y, jet_axis.z);

//    if (jet_axis.y < 0) {
//        exit(0);
//    }
    fuel -= 0.05;
    if (barrel_rolling) {
        barrel_roll();
    }
//    update_position_x(jet_axis.x*s);
//    update_position_y(jet_axis.y*s);
//    update_position_z(jet_axis.z*s);



}


void Jet::barrel_roll() {
    if (barrel_angle >= 360) {
        barrel_rolling = false;
        barrel_angle = 0;
        return;
    }
    this->update_position_x(barrel_radius * std::cos(glm::radians(barrel_angle)));
    this->update_position_y(barrel_radius * std::sin(glm::radians(barrel_angle)));
    roll(1, 5);
    barrel_angle += 5;

}




void Jet::roll(int sign, float angle) {
    angle *= -sign;
    glm::vec3 axis = jet_axis;
    this->rotate(angle, axis);

}

void Jet::pitch(int sign, float angle) {
    angle *= sign;
    glm::vec3 axis = jet_per_axis;
    this->rotate(angle, axis);
//    float speed = 0.05f;
//    this->update_position_y(sign*speed);

//    cam.eye.y += sign*speed;
//    cam.target.y += sign*speed;

}

void Jet::yaw(int sign, float angle) {
    angle *= sign;
    glm::vec3 axis = glm::cross(jet_per_axis, jet_axis);
    this->rotate(angle, axis);
    compass.rotate(angle);
}

void Jet::move_front() {
    float speed = 0.5f;
    update_position_x(jet_axis.x*speed);
    update_position_y(jet_axis.y*speed);
    update_position_z(jet_axis.z*speed);

}

void Jet::move_right() {

    yaw(-1, 0.5);
    roll(-1, 0.25);
}

void Jet::move_left() {
    yaw(1, 0.5);
    roll(1, 0.25);
}