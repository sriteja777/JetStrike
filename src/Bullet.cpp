//
// Created by sriteja on 17/2/19.
//

#include "Bullet.h"


Bullet::Bullet(Jet jet) {
    this->axis = jet.jet_axis;
    glm::vec3 jet_front = jet.position +  (jet.jet_axis * jet.fuselage.length/2.0f);
    glm::vec3 right_pos = jet_front + jet.dis_lbl.x * jet.jet_per_axis;
    glm::vec3 left_pos = jet_front  - jet.dis_lbl.x * jet.jet_per_axis;
    float dist = glm::length(glm::vec3(jet.dis_lbl.x,jet.left_bullet_launcher.radius,jet.dis_lbl.z));

    auto z_pos = static_cast<float>(jet.position.z + jet.jet_axis.z * jet.fuselage.length / 2);
//    float left_z = z_pos - jet.jet_per_axis*jet.jet_axis;

    glm::vec3 bullet_1_position = {jet.position.x - jet.dis_lbl.x , jet.position.y - jet.left_bullet_launcher.radius, jet.position.z};
    glm::vec3 bullet_2_position = {jet.position.x - jet.dis_rbl.x , jet.position.y - jet.right_bullet_launcher.radius, jet.position.z};

//    glm::vec3 pos_1 = jet.left_bullet_launcher.position;
//    glm::vec3 pos_2 = jet.right_bullet_launcher.position;


    this->left_bullet = Line(left_pos, axis, 0.5, COLOR_CHOCOLATE);
    this->right_bullet = Line(right_pos, axis, 0.5, COLOR_CHOCOLATE);

}


void Bullet::draw(glm::mat4 VP) {
    this->left_bullet.draw(VP);
    this->right_bullet.draw(VP);

}

void Bullet::tick() {
    float speed = 0.4f;

    this->left_bullet.update_position(axis*speed);
    this->right_bullet.update_position(axis*speed);
}