//
// Created by sriteja on 2/2/19.
//

#include "Camera.h"
#include "Jet.h"

extern Jet player;

Camera::Camera(glm::vec3 eye, glm::vec3 target, glm::vec3 up) {
    this->eye = eye;
    this->target = target;
    this->up = up;
}

void Camera::tick() {
    float mod = std::sqrt(player.jet_axis.x * player.jet_axis.x + player.jet_axis.z * player.jet_axis.z);
    float total = std::sqrt(mod*mod + player.jet_axis.y*player.jet_axis.y);
    printf("\ncam -> %f %f %f\n",player.jet_axis.x, player.jet_axis.y,  player.jet_axis.z);
    glm::vec3 temp(player.position.x - 2*player.jet_axis.x/mod,
              player.position.y + 1.5f,
              player.position.z - 2*player.jet_axis.z/mod
              );
    printf("\ntemp %f %f %f\n",temp.x ,temp.y, temp.z);
    printf("\neye %f %f %f",player.position.x, player.position.y, player.position.z + 2);
    target = player.position;

//    eye = glm::vec3(player.position.x, player.position.y, player.position.z + 2);
    eye = temp;
//    up = glm::vec3(player.jet_axis.x, 1, -player.jet_axis.z);
}