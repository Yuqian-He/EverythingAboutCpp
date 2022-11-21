//mutator tend to modify the class
void set(float _r, float _g, float _b, float _a=1.0f);
void setRed(float _r);
void setGreen(float _g);
void setBlue(float _b);
void setAlpha(float _a);
//we shouldn't keep it all public, because we should do bound checking