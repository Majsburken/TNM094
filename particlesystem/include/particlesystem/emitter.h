#pragma once
#include <vector>
class Emitter {
private:
    std::vector<float> position;
    float angle;
    public:
    // default constructor
    explicit Emitter();
        std::vector<float> getPosition() const;
};