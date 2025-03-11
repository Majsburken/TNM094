#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>



class Effect {
private:
    glm::vec2 position;
    std::string effectType;

public:
    // default constructor
    explicit Effect();
    glm::vec2 getPosition() const;
};