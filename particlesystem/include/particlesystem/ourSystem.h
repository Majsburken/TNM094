#pragma once
#include <particlesystem/effect.h>
#include <particlesystem/emitter.h>
#include <particlesystem/particle.h>
#include <vector>
#include <random>
#include <span>

class ourSystem {
private:
    Effect myEffect;
    Emitter myEmitter;
    std::vector<Particle> particles;
    float prevTime;
    
    float randomColor;
    float randomSize;
    float randomLifetime;

    float const Lo0 = 0.0f;
    float const HiC = 1.0f;
    float const HiS = 10.0f;
    float const LoL = 0.5f;
    float const HiL = 2.5f;
    

public:
    // default constructor
    explicit ourSystem(int numParticles);
    void update(double time, float speed);
};