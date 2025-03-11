#include <rendering/window.h>
#include <example/randomsystem.h>
#include <particlesystem/particlesystem.h>
#include <particlesystem/ourSystem.h>
#include <iostream>

#include <fmt/format.h>

#include <cmath>
#include <vector>
#include <random>
#include <algorithm>


/*
 * This application represents the "Client" the uses your particle system
 */
int main() try {
    rendering::Window window("Particle System v0.0.2 pre-release alpha", 850, 850);

    // Creates an example system with a 1000 particles.
    // This should be replaced with your new particle system
    const size_t numParticles = 1000;
    example::RandomSystem system{numParticles};
    ourSystem mySystem({numParticles});
    Particle binkparticle({0,0});
    //std::cout << "hej" << std::to_string(binkparticle.getLifeTime()) << std::endl;
   std::vector<float> v = {0.9, 56.9, 54.0};

  


    //glm::vec2 position = binkparticle.getPosition();


    float speed = 1.0f;
    int angle = 0;
    bool running = true;
    bool emitterRandom = true;
    bool effectGravity = true;
    bool effect = false;
    while (running) {
        window.beginFrame();

        // Update the example system.
        // This should be replaced with a call to the new particle system
        mySystem.update(window.time(), speed, angle, emitterRandom, effect, effectGravity);

        // Clear screen with color
        window.clear({0, 0, 0, 1});

        // Draw particles
        // This should also be adjusted to work with the new particle system
     
        window.drawPoints(mySystem.getPosition(), mySystem.getSize(),
                          mySystem.getColor());

        // Example user interface, extend for your needs.
        // Might add controls for effects and emitters etc.
        {
            window.beginGuiWindow("UI");
            window.text("I'm spid, ka-chow!");
            window.sliderFloat("Speed", speed, 0.001f, 10.0f);
            window.sliderInt("Angle", angle, 0, 360);
            
            if (window.button("Emitter Random")) {
                if (emitterRandom) { 
                    emitterRandom = false;
                    std::cout << "now random emitter false";

                } else {
                    emitterRandom = true;
                    std::cout << "now random emitter true";

                }
            }
            if (window.button("Reset")) {
                emitterRandom = true;
                effect = false;
            }
            
            if (window.button("Effect")) {
               
                if (effect) {
                    effect = false;
                    std::cout << "nu är effect = false";
                } else {
                    effect = true;
                    std::cout << "nu är effect = true";
                }
            }
           
            if (window.button("Effect gravity/wind")) {
                if (effectGravity) {
                    effectGravity = false;
                    std::cout << "now wind";

                } else {
                    effectGravity = true;
                    std::cout << "now gravity";
                }
            }     

            if (window.button("Close application")) {
                running = false;
            }
            window.endGuiWindow();
        }

        window.endFrame();
        running = running && !window.shouldClose();
    }

    return EXIT_SUCCESS;
} catch (const std::exception& e) {
    fmt::print("{}", e.what());
    return EXIT_FAILURE;
}
