#ifndef RGBA_H
#define RGBA_H

#endif

struct RGBA
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

void set(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);
void clamp(unsigned char _min, unsigned char _max);