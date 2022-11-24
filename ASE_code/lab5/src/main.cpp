#include<iostream>
#include<random>
#include"Image.h"

int main()
{
    //will be used to obtain a seed for the random number engine
    std::random_device rd; //this device will generate our random numbers.
    std::mt19937 gen(rd());//random number of generator generated with the random device.

    //get a value
    constexpr int width=500;
    constexpr int height=500;

    //set distrubition of pixels' position
    std::uniform_int_distribution<> randWidth(0,width-1);
    std::uniform_int_distribution<> randHeight(0,height-1);
    std::uniform_int_distribution<> randRadius(0,height/2);

    std::uniform_int_distribution<unsigned char> colour(0,255);
    std::uniform_real_distribution<float> zeroToOne(0.0f,1.0f);

    Image image(width,height,255,255,255,255);
    for(size_t i = 0; i<50; i++)
    {
        auto r=colour(gen);
        auto g=colour(gen);
        auto b=colour(gen);
        auto x = randWidth(gen);
        auto y = randHeight(gen);

        for(size_t s=0; s<500; s++){
            
            auto splat_size =30; //create redius
            auto alpha = 2*M_PI*zeroToOne(gen);
            auto radius = splat_size*sqrtf(zeroToOne(gen));
            auto rx = x +int(radius*cosf(alpha));
            auto ry = y +int(radius*sinf(alpha));

            if((rx>=(width-20)) ||( ry>=(height-20)) )
            {
                continue;
            }else{
                image.setPixel(rx,ry,colour(gen),colour(gen),colour(gen));
            }               
        }
       
        
    }
    image.save("ImagePlayground.jpg");

    return EXIT_SUCCESS;
}