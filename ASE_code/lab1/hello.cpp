#include<iostream>
#include<fmt/format.h>

int main()
{
  for(int i = 0; i <10; i++){
    fmt::print("This is using placeholders {} {} {} \n",1,2,3);
  }
 
  return EXIT_SUCCESS;
}