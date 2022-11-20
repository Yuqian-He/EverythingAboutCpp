#include<iostream>

class Building{};
class Animal{};
class Cat:public Animal{};

//static_cast
void test01()
{
    int a = 99;
    char c = static_cast<char>(a);
    std::cout<<c<<'\n';

    //pointer conversion cannot use
    //int* p = NULL;
    //char* sp = static_cast<char*>(p);

    //object pointer conversion cannot use
    //Building* building = NULL;
    //Animal* ani = static_cast<Animal*>(building);

    //object pointer conversion which has inheritance relation
    Animal* ani = NULL;
    Cat* cat = static_cast<Cat*>(ani);

    Cat* catSon = NULL;
    Animal* aniFather = static_cast<Animal*>(catSon);

    //reference of objecte who has inheritance relation can converse
    Animal aniobj;
    Animal& aniref = aniobj;
    Cat& cat_ = static_cast<Cat&>(aniref);

    Cat catobj;
    Cat& catref = catobj;
    Animal& ani_ = static_cast<Animal&>(catref);

    //A pointer in C++ is a variable that holds the memory address of another variable.
    //A reference is an alias for an already existing variable. Once a reference is initialized to a variable, it cannot be changed to refer to another variable.
}

//dynamic_cast
void test02()
{
    //basic type cannot converse 
    //int a = 10;
    //char c = dynamic_cast<char>(a);

    //no-inheritance cannot use
    //Animal* ani = NULL;
    //Building* building = dynamic_cast<Building*>(ani);

    //inheritance
    //Animal* ani = NULL;
    //Cat* cat = dynamic_cast<Cat*>(ani);
    //dynamic sercurity check, subpointer can converse to fatherPointer but fatherPointer cannot converse to subPointer

    //subPointer to fatherPointer
    Cat* cat = NULL;
    Animal* ani = dynamic_cast<Animal*>(cat);

    //dynamic_cast only can be used in inheritance class and only from sub to father

}

//const_cast
void test03()
{
    //basic type change const& to &
    int a = 10;
    const int& b = a;
    int& c = const_cast<int&>(b);

    //pointer
    const int* p = NULL;
    int* p2 = const_cast<int*>(p);

    int*q = NULL;
    const int*d = const_cast<const int*>(q);

    //add or remove const
}

//reinterpret_cast
//A cast is a special operator that forces one data type to be converted into another.
typedef void(*FUNC1)(int,int);
typedef int(*FUNC2)(int, char*);
void test04 ()
{
    //can converse anything
    Building* building = NULL;
    Animal* ani = reinterpret_cast<Animal*>(building);

    //function pointer
    FUNC1 func1;
    FUNC2 func2 = reinterpret_cast<FUNC2>(func1);

}

int main()
{
    test01();
    return EXIT_SUCCESS;
}