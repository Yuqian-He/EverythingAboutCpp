#include "Colour.h"
#include <gtest/gtest.h>
using namespace ::testing;

TEST(Colour,defaultCtor)
{
  Colour c;
  //this use accessors to test
  EXPECT_FLOAT_EQ(c.red(),0.0f);
  EXPECT_FLOAT_EQ(c.green(),0.0f);
  EXPECT_FLOAT_EQ(c.blue(),0.0f);
  EXPECT_FLOAT_EQ(c.alpha(),1.0f);
}

//clamp like a range
//clamp: If v compares less than lo, returns lo; otherwise if hi compares less than v, returns hi; otherwise returns v.
void Colour::clamp(float _min, float _max)
{
  auto clamp=[](float _v,float _min,float _max)
  {
  return (_v < _min) ? _min : (_max < _v) ? _max : _v;
  };

  m_r=clamp(m_r,_min,_max);
  m_g=clamp(m_g,_min,_max);
  m_b=clamp(m_b,_min,_max);
  m_a=clamp(m_a,_min,_max);

}