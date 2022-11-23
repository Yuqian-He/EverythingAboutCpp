#include <iostream>
#include <chrono>
#include "Emitter.h"

int main()
{
  std::cout<<"Particle System\n";
  Emitter e(1);
  for(int i=0; i<100; ++i)
  {
    //std::cout<<"Frame"<<i<<"\n";
    e.update();
    e.render();
  }
  return EXIT_SUCCESS;
}