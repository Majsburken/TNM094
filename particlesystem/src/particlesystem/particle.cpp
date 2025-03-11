#include <particlesystem/particle.h>
#include <vector>
#include <string>
#include <iostream>

    // default constructor
Particle::Particle(glm::vec2 pos) { 
    velocity = {5.0f,5.0f};
    lifetime = 1.0f;
    color = {0.5f, 0.5f, 0.f, 0.5f};
    position = pos;
    force = {0.0f, 0.0f};
    size = {10.0f};
    mass = {10.0f};
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

    glm::vec4 Particle::getColor() const { return color;
    }

    glm::vec2 Particle::getPosition() const{ 
        return position;
    }