#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "main.h"
#include "Jet.h"
#include "Camera.h"
extern Jet player;
extern Camera cam;
double old_x = 1024/2;
double old_y = 768/2;

bool   cannon_keyboard_input = true;
bool   drag_pan = false, old_cki;
double drag_oldx = -1, drag_oldy = -1;
float rotation_val =0;

using namespace std;

/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods) {
    // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE) {
        // switch (key) {
        // case GLFW_KEY_C:
        // rectangle_rot_status = !rectangle_rot_status;
        // break;
        // case GLFW_KEY_P:
        // triangle_rot_status = !triangle_rot_status;
        // break;
        // case GLFW_KEY_X:
        //// do something ..
        // break;
        // default:
        // break;
        // }
    } else if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                quit(window);
                break;
            case GLFW_KEY_V:
//                cam.eye.y = 54;
//                cam.eye.z = -2;
                    cam.eye.x = 10.0f;
                    cam.eye.z  = -7.0f;
                    cam.eye.y = 40;
//                cam.eye.z -=0.5 * std::sin(glm::radians(rotation_val));
//                cam.eye.x += 0.5 * std::cos(glm::radians(rotation_val));
//                rotation_val += 10;
                break;
            case GLFW_KEY_D:
                player.roll(+1);
                break;
            default:
                break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar(GLFWwindow *window, unsigned int key) {
    switch (key) {
        case 'Q':
        case 'q':
//            quit(window);
//            break;
        default:
            break;
    }
}

/* Executed when a mouse button is pressed/released */
void mouseButton(GLFWwindow *window, int button, int action, int mods) {
    switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            if (action == GLFW_PRESS) {
                // Do something
                return;
            } else if (action == GLFW_RELEASE) {
                // Do something
            }
            break;
            // case GLFW_MOUSE_BUTTON_RIGHT:
            // if (action == GLFW_RELEASE) {
            // rectangle_rot_dir *= -1;
            // }
            // break;
        default:
            break;
    }
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    if (yoffset < 0)  {
        zoom_angle -= 1;
    }
    else if (yoffset > 0) {
        zoom_angle += 1;
    }
    printf("zoom angle -> %f\n",zoom_angle);
    reset_screen();
    // Do something
}

void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos) {
//    if (xpos > 1600 || xpos < -520) {
//        return;
//    }
    double xoffset = xpos - old_x;
    double yoffset = ypos - old_y;
    player.update_position_x(static_cast<float>(xoffset/500));
    player.update_position_y(static_cast<float>(-yoffset/500));
//    double rot = atan(xoffset/yoffset);
//    player.update_rotation(static_cast<float>(rot));
    old_x = xpos;
    old_y = ypos;
    printf("xpos -> %lf, ypos-> %lf\n",xpos, ypos);
}