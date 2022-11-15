#include<iostream>

//type int function of swap
void MySwap(int& _a, int& _b)
{
    int temp = _a;
    _a = _b;
    _b = temp;
}

//type double function of swap
void MySwap(double& _a, double& _b)
{
    int temp = _a;
    _a = _b;
    _b = temp;
}

//when use template, can ignore the different type
template<class T> // template<typename T>   
void MySwap01(T& _a, T& _b)
{
    T temp = _a;
    _a = _b;
    _b = temp;
}

//how to use it
void test01()
{
    float a = 10.34;
    float b = 38.478;
    MySwap01<float>(a,b); // use like that
    std::cout<<b<<'\n';
}

int main()
{
    test01();
    return EXIT_SUCCESS;
}

//cpp compiler give priority to normal function