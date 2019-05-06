//
// Created by sriteja on 20/2/19.
//

#include "Parachute.h"


Parachute::Parachute(glm::vec3 position) {
    this->position = position;

    canopy = Hemisphere(position, 2, COLOR_DEEP_PINK, 360);
    canopy.rotate(-90, ORIGIN, X_AXIS);
    payload = Cuboid(glm::vec3 (position.x, position.y - 3, position.z), 1.5,1.5,1.5,COLOR_DARK_ORANGE);
//    link = Cylinder(glm::vec3 (position.x, position.y - payload.height/2, position.z), 0.5, 0.1, COLOR_BLACK);
    link = Cylinder(glm::vec3 (payload.center.x, payload.center.y + payload.height/2, payload.center.z), 0.5, 0.1, COLOR_BLACK);
    link.rotate(-90, ORIGIN, X_AXIS);
    glm::vec3 link_point = link.position + glm::vec3(0, link.length/2, 0);
    glm::vec3 temp_pos = position - glm::vec3(-canopy.radius, 0, 0);
    float dist = glm::length(link_point - temp_pos);
    suspension_lines.emplace_back(Line (temp_pos, link_point-temp_pos, dist, COLOR_BLACK ));
    temp_pos = position - glm::vec3(canopy.radius, 0, 0);
    suspension_lines.emplace_back(Line (temp_pos, link_point-temp_pos, dist, COLOR_BLACK ));
    temp_pos = position - glm::vec3(0, 0, canopy.radius);
    suspension_lines.emplace_back(Line (temp_pos, link_point-temp_pos, dist, COLOR_BLACK ));
    temp_pos = position - glm::vec3(0, 0, -canopy.radius);
    suspension_lines.emplace_back(Line (temp_pos, link_point-temp_pos, dist, COLOR_BLACK ));


}


void Parachute::draw(glm::mat4 VP) {
    this->canopy.draw(VP);
    this->payload.draw(VP);
    link.draw(VP);
    for (auto line : suspension_lines)
        line.draw(VP);

    for (auto &missile : missiles) {
        missile.draw(VP);
    }

}


void Parachute::shoot(glm::vec3 player_position) {
    glm::vec3 direction = glm::normalize(player_position - payload.center);
//    direction.z -= 0.1;

    missiles.emplace_back(Missile(payload.center, direction));
}


void Parachute::tick(glm::vec3 player_position) {
    if (rand()%100 == 4) {
        shoot(player_position);
    }

    for (auto &missile: missiles) {
        missile.tick();
        printf("came here");
    }
}