#include <gtest/gtest.h>
#include "Particle.h"
#include "Emitter.h"

TEST(Particle,ctor)
{
  Particle p;
  EXPECT_FLOAT_EQ(p.position.x, 0.0f);
  EXPECT_FLOAT_EQ(p.position.y, 0.0f);
  EXPECT_FLOAT_EQ(p.position.z, 0.0f);

  EXPECT_FLOAT_EQ(p.colour.x, 0.0f);
  EXPECT_FLOAT_EQ(p.colour.y, 0.0f);
  EXPECT_FLOAT_EQ(p.colour.z, 0.0f);

  EXPECT_FLOAT_EQ(p.direction.x, 0.0f);
  EXPECT_FLOAT_EQ(p.direction.y, 1.0f);
  EXPECT_FLOAT_EQ(p.direction.z, 0.0f);
}

TEST(Emitter,ctor)
{
  Emitter e(100);
  EXPECT_EQ(e.getNumParticles(),100);
}

TEST(Vec3,operatorMultScalar)
{
  Vec3 a(1,2,3);
  Vec3 b=a*2;
  EXPECT_FLOAT_EQ(b.x,2);
  EXPECT_FLOAT_EQ(b.y,4);
  EXPECT_FLOAT_EQ(b.z,6);
}

TEST(Vec3, addVec3Vec3)
{
  Vec3 a(1,2,3);
  Vec3 b(4,5,6);
  auto c=a+b;
  EXPECT_FLOAT_EQ(c.x, 5.0f);
  EXPECT_FLOAT_EQ(c.y, 7.0f);
  EXPECT_FLOAT_EQ(c.z, 9.0f);
}

TEST(Vec3, plusEqual)
{
  Vec3 a(1,2,3);
  Vec3 b(4,5,6);
  a+=b;
  EXPECT_FLOAT_EQ(a.x, 5.0f);
  EXPECT_FLOAT_EQ(a.y, 7.0f);
  EXPECT_FLOAT_EQ(a.z, 9.0f);
}