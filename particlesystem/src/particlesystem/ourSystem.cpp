#include <particlesystem/ourSystem.h>

ourSystem::ourSystem(int numParticles) {

    myEffect = Effect();
    myEmitter = Emitter();
    prevTime = {0.0f};
    
    for (int i = 0; i < numParticles; ++i) {
        particles.push_back(Particle(myEmitter.getPosition()));
    }
}

float ourSystem::randomFloat(float lo, float hi) const {
     return lo + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (hi - lo)));
}

 void ourSystem::update(double time, float speed, int angle, bool emitterRandom, bool effect, bool effectGravity) {
    const double dt = time - prevTime;
    prevTime = time;
    float radians;
    if (emitterRandom) {
        radians = randomFloat(0, 6.28);
    } else {
        radians = angle * (3.14 / 180.0);
    }
    
    const float simDt = static_cast<float>(dt) * speed;
    float radius = 0;

    for (Particle& e : particles) {
        if (effect) {
            if (effectGravity) {
                 radius = sqrt(pow(abs(e.position[0] - myEffect.getPosition()[0]), 2) +
                              pow(abs(e.position[1] - myEffect.getPosition()[1]), 2));
                e.velocity[0] += (myEffect.getPosition()[0] - e.position[0]) * simDt *
                                 (0.1 * e.mass) / pow(radius, 2);
                e.velocity[1] += (myEffect.getPosition()[1] - e.position[1]) * simDt *
                                 (0.1 * e.mass) / pow(radius, 2);
            } else {
                e.velocity[0] += 7*(e.position[0] - myEffect.getPosition()[0]) * simDt;
                e.velocity[1] += 7*(e.position[1] - myEffect.getPosition()[1]) * simDt;
            }
        }
        e.position += e.velocity * simDt;
        e.color[3] = std::min(e.color[3], e.lifetime);
        e.lifetime -= simDt;

        //randomColor = Lo0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (HiC - LO)));
         
         if (e.lifetime < 0.0f) {
            e.position = myEmitter.getPosition();
            e.color = {randomFloat(Lo0, HiC), randomFloat(Lo0, HiC), randomFloat(Lo0, HiC),0.5f};
            e.size = {randomFloat(Lo0, HiS)};
            e.velocity = {cos(radians), sin(radians)};
            e.lifetime = randomFloat(LoL, HiL);
        }
    }
 }

 std::vector<glm::vec2> ourSystem::getPosition() const { 
     std::vector<glm::vec2> positions;
     for (Particle e : particles) {
        positions.push_back(e.position);
     }
     return positions;
 }

 std::vector<glm::vec4> ourSystem::getColor() const {
     std::vector<glm::vec4> colors;
     for (Particle e : particles) {
        colors.push_back(e.color);
     }
     return colors;
 }

 std::vector<float> ourSystem::getSize() const {
     std::vector<float> sizes;
     for (Particle e : particles) {
        sizes.push_back(e.size);
     }
     return sizes;
 }
