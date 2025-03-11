#include <particlesystem/effect.h>

Effect::Effect() {
    position = {0.0f, 0.0f};
    effectType = "";
}

glm::vec2 Effect::getPosition() const { return position; }
