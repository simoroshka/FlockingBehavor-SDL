#ifndef AGENT_H
#define AGENT_H

#include "Swarm.h"
#include "Vector2.h"
#include "Screen.h"


namespace mysdl{

class Swarm;

class Agent
{
    Swarm static * swarm;

    /*agent config*/
    double static const max_velocity = 0.08;
    double static const max_acceleration = 0.0002;

    double const Rc = 50;
    double const Rs = 10;
    double const Ra = 15;
    double const Kc = 1;
    double const Ks = 3;
    double const Ka = 5;

    /*end config*/


    double speed;


    void init();


    Vector2* cohesion();    //cohesion behaviour
    Vector2* separation();  //~
    Vector2* alignment();   //~
    Vector2* combine();     //combine all behaviours to get acceleration



    public:
        Vector2* position;
        Vector2* velocity;
        Vector2* acceleration;

        void setSwarm(Swarm*);

        void update(int deltaTime);
        void render();

        Agent();
        virtual ~Agent();

};
} //namespace mysdl
#endif // AGENT_H
