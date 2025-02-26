#include <particlesystem/ourSystem.h>
#include <particlesystem/emitter.h>


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

 void ourSystem::update(double time, float speed) {
    const double dt = time - prevTime;
    prevTime = time;

    const float simDt = static_cast<float>(dt) * speed;

    for (Particle e : particles) {
        e.position[0] += e.velocity * simDt;
        e.position[1] += e.velocity * simDt;
        e.color[3] = std::min(e.color[3], e.lifetime);
        e.lifetime -= simDt;

        //randomColor = Lo0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (HiC - LO)));
         
         if (e.lifetime < 0.0f) {
            e.position = myEmitter.getPosition();
            e.color = {randomFloat(Lo0, HiC), randomFloat(Lo0, HiC), randomFloat(Lo0, HiC)};
            e.size = randomFloat(Lo0, HiS);
            e.lifetime = randomFloat(LoL, HiL);
        }
    }
 }
