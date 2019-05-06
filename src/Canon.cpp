//
// Created by sriteja on 19/2/19.
//

#include "Canon.h"


Canon::Canon(glm::vec3 position) {
    this->position = position;
    float base_height = 4;
    base = Cuboid(position, 4, 4, base_height, COLOR_DARK_ORANGE);
//    shooter = Cylinder({position.x, position.y + base_height/2, position.z}, 3, 0.5, COLOR_BLACK );
    shooter = Sphere({position.x, position.y+base_height/2 , position.z}, 1, COLOR_BLACK);

}

void Canon::draw(glm::mat4 VP) {
//    this->base.draw(VP);
    shooter.draw(VP);

    for (auto &ball : balls)
        ball.draw(VP);

}


void Canon::shoot(glm::vec3 player_position) {
    glm::vec3 direction = glm::normalize(player_position - this->shooter.center);
    direction.z -= 0.1;
    balls.emplace_back(Sphere(shooter.center, 0.2, COLOR_BLACK));
    ball_directions.emplace_back(direction);
}

void Canon::tick(glm::vec3 player_position) {
    if (rand()%143 == 4) {
        if (glm::distance(position, player_position) < 75)
            shoot(player_position);

    }
    for (int i = 0; i < balls.size(); i++) {
//        exit(0);
        balls[i].update_position(ball_directions[i] * 1.f);

    }
    std::vector<Sphere>::iterator ball;
    std::vector<glm::vec3>::iterator ball_d;
    float dist;
    for (ball = balls.begin(), ball_d = ball_directions.begin(); ball < balls.end(); ball++, ball_d++) {
        dist = glm::distance(player_position, (*ball).center);
//        printf("dist %f ",dist);
        if (glm::distance(player_position, (*ball).center) > 125) {
//            exit(4);
            balls.erase(ball);
            ball_directions.erase(ball_d);
        }
    }
}