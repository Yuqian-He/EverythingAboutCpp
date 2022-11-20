#include<iostream>

void func()
{
    throw 1;
}

void func02()
{
    throw "exception";
}

class Myexception02
{
    public:
    char* error;
    Myexception02(char* str)
    {
        error=new char[strlen(str)+1];
        strcpy(error,str);
    }
    void what(){std::cout<<"undefined exception"<<'\n';}
};

//throw class exception
void func03()
{
    throw Myexception02(" ");
}

void test01()
{
    try
    {
        func();
    }
    catch(int e)
    {
        std::cout<<e<<'\n';
    }

    try
    {
        func02();
    }
    catch(char* e)
    {
        std::cout<<e<<'\n';
    }

    try
    {
        func03();
    }
    catch(Myexception02 e)
    {
        e.what();
    }
    
}

int main()
{
    return EXIT_SUCCESS;
}