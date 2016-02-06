#include <iostream>

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace mysdl;

int main(int argc, char *argv[]) {


    srand(time(NULL));

    Screen screen;

    if (screen.init() == false) {
        cout << "error initializing SDL" << endl;
    }

    Swarm swarm;

    Agent * pParticles = swarm.getAgents();

    swarm.getNeighbors(&pParticles[0], 20);

    int lastTime = 0;

    while (true) {
        int elapsed = SDL_GetTicks();

        //reduce the frame rate to 60 fps
        if (elapsed - lastTime > 1000/60) {
            //clear the screen
            screen.clear();


            //update particles
            swarm.update(elapsed);

            unsigned char green, red, blue;


            green = 150 + (1 + sin(elapsed * 0.001)) * 50;
            red = 150 + (1 + sin(elapsed * 0.002)) * 50;
            blue = 150 + (1 + sin(elapsed * 0.003)) * 50;


            //draw particles
            for (unsigned int i = 0; i < Swarm::NPARTICLES; i++) {
                Agent particle = pParticles[i];

                int x = particle.position.x;
                int y = particle.position.y;

                screen.setPixel(x, y, red, green, blue);
            }

            //draw the screen
            screen.update();

            //check for events
            if (!screen.ProcessEvents()) break;
        }

    }

    screen.close();

    return 0;
}
