#include<iostream>

int divide(int x, int y)
{
    if(y == 0)
    {
        throw y; //throw exception
    }

    return x/y;
}

void callDivide(int x, int y)
{
    divide(x,y);
}

void test02()
{
    try
    {
        callDivide(10,0);
        
    }
    catch(int e)
    {
        std::cout<<"catch exception successfully"<<e<<'\n';
    }
    
}

void test01()
{
    //capture exception
    try
    {
        divide(10,0);
    }
    catch (int e)
    {
        std::cout<<"catch exception successfully"<<e<<'\n';
    }
}

int main()
{
    test02();
    test01();
    return EXIT_SUCCESS;
}