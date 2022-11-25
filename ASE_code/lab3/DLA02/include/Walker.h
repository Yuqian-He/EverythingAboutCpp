#ifndef WALKER_H_
#define WALKER_H_
#include"Image.h"
#include<memory>
#include<string>
#include<random>

class Walker
{
public:
    Walker(size_t _w, size_t _h);
    Walker(const Walker & )=delete; //this is no longer copyable
    bool saveImage(const std::string &_fname) const;
    void randomImageSeed();//init the color to the seed
    void resetStart();
    void walk(int _x, int _y);
    void getCentrePoint();


private:
    //void initRNG();
    std::unique_ptr<Image> m_map; //map is a pointer point to a series of image
    //random pixcles of seed,random position of x and y
    std::uniform_int_distribution<> m_xRand;
    std::uniform_int_distribution<> m_yRand;

    //okay, I can undestand now
    int m_xpos;
    int m_ypos;
};

#endif