#pragma once
#include <particlesystem/particle.h>

class Emitter {
private:
    glm::vec2 position;
    int angle;
public:
    // default constructor
    explicit Emitter();
    glm::vec2 getPosition() const { return position; };
};