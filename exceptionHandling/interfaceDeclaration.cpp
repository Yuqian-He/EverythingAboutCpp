#include<iostream>

//this function can only throw exception of int,float,char 
void func01() throw(int, float, char)
{
    throw 2;
}

//cannot throw any exception
void func02() throw()
{
    throw -1;
}

//can throw any exception
void func03()
{

}

int main()
{
    try{
        func01();
    }
    catch(char* str)
    {
        std::cout<<str<<'\n';
    }
    catch(int e)
    {
        std::cout<<e<<'\n';
    }
    catch(...)
    {
        std::cout<<"capture all the exception"<<'\n';
    }

    return EXIT_SUCCESS;
}