#include<gtest/gtest.h>
#include"Image.h"


TEST(Image,ctor)
{
    auto a=Image();
    ASSERT_EQ(a.getWidth(),0);
    ASSERT_EQ(a.getHeight(),0);
}

TEST(Image,userCtor)
{
    auto a = Image(1024,512);
    ASSERT_EQ(a.getWidth(),1024);
    ASSERT_EQ(a.getHeight(),512);
}

TEST(Image, userCtorRGB)
{
    auto a=Image(100,100,255,0,0);
    ASSERT_EQ(a.getWidth(),100);
    ASSERT_EQ(a.getHeight(),100);
    auto pixel=a.getPixel(0,0);
    ASSERT_EQ(pixel.r,255);
    ASSERT_EQ(pixel.g,0);
    ASSERT_EQ(pixel.b,0);
    ASSERT_EQ(pixel.a,255);

}

/*
TEST(Image,copy)
{
    auto a=Image(100,100);
    auto b=a; //the copy constructor in make_uniqye is deleted
    //smart_pointer is uncopyable
    ASSERT_EQ(a.getWidth(),100);
    ASSERT_EQ(a.getHeight(),100);
    ASSERT_EQ(b.getWidth(),100);
    ASSERT_EQ(b.getHeight(),100);

}
*/

TEST(Image,save)
{
    auto a=Image(512,512,255,0,255,255);
    EXPECT_TRUE(a.save("test.tiff"));
}