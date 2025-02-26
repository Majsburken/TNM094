#pragma once
#include <vector>
#include <string>
#include <iostream>

class Particle {
private:
     std::vector<float> force;
     float mass;

    //void updateParticle();
    //void updateColor(std::vector<int> newColor);
    //void updateLifetime(int newLifeTime);

public:
    // default constructor
    explicit Particle(std::vector<float> pos);
    std::vector<float> getPosition() const;
    int getLifetime() const;
    std::vector<float> getColor() const;
    std::vector<float> position;
    float velocity;
    std::vector<float> color;
    int lifetime;
    float size;
};

template <typename T>
void printVector(std::vector<T> v) {
    for (T e : v) {
        std::cout << e << " ";
    }
};