#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Vec3.h"

struct Particle
{
    int lifetime=0; 
    Vec3 position;
    Vec3 colour;
    Vec3 direction={0.0f,1.0f,0.0f};
};

#endif