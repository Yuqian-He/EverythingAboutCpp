#include "Walker.h"
#include<iostream>
#include<random>

std::random_device g_rd;//don't want put it in a header because everytime you # a header you'll generate it again
std::mt19937 g_rng(12345);
std::uniform_int_distribution<> g_walkDir(-1,1);

Walker::Walker(size_t _w, size_t _h)
{
    m_map=std::make_unique<Image>(_w,_h,255,255,255,0);
    //initRNG();
    resetStart();
}

bool Walker::saveImage(const std::string &_fname) const
{
    std::cout<<"Saving frame"<<_fname<<'\n';
    return m_map->save(_fname);
}

/*
void Walker::initRNG()
{
    m_xRand=std::uniform_int_distribution<>(1,m_map->width()-1);
    m_yRand=std::uniform_int_distribution<>(1,m_map->height()-1);
}
*/

void Walker::randomImageSeed()
{
    //set the random position of the pixels
    m_xRand=std::uniform_int_distribution<>(1,m_map->width()-1);
    m_yRand=std::uniform_int_distribution<>(1,m_map->height()-1);
    m_map->setPixel(m_xRand(g_rd),m_yRand(g_rd),255,0,0,255);

}

//I don't understand this function
void Walker::resetStart()
{
    m_xpos=m_xRand(g_rng);
    m_ypos=m_yRand(g_rng);
    std::cout<<"New Start"<<m_xpos<<' '<<m_ypos<<'\n';
}

void Walker::getCentrePoint()
{
    std::cout<<"begin get cenre\n";
    for(int x = 0; x<= m_map->width();x++)
       {
           for(int y = 0; y<= m_map->height();y++)
           {
               auto rgba=m_map->getPixel(x,y);
               std::cout<<rgba.a<<" "<<rgba.b<<'\n';
               if(rgba.r == 255 && rgba.b == 0 && rgba.g == 0 && rgba.a == 255)
               {
                   walk(x,y);
                   std::cout<<" get one point "<<x<<" "<<y<<'\n';
               }
           }
       }
}

void Walker::walk(int _x, int _y)
{
    bool walking=true;
    while(walking)
    {
        //move walker
        //To choose our next position in a random walk all we need to do is choose a random integer in the range -1 -> +1 and add this to the x position, and choose a different random number for the y position. As we are not concerned about the walker path crossing this makes it much simpler.
        //Brownian motion bit
        _x+=g_walkDir(g_rd);
        _y+=g_walkDir(g_rd);

        //have I hit the edges of the map
        if(_x==0||_x>=(m_map->width()-1) || _y==0||_y>=(m_map->height()-1) )
        {
            walking=false;
        }else{
            m_map->setPixel(_x,_y,0,0,0,255);
        }
    }
}

/*
bool Walker::walk()
{
    bool walking=true;
    bool found;
    while(walking)
    {
        //move walker
        //To choose our next position in a random walk all we need to do is choose a random integer in the range -1 -> +1 and add this to the x position, and choose a different random number for the y position. As we are not concerned about the walker path crossing this makes it much simpler.
        //Brownian motion bit
        m_xpos+=g_walkDir(g_rd);
        m_ypos+=g_walkDir(g_rd);

        //have I hit the edges of the map
        if(m_xpos==0||m_xpos>=(m_map->width()-1) || m_ypos==0||m_ypos>=(m_map->height()-1) )
        {
            walking=false;
            found=false;
            break;
        }else
        {
            m_map->setPixel(m_xpos,m_ypos,255,0,255,255);
            return true;
        }

        
        //have we a seed point
        RGBA p;
        for(int y=-1;y<=1;y++)
        {
            for(int x=-1;x<=1;x++)
            {
                p=m_map->getPixel(m_xpos+x,m_ypos+y);
            }
        }
        
    }
    

    
}
*/