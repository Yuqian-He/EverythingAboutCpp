#include<iostream>
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <cstdlib>

//using namespace fmt::detail;


int main()
{
  fmt::print("This is using placeholders {} {} {} \n",1,2,3);
  return EXIT_SUCCESS;
}