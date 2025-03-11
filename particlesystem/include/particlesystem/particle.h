#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

class Particle {
private:
     std::vector<float> force;

    //void updateParticle();
    //void updateColor(std::vector<int> newColor);
    //void updateLifetime(int newLifeTime);

public:
    // default constructor
    explicit Particle(glm::vec2 pos);
    glm::vec2 getPosition() const;
    float getLifetime() const;
    glm::vec4 getColor() const;
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec4 color;
    float lifetime;
    float size;
    float mass;
};

template <typename T>
void printVector(std::vector<T> v) {
    for (T e : v) {
        std::cout << e << " ";
    }
};