#ifndef PARTICLE_H
#define PARTICLE_H

namespace mysdl {
class Particle
{
    double m_speed;
    double m_direction;
    double m_acceleration;

    void init();

    void update(int deltaTime);

    public:
        double m_x;
        double m_y;
        double m_rotation;

        Particle();
        virtual ~Particle();
};
} //namespace mysdl
#endif // PARTICLE_H
