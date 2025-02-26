#include <particlesystem/emitter.h>

Emitter::Emitter() {
	position = {0.0f, 0.0f};
    angle = 0.0f;
}

std::vector<float> Emitter::getPosition() const { return position; }
