#include <iostream>
#include "Colour.h"
// Note :-
// You would never really write code like this!!!!!

int main()
{
  Colour *c; 
  auto x= new Colour(0.1f,0.2f,0.3f,0.4f);
  x->clamp(0.2f,0.3f); //we use a pointer to ranther than dot,cuz it's a different type
  std::cout<<"x "<<x->red()<<' '<<x->green()<<' '<<x->blue()<<'\n';

  c = new Colour;
  std::cout<<"c "<<c->red()<<' '<<c->green()<<' '<<c->blue()<<'\n';
  delete c;
  c = new Colour(0.1f,0.2f,0.3f);
  std::cout<<"c "<<c->red()<<' '<<c->green()<<' '<<c->blue()<<'\n';
  delete c;

  delete x;

}