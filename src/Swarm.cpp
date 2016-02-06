#include "Swarm.h"
#include <vector>
#include "Vector2.h"



namespace mysdl {
Swarm::Swarm(): lastTime(0)
{
    m_agents = new Agent[NPARTICLES];
    m_agents[0].setSwarm(this);
}
Swarm::~Swarm()
{
    delete [] m_agents;
}

void Swarm::update(int elapsed)
{
    int deltaTime = elapsed - lastTime;

    for (int i = 0; i < NPARTICLES; i++) {
        m_agents[i].update(deltaTime);
    }

    lastTime = elapsed;
}


std::vector<Agent*> Swarm::getNeighbours(Agent* agent, double radius)
{
    //should return an array of links to agents


    std::vector<Agent*> neighbors;

    for (int i = 0; i < NPARTICLES; i++) {
        if (&m_agents[i] != agent &&
            Vector2::DistanceSq(m_agents[i].position, agent->position) < radius*radius)
        {
            neighbors.insert(neighbors.end(), &m_agents[i]);
        }
    }
    return neighbors;
}
//returns sqared distance between points
double Swarm::sqDistance(double x1, double y1, double x2, double y2) {

    return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

}

}//namespace mysdl
