//
// Created by sriteja on 2/2/19.
//

#ifndef JETSTRIKE_CAMERA_H
#define JETSTRIKE_CAMERA_H

#include "main.h"
class Camera {
public:
    Camera() {}
    Camera(view cam_view);
    glm::vec3 eye;
    glm::vec3 target;
    glm::vec3 up;
    view cam_view;
    glm::vec3 hel_rotation;
    float hel_radius;
    void tick();
    void change_view(view cam_view);
    void set_view(view cam_view);


};


#endif //JETSTRIKE_CAMERA_H
