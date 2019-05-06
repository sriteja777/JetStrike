#include "main.h"
#include "timer.h"
#include "Circle.h"
#include "Cuboid.h"
#include "Camera.h"
#include "Jet.h"
#include "Sphere.h"
#include "Mountain.h"
#include "Ring.h"
#include "Arrow.h"
#include "Line.h"
#include "Bullet.h"
#include "VariableRectangle.h"
#include "PetrolPump.h"
#include "Alphabet.h"
#include "Indicator.h"
#include "Compass.h"
#include "Bomb.h"
#include "Canon.h"
#include "Island.h"
#include "Parachute.h"
#include "Missile.h"


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
vector <Mountain> mountains;
vector <ObliqueCone> oblique_mountains;
vector <Ring> rings;
vector <Arrow> direction_arrows;
vector <Line> lines;
vector <Bullet> bullets;
Compass compass;
vector <Bomb> bombs;
Canon enemy;
vector<Island> islands;
vector <Parachute> parachute_enemies;
vector <Missile> missiles;
//VariableRectangle fuel_indicator;

PetrolPump pump;
Indicator altitude_indicator;
Indicator fuel_indicator;

glm::mat4 fuel_projection(1.0f);
glm::mat4 altitude_projection(1.0f);
glm::mat4 compass_projection;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0, zoom_angle = 45.0f;
float ocean_surface;
int window_width, window_height;
float far = 150;
glm::vec3 player_start = glm::vec3(0, -40, 2);

Timer t60(1.0 / 60);


/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    Matrices.view = glm::lookAt( cam.eye, cam.target, cam.up ); // Rotating Camera for 3D
//    Matrices.
    glm::mat4 view = glm::lookAt({0,0,4}, glm::vec3(), {0,1,0});

    glm::mat4 VP = Matrices.projection * Matrices.view;
    glm::mat4 vp2 = fuel_projection * view;
    glm::mat4 vp3 = altitude_projection * view;
    glm::mat4 vp_compass = compass_projection * view;
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
//    ball1.draw(VP);
//    printf("%d %d", window_width, window_height);
//    exit(0);
    glViewport (0, 100, 50, 700);
    altitude_indicator.draw(vp3, 1, player.altitude/1000);

//    glViewport((GLint)window_width - 50, (GLint)100, (GLsizei )window_width, (GLsizei )700 );
    glViewport(870, 100, 920, 700 );
    fuel_indicator.draw(vp2, 1, player.fuel/1000);

//    glViewport(850, 300, 920, 800 );
    glViewport(850, 450, 900, 470 );
    compass.draw(vp_compass);
//
    glViewport (0, 0, (GLsizei) window_width, (GLsizei) window_height);
//    player.draw(vp2);
//    sphere.draw(VP);
    ocean.draw(VP);
    player.draw(VP);
    pump.draw(VP);
    for (auto &mountain : mountains) {
        mountain.draw(VP);
    }
    for (auto &ring: rings) {
        float diff;
        diff = ring.position.z - player.position.z;
        if (diff < 120 && diff > -120)
            ring.draw(VP);
    }
    for (auto &arrow : direction_arrows) {
        arrow.draw(VP);
    }

    for (auto &line: lines) {
        line.draw(VP);
    }

    for (auto &bullet : bullets) {
        bullet.draw(VP);
    }

    for (auto &bomb : bombs) {
        bomb.draw(VP);
    }

    for (auto &island : islands) {
        island.draw(VP);
    }

    for (auto &parachute : parachute_enemies) {
        parachute.draw(VP);
    }

//    for (auto &missile : missiles) {
//        missile.draw(VP);
//    }

    enemy.draw(VP);

//    oblique_mountains[0].draw(VP);
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
    int w = glfwGetKey(window, GLFW_KEY_W);
    int l = glfwGetKey(window, GLFW_KEY_L);
    int j = glfwGetKey(window, GLFW_KEY_J);
    int i = glfwGetKey(window, GLFW_KEY_I);
    int k = glfwGetKey(window, GLFW_KEY_K);
//    int m = glfwGetKey(window, GLFW_KEY_M);
    int eight = glfwGetKey(window, GLFW_KEY_KP_8);
    int four = glfwGetKey(window, GLFW_KEY_KP_4);
    int six = glfwGetKey(window, GLFW_KEY_KP_6);
    int five = glfwGetKey(window, GLFW_KEY_KP_5);
    int two = glfwGetKey(window, GLFW_KEY_KP_2);
    if (four) {
        player.update_position_x(-0.05f);
        // Do something
    }
    if (six) {
        player.update_position_x(+0.05f);
    }
    if (eight) {
        player.update_position_y(+0.5f);
    }
    if (five) {
        player.update_position_y(-0.5f);
    }
    if (two) {
        player.update_position_z(0.5);
    }
    if (up) {
        player.move_front();
    }
    if (l) {
        cam.hel_rotation.x -= 1;
    }
    if (j) {
        cam.hel_rotation.x += 1;
    }
    if (i) {
        cam.hel_rotation.y += 1;
    }
    if (k) {
        cam.hel_rotation.y -= 1;
    }
//    if (m) {
//        enemy.shoot(player.position);
//    }

    if (left) {
        player.move_left();
    }
    if (right) {
        player.move_right();
    }

    if (d) player.roll(-1);
    if (a) player.roll(1);
    if (x) player.pitch(-1);
    if (z) player.pitch(1);
    if (q) player.yaw(1);
    if (e) player.yaw(-1);
    if (w) player.move_front();

}


