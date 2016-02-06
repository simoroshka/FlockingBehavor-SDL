#ifndef SWARM_H
#define SWARM_H
#include "Agent.h"
#include <vector>

namespace mysdl {

class Agent;

class Swarm
{
    private:
        Agent * m_agents;
        int lastTime;

    public:
        const static unsigned int NPARTICLES = 200;

        void update(int elapsed);
        std::vector<Agent*> getNeighbors(const Agent* agent, const double radius) const;
        Agent * getAgents() const {return m_agents;}

        Swarm();
        virtual ~Swarm();

};
} //namespace mysdl
#endif // SWARM_H
