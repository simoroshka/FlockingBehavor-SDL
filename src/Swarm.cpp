#include "Swarm.h"
#include <vector>
#include "Vector2.h"

namespace mysdl {

Swarm::Swarm(): lastTime(0)
{
    m_agents = new Agent[NPARTICLES];

    for (unsigned int i = 0; i < NPARTICLES; i++) {
        m_agents[i].setSwarm(this);
    }

}

void Swarm::update(int elapsed)
{
    int deltaTime = elapsed - lastTime;

    for (unsigned int i = 0; i < NPARTICLES; i++) {
        m_agents[i].update(deltaTime);
    }

    lastTime = elapsed;
}


std::vector<Agent*> Swarm::getNeighbors(const Agent* agent, const double radius) const
{
    //returns an array of links to agents that are in a given radius

    std::vector<Agent*> neighbors;

    for (unsigned int i = 0; i < NPARTICLES; i++) {
        if (&m_agents[i] != agent &&
            Vector2::DistanceSq(m_agents[i].position, agent->position) < radius*radius)
        {
            neighbors.push_back(&m_agents[i]);
        }
    }
    return neighbors;
}

Swarm::~Swarm()
{
    delete [] m_agents;
}

}//namespace mysdl