void tick_elements() {
    ball1.tick();
    player.tick();
    cam.tick();

    for (auto &arrow : direction_arrows) {
        arrow.tick();
    }

    for (auto &bullet : bullets) {
        bullet.tick();
    }
    vector<Bomb>::iterator bomb;
    for (bomb = bombs.begin(); bomb < bombs.end(); bomb++) {
        (*bomb).tick();
        if ((*bomb).position.y < ocean_surface) {
            bombs.erase(bomb);

        }
    }


//    if (rand()%143 == 4) {
//        if (glm::distance(enemy.position, player.position) < 100)
//            enemy.shoot(player.position);
//
//    }

//    for (auto &island : islands) {
//        if (glm::d)
//        island.tick(player.position);
//    }

    for (auto &island: islands) {
        float diff;
        diff = island.position.z - player.position.z;
        if (diff < 120 && diff > -120)
            island.tick(player.position);
    }


    for (auto &parachute : parachute_enemies) {
        parachute.tick(player.position);
    }


    enemy.tick(player.position);

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    if (xpos > 1000) {
        cam.hel_rotation.x -= 1;
    }
    if (xpos < 200) {
        cam.hel_rotation.x += 1;
    }
    if (ypos < 100) {
        cam.hel_rotation.y -= 1;
    }
    if (ypos > 650) {
        cam.hel_rotation.y += 1;
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

//    ball1 = Circle(glm::vec3(0.0f, 50.0f, -10.0f), 10.0f, COLOR_RED, glm::vec3(1,0,0));
    ocean = Cuboid(glm::vec3(0.0f, -100.0f, 0.0f), 2000.f, 30.f, 2000.f, COLOR_BLUE);
    ocean_surface = ocean.center.y + ocean.height/2;

    player = Jet(player_start);
    sphere = Sphere(glm::vec3(player.position.x + 2, player.position.y , player.position.z-10), 0.25, COLOR_RED);
    if (DEBUG) printf("ocean.y -> %f\n", ocean_surface);
//    exit(0);
    float mountain_length = 10;
    float mountain_radius = 4;

    auto start = player_start;
//    mountains.emplace_back(Mountain(glm::vec3(player_start.x + 2, ocean_surface + mountain_length, player_start.z - 20), mountain_length, mountain_radius));
    for (int i=-50, j=1;i< 25;i+=2, j+=3) {
        mountain_length = 10 + 5 - rand()%10;
        mountain_radius = 6 + 2 - rand()%5;
        mountains.emplace_back(Mountain(
                {start.x + 40 - rand() % 80, ocean_surface + mountain_length + 10 - rand() % 20, start.z + i * j},
                mountain_length, mountain_radius));
    }


//    rings.emplace_back(Ring({start.x, start.y, start.z-50}, 5));
//    direction_arrows.emplace_back(Arrow({start.x, start.y, start.z -  30}, {1,1,-1}));
    float min_dist = 100;
    glm::vec3 curr = start;
    glm::vec3 next = {start.x + 15 - rand()%30, start.y + 15 - rand()%30, start.z - min_dist + 20 - rand()%40};
//    next = start + glm::vec3(0, 100, -100);
//
//    direction_arrows.emplace_back(Arrow({curr.x, curr.y, curr.z - 10}, next-curr));
//    rings.emplace_back(Ring(next, 5));
    for (int i=0;i<10;i++) {

        direction_arrows.emplace_back(Arrow({curr.x, curr.y, curr.z - 10}, next-curr));
        rings.emplace_back(Ring(next, 5));
        min_dist += 100;
        curr = next;
        next = {start.x + 15 - rand()%30, start.y + 15 - rand()%30, start.z - min_dist + 20 - rand()%40};
        islands.emplace_back(Island(glm::vec3 (mountains[i].position.x + 10 +20 - rand()%40, ocean_surface, start.z - min_dist - 50 + 10 - rand()%20)));
    }

//    islands.emplace_back(Island(glm::vec3 (start.x + 20, ocean_surface, start.z - 150)));
//    lines.emplace_back(Line( glm::vec3(start.x, start.y, start.z - 30), glm::vec3 (1,1,1), 10, COLOR_RED));
    parachute_enemies.emplace_back(Parachute(glm::vec3 {start.x, start.y, start.z - 30}));

//    altitude_indicator = VariableRectangle(glm::vec3(-0.5, -1, 0), 1,1,COLOR_SADDLE_BROWN, COLOR_RED );
    altitude_indicator = Indicator(glm::vec3 (-0.5, -1, 0), 'H');
    fuel_indicator = Indicator(glm::vec3 (-0.5, -1, 0), 'F');
//    fuel_indicator = Indicator(glm::vec3(-0))
    pump = PetrolPump(glm::vec3(start.x, start.y, start.z - 600));
    cam = Camera(top);
    compass = Compass(glm::vec3(0));
    enemy = Canon(glm::vec3(start.x - 10, ocean_surface, start.z - 100));
    missiles.emplace_back(Missile({start.x, start.y, start.z - 50}, glm::vec3({1,1,1})));

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
    printf("%d %d\n",width, height);
    get_resolution(&window_width, &window_height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers
//        printf("yes\n");
        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw comma
            draw();
//            printf("no\n");
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
    Matrices.projection = glm::perspective(glm::radians(zoom_angle), 4.0f / 3.0f, 0.1f, (float)cam.cam_view);
    fuel_projection = glm::ortho(-20.f, 20.f, -1.f, 1.f, 0.f, 500.f);
    altitude_projection = glm::ortho(-1.3f,1.3f,-1.f,1.f,0.1f,500.f);
    compass_projection = glm::ortho(-1.2f, 1.2f, -1.f, 1.f, 0.1f, 100.f);
//    glm::perspective
}
