#pragma once
#include <particlesystem/effect.h>
#include <particlesystem/emitter.h>
#include <vector>
#include <random>
#include <span>
#include <cmath>


class ourSystem {
private:
    Effect myEffect;
    Emitter myEmitter;
    std::vector<Particle> particles;
    float prevTime;
    
    float const Lo0 = 0.0f;
    float const HiC = 1.0f;
    float const HiS = 10.0f;
    float const LoL = 0.5f;
    float const HiL = 2.5f;
    
    float randomFloat(float lo, float hi) const;

public:
    // default constructor
    explicit ourSystem(int numParticles);
    void update(double time, float speed, int angle, bool emitterRandom, bool effect, bool effectGravity);
    std::vector<glm::vec2> getPosition() const;
    std::vector<glm::vec4> getColor() const;
    std::vector<float> getSize() const;
};