#include "Emitter.h"
#include<iostream>
#include"Random.h"

Emitter::Emitter(size_t _numParticels)
{
    m_particles.resize(_numParticels);
    Vec3 emitDir(0,10.0f,0);
    for(auto &p : m_particles)
    {
        p.direction=emitDir * Random::randomPositiveFloat() +
        Random::randomVectorOnSphere()*10;
        p.direction.y=std::abs(p.direction.y);
        p.colour=Random::randomPositiveVec3();
    }
}

size_t Emitter::getNumParticles() const
{
    return m_particles.size();
}

void Emitter::update()
{
    float _dt=0.01f;
    Vec3 gravity(0,-9.81,0);
    for(auto &p : m_particles)
    {
        p.direction += gravity * _dt * 0.5f;
        p.direction +=p.direction*_dt;

    }
}

void Emitter::render() const
{
    for(auto p:m_particles)
    {
        //std::cout<<"**************************************\n";
        std::cout<<p.position.x<<','<<p.position.y<<','<<p.position.z<<'\n';
        //std::cout<<p.direction.x<<' '<<p.direction.y<<' '<<p.direction.z<<'\n';
        //std::cout<<p.colour.x<<' '<<p.colour.y<<' '<<p.colour.z<<'\n';
    }
}