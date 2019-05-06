//
// Created by sriteja on 12/2/19.
//

#include "Mountain.h"


extern float ocean_surface;
Mountain::Mountain(glm::vec3 position, float length, float radius) {
    this->position = position;
//    int rand_0_2 = rand()%3;
//    int rand_3_7 = 3 + rand()%5;
//    int rand_8_11 = 8 +rand()%4;
//    int rand_12_15 = 12 + rand()%4;
//    summit = Cone(position, length, radius, COLOR_SADDLE_BROWN, 90, X_AXIS);
//    summits.emplace_back(Cone(glm::vec3(position.x + 2, ocean_surface + length, position.z - 10), length, radius, COLOR_SADDLE_BROWN, 90, X_AXIS));
//    summits.emplace_back(Cone(glm::vec3(position.x + 3, ocean_surface + length, position.z - 9), length-1, radius+1, COLOR_SADDLE_BROWN, 90, X_AXIS));
//    t = ObliqueCone(glm::vec3(position.x + 5, ocean_surface + length, position.z - 9),
//                                               glm::vec3(position.x + 7, ocean_surface + length, position.z - 9),
//                                               length-1, radius+1, COLOR_SADDLE_BROWN, 90, X_AXIS);

    summits.emplace_back(ObliqueCone(glm::vec3(position.x + 0 + 2-rand()%4, ocean_surface + length + 1 - rand()%3 + 0, position.z),
                                     glm::vec3(position.x + 0 + 2-rand()%4, ocean_surface + length + 1 - rand()%3 + 0, position.z),
                                     length+4, radius+1-rand()%3, COLOR_SADDLE_BROWN, 90, X_AXIS ));

    summits.emplace_back(ObliqueCone(glm::vec3(position.x + 2 + 2-rand()%4, ocean_surface + length + 1 - rand()%3 + 0, position.z),
                                     glm::vec3(position.x + 2 + 2-rand()%4, ocean_surface + length + 1 - rand()%3 + 0, position.z),
                                     length+4, radius+1-rand()%3, COLOR_SADDLE_BROWN, 90, X_AXIS ));

    summits.emplace_back(ObliqueCone(glm::vec3(position.x + 0 + 2-rand()%4, ocean_surface + length + 1 - rand()%3 + 2, position.z),
                                     glm::vec3(position.x + 0 + 2-rand()%4, ocean_surface + length + 1 - rand()%3 + 2, position.z),
                                     length+4, radius+1-rand()%3, COLOR_SADDLE_BROWN, 90, X_AXIS ));

    summits.emplace_back(ObliqueCone(glm::vec3(position.x + 2 + 2-rand()%4, ocean_surface + length + 1 - rand()%3 + 2, position.z),
                                     glm::vec3(position.x + 2 + 2-rand()%4, ocean_surface + length + 1 - rand()%3 + 2, position.z),
                                     length+4, radius+1-rand()%3, COLOR_SADDLE_BROWN, 90, X_AXIS ));

}

void Mountain::draw(glm::mat4 VP) {
    for (auto &summit: summits)
        summit.draw(VP);

//    t.draw(VP);
}

