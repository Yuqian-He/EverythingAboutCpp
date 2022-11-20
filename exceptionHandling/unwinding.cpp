#include<iostream>

class Person
{
    public:
    Person(){std::cout<<"constructe instance"<<'\n';}
    ~Person(){std::cout<<"destructe instance"<<'\n';}
};

int divide(int x,int y)
{
    Person p1,p2;

    if(y==0)
    {
        throw y;
    }
    return x/y;
}

//when a function throw a exception, all of the constructor will be deconstruct.
void test01()
{
    try
    {
        divide(10,0);
    }
    catch(int e)
    {
        std::cout<<"capture exception"<<'\n';
    }
    
}

int main()
{
    test01();
    return EXIT_SUCCESS;
}