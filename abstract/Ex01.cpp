#include <iostream>

class AbstractNumber
{
  public : 
    AbstractNumber(int _v) : m_v{_v}{}
    ~AbstractNumber()=default;
    //when a function set to virtual and equals to 0, it's pure virtual method
    //it does't exit in this class and never exit in this class
    virtual void printValue() const = 0;

  private :
    int m_v;
};

int main()
{
    //not allowed to construct an object, Abstract print value is a pure virtual function
  AbstractNumber n(100);
}