#ifndef MAIN_H
#define MAIN_H

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

#define X_AXIS glm::vec3(1,0,0)
#define Y_AXIS glm::vec3(0,1,0)
#define Z_AXIS glm::vec3(0,0,1)
#define ORIGIN glm::vec3(0,0,0)
#define DEBUG  false



struct color_t {
    int r;
    int g;
    int b;
};

// nonedit.cpp
GLFWwindow *initGLFW(int width, int height);
GLuint     LoadShaders(const char *vertex_file_path, const char *fragment_file_path);
struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, const GLfloat *color_buffer_data, GLenum fill_mode = GL_FILL);
struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode = GL_FILL);
struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, const color_t color, GLenum fill_mode = GL_FILL);
void       draw3DObject(struct VAO *vao);
void get_resolution(int* width, int*height);



// input.cpp
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods);
void keyboardChar(GLFWwindow *window, unsigned int key);
void mouseButton(GLFWwindow *window, int button, int action, int mods);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos);

// other_handlers.cpp
void error_callback(int error, const char *description);
void quit(GLFWwindow *window);
void reshapeWindow(GLFWwindow *window, int width, int height);

// utility.cpp
void print_mat4(glm::mat4 matrix);

// Types
struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int    NumVertices;
};
typedef struct VAO VAO;

struct GLMatrices {
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
    GLuint    MatrixID;
};

extern GLMatrices Matrices;



// ---- Logic ----

enum direction_t { DIR_UP, DIR_RIGHT, DIR_DOWN, DIR_LEFT };
enum view {plane = 200, top=1000, tower=2000, follow=150, helicopter=250};

struct bounding_box_t {
    float x;
    float y;
    float width;
    float height;
};

bool detect_collision(bounding_box_t a, bounding_box_t b);

extern float screen_zoom, screen_center_x, screen_center_y, zoom_angle;
void reset_screen();

// ---- Colors ----
extern const color_t COLOR_RED;
extern const color_t COLOR_GREEN;
extern const color_t COLOR_BLUE;
extern const color_t COLOR_BLACK;
extern const color_t COLOR_BACKGROUND;
extern const color_t COLOR_DARK_TURQUOISE;
extern const color_t COLOR_SADDLE_BROWN;
extern const color_t COLOR_GOLD;
extern const color_t COLOR_DIAMOND;
extern const color_t COLOR_CHOCOLATE;
extern const color_t COLOR_CRIMSON;
extern const color_t COLOR_PERU;
extern const color_t COLOR_NAVAJO_WHITE;
extern const color_t COLOR_SKIN;
extern const color_t COLOR_NAVY;
extern const color_t COLOR_MAROON;
extern const color_t COLOR_DARK_ORANGE;
extern const color_t COLOR_ORANGE_RED;
extern const color_t COLOR_SKY_BLUE;
extern const color_t COLOR_SILVER;
extern const color_t COLOR_ORCHID;
extern const color_t COLOR_RUST;
extern const color_t COLOR_YELLOW;
extern const color_t COLOR_LIME;
extern const color_t COLOR_WHITE;
extern const color_t COLOR_MAGNETA;
extern const color_t COLOR_THISTLE;
extern const color_t COLOR_SANDY_BROWN;
extern const color_t COLOR_DEEP_PINK;
extern const color_t COLOR_DIM_GREY;
extern const color_t COLOR_GAINSBORO;
#endif
