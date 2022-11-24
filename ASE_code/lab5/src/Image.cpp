#include<iostream>
#include"Image.h"
#include<OpenImageIO/imageio.h>
#include<cstring>

Image::Image(size_t _w,size_t _h):m_width{_w},m_height{_h}
{
    m_pixels = std::make_unique<RGBA []>(m_width*m_height); //dynamically allocated memory
}

Image::Image(size_t _w,size_t _h, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a): Image(_w, _h)
{
    //: Image(_w, _h) This is another way to call another base constructor
    //m_pixels = std::make_unique<RGBA []>(m_width*m_height); 
    for(size_t i =0; i<m_width*m_height;++i)
    {
        m_pixels[i]=RGBA(_r,_g,_b,_a);
    }
}

size_t Image::getWidth() const
{
    return m_width;
}

size_t Image::getHeight() const
{
    return m_height;
}

RGBA Image::getPixel(size_t _x, size_t _y) const
{
    return m_pixels[m_width*(_y)+_x];
}

RGBA Image::setPixel(size_t _x, size_t _y,unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) const
{
    m_pixels[m_width*(_y)+_x]=RGBA(_r,_g,_b,_a);
}

bool Image::save(std::string_view _fname) const
{
    bool success=false;
    using namespace OIIO;
    auto out = ImageOutput::create(_fname.data());
    if(!out)
    {
        return false;
    }
    ImageSpec spec(m_width,m_height,4,TypeDesc::UINT8);
    success = out->open(_fname.data(),spec);
    success = out->write_image(TypeDesc::UINT8,m_pixels.get());
    success = out->close();
    return success;
}

void Image::clear(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    auto p=RGBA(_r,_g,_b,_a);
    
    for(size_t i=0; i<m_width*m_height; i++)
    {
        m_pixels[i]=p;
    }       
    
    //memset(&m_pixels[0],p.pixel,sizeof(uint32_t)*m_width*m_height);
}
