#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace mysdl {
Particle::Particle()
{
    init();
}
void Particle::init() {
    m_x = 0;
    m_y = 0;

    m_direction = 2 * M_PI * rand()/RAND_MAX;
    m_speed = 0.02 * rand()/RAND_MAX;

    m_speed *= m_speed;
}


Particle::~Particle()
{

}

void Particle::update(int deltaTime) {
    m_direction += deltaTime * 0.0003;

    double xSpeed = m_speed * cos(m_direction);
    double ySpeed = m_speed * sin(m_direction);

    m_x += xSpeed * deltaTime;
    m_y += ySpeed * deltaTime;



    if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
        init();
    }

}
} //namespace mysdl

