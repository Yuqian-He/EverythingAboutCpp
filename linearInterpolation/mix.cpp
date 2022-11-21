
//easy way to get different color with constant speed
void Colour::mix(const Colour &_in, float _t)
{
  assert(_t>=0.0f && _t <= 1.0f);
  m_r=m_r+(_in.m_r-m_r)*_t;
  m_g=m_g+(_in.m_g-m_g)*_t;
  m_b=m_b+(_in.m_b-m_b)*_t;
  m_a=m_a+(_in.m_a-m_a)*_t;
}