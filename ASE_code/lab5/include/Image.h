#ifndef IMAGE_H
#define IMAGE_H
#include<cstddef>
#include<memory>
#include"RGBA.h"
#include<string_view>//an object you can look at,and it has certain semantics which make it quick to copy and to look at.

class Image
{
public:
    
    Image()=default; //default constructor
    Image(size_t _w, size_t _h);
    Image(size_t _w, size_t _h, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a = 255);
    size_t getWidth() const; //to guarantee width is read only 
    size_t getHeight() const; //accessors
    RGBA getPixel(size_t _x, size_t _y) const;
    RGBA setPixel(size_t _x, size_t _y,unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a = 255) const;
    bool save(std::string_view _fname) const;
    void clear(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a = 255);

private:
    size_t m_width=0;
    size_t m_height=0;
    std::unique_ptr<RGBA []> m_pixels;
};

#endif 