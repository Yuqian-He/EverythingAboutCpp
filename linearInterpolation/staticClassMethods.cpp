int value()
{
    static int v = 0;
    return ++v;
}

//every time I call value(), I get a different number.
//because static v stores outside.

static Colour mix(const Colour &_a, const Colour &_b, float _t);

Colour Colour::mix(const Colour &_a, const Colour &_b, float _t)
{
  Colour ret;
  ret.m_r=_a.m_r+(_b.m_r-_a.m_r)*_t;
  ret.m_g=_a.m_g+(_b.m_g-_a.m_g)*_t;
  ret.m_b=_a.m_b+(_b.m_b-_a.m_b)*_t;
  ret.m_a=_a.m_a+(_b.m_a-_a.m_a)*_t;
  return ret;
}

//this static method can be called without an instance of the class

//when to use this class
TEST(Colour,mixStatic)
{
  Colour a(0.0f,0.0f,0.0f,0.0f);
  Colour b(1.0f,1.0f,1.0f,1.0f);
  Colour res;
  for(float t=0.0f; t<=1.0f; t+=0.1f)
  {
    res=Colour::mix(a,b,t);//just use it without an instance
    EXPECT_FLOAT_EQ(res.red(),t);
    EXPECT_FLOAT_EQ(res.green(),t);
    EXPECT_FLOAT_EQ(res.blue(),t);
    EXPECT_FLOAT_EQ(res.alpha(),t);
  }
}