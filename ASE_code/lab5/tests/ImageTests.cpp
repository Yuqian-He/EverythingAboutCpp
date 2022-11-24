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

TEST(Image,clear)
{
    auto a=Image(100,100,255,255,255,0);
    a.save("clear.tiff");
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

TEST(Image,greenHorizontal)
{
    auto a=Image(100,100,255,255,255);
    EXPECT_TRUE(a.save("beforegreen.tiff"));
    for(int i = 0; i<a.getHeight(); i++)
    {
        auto pixel=a.setPixel(a.getWidth()/2,i,0,255,0,255);
    }
    EXPECT_TRUE(a.save("greenHorizontal.tiff"));

    for(size_t y=0; y<100; y++)
    {
        for(size_t x=0; x<100; x++)
        {
            auto p = a.getPixel(x,y);
            if(x != 50){
                ASSERT_EQ(p.r, 255);
                ASSERT_EQ(p.g, 255);
                ASSERT_EQ(p.b, 255);
                ASSERT_EQ(p.a, 255);
             }
             else{
                ASSERT_EQ(p.r, 0);
                ASSERT_EQ(p.g, 255);
                ASSERT_EQ(p.b, 0);
                ASSERT_EQ(p.a, 255);
             }
        }
    }
    
}

TEST(Image,blueVertical)
{
    auto a=Image(512,512,255,255,255);
    EXPECT_TRUE(a.save("beforeRed.tiff"));
    for(int i = 0; i<a.getWidth(); i++)
    {
        auto pixel=a.setPixel(i,a.getWidth()/2,0,0,255,255);
    }
    EXPECT_TRUE(a.save("blueVertical.tiff"));
    
}


TEST(Image,save)
{
    {
        auto a=Image(512,512,255,0,0,255);
        EXPECT_TRUE(a.save("red.tiff"));
    }
    {
        auto a=Image(512,512,0,255,0,255);
        EXPECT_TRUE(a.save("green.tiff"));
    }
    {
        auto a=Image(512,512,0,0,255,255);
        EXPECT_TRUE(a.save("blue.tiff"));
    }

}


