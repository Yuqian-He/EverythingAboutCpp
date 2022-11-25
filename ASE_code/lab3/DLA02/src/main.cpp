#include<iostream>
#include"Walker.h"
#include<fmt/format.h>

int main()
{

    std::cout<<"DLA\n";
    Walker w(512,512);
    for(size_t i=0; i<10; i++)
    {
        //first init the point seed
        w.randomImageSeed();
    }

//generate 100 sequence
    for(int i=0; i<10; i++)
    {
        std::cout<<"generate 10 sequence\n";
        /*
        if(w.walk()==true)//if the next one step is successful
        {
            w.saveImage(fmt::format("sim.{:04d}.tiff",i));//generate sequence
        }
        w.resetStart();//then regenerate it
        */

       //getPixel and draw walk
       w.getCentrePoint();


       w.saveImage(fmt::format("sim.{:04d}.tiff",i));

    }

    //w.saveImage("test.jpg");
    return EXIT_SUCCESS;
}