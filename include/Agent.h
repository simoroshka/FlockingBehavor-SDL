#ifndef AGENT_H
#define AGENT_H

#include "Swarm.h"
#include "Vector2.h"
#include "Screen.h"

namespace mysdl{

class Swarm;

class Agent
{
    Swarm * swarm;

    /*agents config*/
    double static const max_velocity = 0.08;
    double static const max_acceleration = 0.0002;

    const static double Rc = 50;
    const static double Rs = 10;
    const static double Ra = 15;
    const static double Kc = 1;
    const static double Ks = 3;
    const static double Ka = 5;

    /*end config*/

    void init();

    Vector2 cohesion() const;    //cohesion behaviour
    Vector2 separation() const;  //~
    Vector2 alignment() const;   //~
    Vector2 combine() const;     //combine all behaviours to get acceleration

    public:
        Vector2 position;
        Vector2 velocity;
        Vector2 acceleration;

        void setSwarm(Swarm*);

        void update(int deltaTime);

        Agent();
        virtual ~Agent();

};
} //namespace mysdl
#endif // AGENT_H
