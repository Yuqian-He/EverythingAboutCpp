#include<iostream>
#include<stdexcept>
#include <string.h>
using namespace std;


class Person
{

public:
    int mAge;
    Person()
    {
        mAge = 0;
    }
    void setAge(int age)
    {
        if(age<0||age>100)
        {
            throw out_of_range("age range(0,100)"); //use out_of_range
        }
        mAge=age;
    }

};

void test01()
{
    Person p;
    try
    {
        p.setAge(10000);
    }
    catch(out_of_range e)
    {
        cout<<e.what()<<'\n';
    }
}


//1.inheritance exception
//2.overload function what and virtual destructor

class MyOutOfRange : public exception
{
    public:
    char* pError;

    //constructor
    MyOutOfRange(char* error)
    {
        pError=new char[strlen(error)+1];
        strcpy(pError,error);
    }

    //destructor
    ~MyOutOfRange()
    {
        if(pError!=NULL)
        {
            delete[] pError;
        }
    }

    virtual const char* what() const throw()
    {
        return pError;
    }
};

void fun03()
{
    throw MyOutOfRange("xxxxx");
}

void test03()
{
    try
    {
        fun03();
    }
    catch(MyOutOfRange e)
    {
        std::cout<<e.what()<<'\n';
    }
    
}

int main()
{

    test03();
    return EXIT_SUCCESS;
}