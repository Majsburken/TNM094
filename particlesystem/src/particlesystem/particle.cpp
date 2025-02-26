#include <particlesystem/particle.h>
#include <vector>
#include <string>
#include <iostream>

    // default constructor
Particle::Particle(std::vector<float> pos) { 
    velocity = {0.0f};
    lifetime = 1.0f;
    color = {0.5f, 0.5f, 0.f, 0.5f};
    position = pos;
    force = {0.0f, 0.0f};
    size = {1.0f};
    mass = {1.0f};
    }
   

    /*void Particle::updateParticle(){

    };*/

   /* void Particle::updateColor(std::vector<int> newColor) { color = newColor;
        return;
    }*/

    //void Particle::updateLifetime(int newLifeTime) { lifeTime = newLifeTime;
    //    return;
    //}
    
    float Particle::getLifetime() const { return lifetime;
    }

    std::vector<float> Particle::getColor() const { return color;
    }

    std::vector<float> Particle::getPosition() const{ 
        return position;
    }