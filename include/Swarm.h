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
        const static int NPARTICLES = 200;

        void update(int elapsed);
        std::vector<Agent*> getNeighbours(Agent* agent, double radius);
        Agent * getAgents() {return m_agents;};
        double sqDistance(double x1, double y1, double x2, double y2);

        Swarm();
        virtual ~Swarm();


};
} //namespace mysdl
#endif // SWARM_H
