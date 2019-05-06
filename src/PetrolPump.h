//
// Created by sriteja on 18/2/19.
//

#ifndef JETSTRIKE_PETROLPUMP_H
#define JETSTRIKE_PETROLPUMP_H


#include "TwoDPolygon.h"
#include "Cuboid.h"

class PetrolPump {
public:
    PetrolPump() {}
    PetrolPump(glm::vec3 position);
    void draw(glm::mat4 VP);
    glm::vec3 position;
    TwoDPolygon outer;
    TwoDPolygon inner;
    Cuboid outer_box;
};


#endif //JETSTRIKE_PETROLPUMP_H
