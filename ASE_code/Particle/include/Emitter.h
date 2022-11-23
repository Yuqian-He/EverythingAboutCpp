#ifndef EMITTER_H_
#define EMITTER_H_
#include <cstddef>
#include <vector>
#include "Particle.h"

class Emitter
{
    public :
    Emitter(size_t _numParticles);
    size_t getNumParticles() const;
    void update();
    void render() const;

    private:
    std::vector<Particle> m_particles;
};

#endif