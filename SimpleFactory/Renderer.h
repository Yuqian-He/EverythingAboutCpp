#ifndef RENDERER_H
#define RENDERER_H

#include<string>

class Renderer
{
    public:
    virtual ~Renderer(){}
    virtual bool loadScene(const std::string &filename) = 0;
    virtual void setViewportSize(int _w, int _h) = 0;
    virtual void setCameraPos(float _x, float _y, float _z) = 0;
    virtual void setLookAt(float _x, float _y, float _z) = 0;
    virtual void render() = 0;

};

#endif