#include "Agent.h"
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

namespace mysdl {

const double Agent::max_velocity;
const double Agent::max_acceleration;
Swarm * Agent::swarm;

Agent::Agent()
{

    init();

}

void Agent::init()
{
    position = new Vector2(Screen::WIDTH * rand()/RAND_MAX, Screen::HEIGHT * rand()/RAND_MAX);


    acceleration = new Vector2();
    velocity = new Vector2(max_velocity * 2 * rand()/RAND_MAX - max_velocity,
                           max_velocity * 2 * rand()/RAND_MAX - max_velocity);

    return;
}

void Agent::setSwarm(Swarm* s) {
    swarm = s;
    return;
}

Vector2* Agent::cohesion()
{
    //return a vector that will steer the velocity
    //towards the center of mass of neighbors
    Vector2* result = new Vector2();


    //get all my nearby neighbors in the radius of cohesion
    std::vector<Agent*> neighbors = swarm->getNeighbours(this, Rc);

    //if no neighbors found, then no cohesion desire, return zero vector
    if (neighbors.size() == 0) { return result; }

    //otherwise find center of mass in the group
    for (int i = 0; i < neighbors.size(); i++) {
        (*result) += (*neighbors[i]->position);
    }
    (*result) /= neighbors.size();

    (*result) -= (*this->position);

    result->Normalize();

    return result;


}

Vector2* Agent::separation()
{
    //separation behaviour
    //steer away from the close neighbours

    Vector2* result = new Vector2();

    //get all my nearby neighbors in the radius of separation
    std::vector<Agent*> neighbours = swarm->getNeighbours(this, Rs);

    //if no neighbors found, then no cohesion desire, return zeros
    if (neighbours.size() == 0) {
        return result;
    }

    //otherwise calculate the separation behaviour vector

    for (int i = 0; i < neighbours.size(); i++) {
        Vector2 towards = (*this->position) - (*neighbours[i]->position);

        //the force contribution is inversly proportional
        //to the distance between agents
        double len = towards.Length();
        if (len != 0) {
            (*result) += towards.Normalize() / len;
        }



    }
    result->Normalize();

    return result;
}

Vector2* Agent::alignment()
{
    //alignment behaviour
    //steer the agent to align its movements with the neighbours

    Vector2* result = new Vector2();

    //get all my nearby neighbors in the radius of separation
    std::vector<Agent*> neighbours = swarm->getNeighbours(this, Ra);

    //if no neighbors found, then no alignment desire, return zeros
    if (neighbours.size() == 0) {
        return result;
    }

    //match velocity
    for (int i = 0; i < neighbours.size(); i++) {
        (*result) += (*neighbours[i]->velocity);
    }
    result->Normalize();

    return result;
}

Vector2* Agent::combine()
{
    Vector2* result = new Vector2();
    (*result) += *(cohesion()) * Kc;
    (*result) += *(separation()) * Ks;
    (*result) += *(alignment()) * Ka;
    return result;
}

void Agent::update(int deltaTime) {

    acceleration = combine(); //get acceleration
    acceleration->ClumpMagnitude(max_acceleration);

   // cout << "(" << acceleration->x << "; " << acceleration->y << ")\n";

    (*velocity) += (*acceleration) * (double)deltaTime;
     velocity->ClumpMagnitude(max_velocity);

    (*position) += (*velocity) * (double)deltaTime;


    if (position->x < 0 || position->x > Screen::WIDTH) {
        velocity->x *= -1;
       // acceleration->x *= -1;
    }
    if (position->y < 0 || position->y > Screen::HEIGHT) {
        velocity->y *= -1;
      //  acceleration->y *= -1;
    }

    position->Truncate(0, 0, Screen::WIDTH, Screen::HEIGHT);

    return;

}


Agent::~Agent()
{
    //dtor
}
}
