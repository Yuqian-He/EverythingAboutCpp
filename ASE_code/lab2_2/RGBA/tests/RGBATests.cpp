#include<gtest/gtest.h>
#include"rgba.h"

TEST(RGBA,construct)
{
  RGBA a;
  ASSERT_TRUE(a.r == 0);
  ASSERT_TRUE(a.g == 0);
  ASSERT_TRUE(a.b == 0);
  ASSERT_TRUE(a.a == 0);
}

int main(){

  RGBA a;
  set(a.r, a.g, a.b, a.a);
  return EXIT_SUCCESS;
}