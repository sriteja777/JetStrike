#include "main.h"
#include "timer.h"
#include "Circle.h"
#include "Cuboid.h"
#include "Camera.h"
#include "Jet.h"
#include "Sphere.h"


using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;


/**************************
* Customizable functions *
**************************/

Circle ball1;
Cuboid ocean;
Camera cam;
Cuboid temp_cube;
Jet player;
Sphere sphere;


float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0, zoom_angle = 120.0f;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);


/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
//    glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );

    // Target - Where is the camera looking at.  Don't change unless you are sure!!
//    glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
//    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( cam.eye, cam.target, cam.up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
//    ball1.draw(VP);
    ocean.draw(VP);
    player.draw(VP);
//    sphere.draw(VP);
//    temp_cube.draw(VP);

}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up    = glfwGetKey(window, GLFW_KEY_UP);
    int down  = glfwGetKey(window, GLFW_KEY_DOWN);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int a = glfwGetKey(window, GLFW_KEY_A);
    int q = glfwGetKey(window, GLFW_KEY_Q);
    int e = glfwGetKey(window, GLFW_KEY_E);
    int z = glfwGetKey(window, GLFW_KEY_Z);
    int x = glfwGetKey(window, GLFW_KEY_X);
    if (left) {
        player.update_position_x(-0.05f);
        // Do something
    }
    if (right) {
        player.update_position_x(+0.05f);
        // Do something
    }
    if (up) {
        player.update_position_y(+0.05f);
    }
    if (down) {
        player.update_position_y(-0.05f);
    }
    if (d) player.roll(-1);
    if (a) player.roll(1);
    if (x) player.pitch(-1);
    if (z) player.pitch(1);
    if (q) player.yaw(1);
    if (e) player.yaw(-1);


}





void tick_elements() {
    ball1.tick();
    player.tick();
//    camera_rotation_angle += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    cam = Camera(glm::vec3(0.0f, 50.0f, 5.0f), glm::vec3(0, 50, 0), glm::vec3(0,1,0));
//    ball1 = Circle(glm::vec3(0.0f, 50.0f, -10.0f), 10.0f, COLOR_RED, glm::vec3(1,0,0));
    ocean = Cuboid(glm::vec3(0.0f, -5.0f, 0.0f), 2000.f, 8.f, 1000.f, COLOR_BLUE);
    player = Jet(glm::vec3(0.0f, 49.0f, 2.0f));
    sphere = Sphere(glm::vec3(), 5);
//    sphere = Sphere(1);
//    temp_cube = Cuboid(glm::vec3, )
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_SKY_BLUE.r / 256.0, COLOR_SKY_BLUE.g / 256.0, COLOR_SKY_BLUE.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = -1;
    int height = -1;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();

            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
//    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
//    glm::mat4 projectionMatrix = glm::perspective(
//            45, // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
//            static_cast<int>(4.0f / 3.0f),       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
//            0.1f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
//            100.0f             // Far clipping plane. Keep as little as possible.
//    );
    Matrices.projection = glm::perspective(glm::radians(zoom_angle), 4.0f / 3.0f, 0.1f, 100.0f);
//    glm::perspective
}
