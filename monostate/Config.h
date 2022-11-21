#ifndef CONFIG_H_
#define CONFIG_H_
#include <string>

class Config
{
  public :
    Config(); //constructor
    int getPointSize() const {return m_pointSize;}
    std::string getColour() const {return m_colour;}
    std::string getDrawMode() const {return m_drawMode;}
  private :
  //all prefix with static
    static bool m_configRead;
    static int m_pointSize;
    static std::string m_colour;
    static std::string m_drawMode;
};

//creating a class that has global data because there are static
//the only way we can access data is by calling methods vis interface
//the static data is globle, but we need still an instance of class to access our data

#endif