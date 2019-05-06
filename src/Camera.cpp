//
// Created by sriteja on 2/2/19.
//

#include "Camera.h"
#include "Jet.h"

extern Jet player;
extern glm::vec3 player_start;
Camera::Camera(view cam_view) {
    hel_radius = 5;
    hel_rotation = glm::vec3(90, 60, 45);
    set_view(cam_view);
//    this->cam_view = cam_view;
//    if (this->cam_view == follow) {
//        this->eye = glm::vec3(0.0f, 50.0f, 5.0f);
//        this->target = glm::vec3(0, 50, 0);
//        this->up = glm::vec3(0, 1, 0);
//    }
//    else if (this->cam_view == top) {
//        printf("came");
////        exit(0);
//        this->eye = {player.position.x, player.position.y+50, player.position.z+10};
//        this->target = player.position;
//        this->up = glm::vec3 (0, 0, -1);
//    }
//    else if (this->cam_view == plane) {
//        this->eye = glm::vec3(player.position.x, player.position.y, player.position.z-player.fuselage.radius - player.cockpit.length);
//        this->target  = player.position + 10.0f*player.jet_axis;
//        this->up = {0,1,0};
//    }

}

void Camera::tick() {

        float mod = std::sqrt(player.jet_axis.x * player.jet_axis.x + player.jet_axis.z * player.jet_axis.z);
        float total = std::sqrt(mod * mod + player.jet_axis.y * player.jet_axis.y);
        if (DEBUG) {
            printf("\ncam -> %f %f %f\n", player.jet_axis.x, player.jet_axis.y, player.jet_axis.z);
            printf("\nmod -> %f\n val %f", mod, player.jet_axis.z / mod);
        }
        glm::vec3 temp(player.position.x - 10 * player.jet_axis.x / mod,
                       player.position.y + 3.0f,
                       player.position.z - 10 * player.jet_axis.z / mod
        );

        if (DEBUG) {
            printf("\ntemp %f %f %f\n", temp.x, temp.y, temp.z);
            printf("\neye %f %f %f", player.position.x, player.position.y, player.position.z + 2);
        }
        target = player.position;
    if (cam_view == follow) {

//        eye = glm::vec3(player.position.x, player.position.y + 1.5, player.position.z + 5);
        eye = temp;
        up = {0,1,0};
//    up = glm::vec3(player.jet_axis.y, 1, player.jet_axis.z);
//    up = glm::vec3 (0, player.jet_axis.y + 1, 0);
    }
    else if (cam_view == top) {
        set_view(cam_view);
//        this->eye = {player.position.x, player.position.y+50, player.position.z};
//        this->target = player.position;
//        this->up = {0,0,-1};
    }
    else if (cam_view == plane) {
        set_view(cam_view);
    }
    else if (cam_view == helicopter) {
        set_view(cam_view);
    }
}

void Camera::change_view(view cam_view) {
    set_view(cam_view);
    reset_screen();
}

void Camera::set_view(view cam_view) {
    this->cam_view = cam_view;
    if (cam_view == follow) {
        this->eye = {player.position.x, player.position.y, player.position.z + 10};
        this->target = player.position;
        this->up = glm::vec3 (0, 1,0);
    }
    else if (cam_view == plane) {
//        this->eye = glm::vec3(player.position.x, player.position.y, player.position.z-player.fuselage.radius - player.cockpit.length-0.5);
        this->eye = player.position + player.jet_axis * (player.fuselage.radius + player.cockpit.length+0.5f);
        this->target  = player.position + 10.0f*player.jet_axis;
        this->up = {0,1,0};
    }
    else if (cam_view == top) {
        this->eye = {player.position.x, player.position.y+50, player.position.z};
        this->target = player.position;
        this->up = {0,0,-1};
    }
    else if (cam_view == tower) {
        this->eye = player_start + glm::vec3(20, 300, -100);
        this->target = player.position;
        this->up = {0, 1, 0};
    }
    else if (cam_view == helicopter) {
        float alpha = glm::radians(hel_rotation.x);
        float theta = glm::radians(hel_rotation.y);
//        glm::vec3 rota = glm::vec3 (10 *std::cos(glm::radians(hel_rotation.y)), 0, 10*sin(glm::radians(hel_rotation.y)));
//        glm::vec3 rota2 = glm::vec3(5*std::cos(glm::radians(hel_rotation.z)), 5*sin(glm::radians(hel_rotation.z)), 0);

//        glm::vec3 rot = 7.0f * glm::vec3 (std::cos(glm::radians(hel_rotation.x)),
//                                       std::cos(glm::radians(hel_rotation.y)),
//                                       std::cos(glm::radians(hel_rotation.z)));
        float r = 7*std::sin(theta);
        glm::vec3 pos (0, 7*cos(theta), 0);
//        printf("hel_rot %f\n",theta);
        glm::vec3 ro (r*std::cos(alpha), 0, r*std::sin(alpha));
        this->eye = player.position + pos + ro;
        this->target = player.position;
        this->up = {0, 1, 0};
//        this->up = glm::vec3 (sin(glm::radians(hel_rotation.x)), sin(hel_rotation), cos(glm::radians(hel_rotation.x)));
        glm::vec3 temp = glm::vec3 (std::cos(theta)*std::cos(alpha),std::sin(theta),-std::cos(theta)*std::sin(alpha));
//        if (temp.x == (float)0) {
//            printf("zero");
//            exit(0);
//        }

//        if (temp.x >= 0.0f) {
//            if (fabs(temp.x) < 0.00001 ) up.x = 0;
//            else up.x = 1;
//        }
//        else {
//            up.x  = -1;
//        }
//        if (temp.y>=0) {
//            if (fabs(temp.y) < 0.00001) up.y = 0;
//            else up.y = 1;
//        }
//        else {
//            up.y  = -1;
//        }
//        if (temp.z>=0) {
//            if (fabs(temp.z) < 0.00001 ) up.z = 0;
//            else up.z = 1;
//        }
//        else {
//            up.z  = -1;
//        }
//        up = temp;
//        printf("up %f %f %f ",up.x, up.y, up.z);
//        printf("temp %f %f %f ",temp.x, temp.y, temp.z);
//        exit(0);
//        glm::rotate = glm::rotate()
    }
}