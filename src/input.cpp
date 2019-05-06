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
#include "Bullet.h"
#include "Bomb.h"
#include "Canon.h"
#include "Parachute.h"
extern Jet player;
extern Camera cam;
extern std::vector<Bullet> bullets;
extern Canon enemy;
extern std::vector<Bomb> bombs;
extern std::vector<Parachute> parachute_enemies;
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
            case GLFW_KEY_F1:
                cam.change_view(plane);
                break;
            case GLFW_KEY_F2:
                cam.change_view(top);
                break;
            case GLFW_KEY_F3:
                cam.change_view(tower);
                break;
            case GLFW_KEY_F4:
                cam.change_view(follow);
                break;
            case GLFW_KEY_F5:
                cam.change_view(helicopter);
                break;
            case GLFW_KEY_M:
                enemy.shoot(player.position);
                break;
            case GLFW_KEY_P:
                parachute_enemies[0].shoot(player.position);
                break;
            case GLFW_KEY_B:
                player.barrel_rolling = true;
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
                bullets.emplace_back(Bullet(player));
                // Do something
            }
            break;
             case GLFW_MOUSE_BUTTON_RIGHT:
             if (action == GLFW_PRESS) {
                    bombs.emplace_back(Bomb(player));
             }
             break;
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
    if (DEBUG) printf("zoom angle -> %f\n",zoom_angle);
    reset_screen();
    // Do something
}

void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos) {
//    if (xpos > 1600 || xpos < -520) {
//        return;
//    }

//    printf("%f %f\n", xpos, ypos);

//    if ((xpos < 200 || xpos > 1000) && (ypos < 100 || ypos > 600)) {
//        if (xpos > 1000) {
//            cam.hel_rotation.x += 1;
//        }
//        if (xpos < 200) {
//            cam.hel_rotation.x -= 1;
//        }
//    }

//    double xoffset = xpos - old_x;
//    double yoffset = ypos - old_y;
//    player.update_position_x(static_cast<float>(xoffset/500));
//    player.update_position_y(static_cast<float>(-yoffset/500));
//    double rot = atan(xoffset/yoffset);
//    player.update_rotation(static_cast<float>(rot));
//    old_x = xpos;
//    old_y = ypos;
    if (DEBUG) printf("xpos -> %lf, ypos-> %lf\n",xpos, ypos);
}