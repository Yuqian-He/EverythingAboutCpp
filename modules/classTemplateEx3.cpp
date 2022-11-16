#include<iostream>
#include<string.h>

template<class T1, class T2>
class Person
{
    public:
        T1 mName;
        T2 mAge;
        Person(T1 name, T2 age); //when use tempalte and want to implement outside the class
        void Show();
};

//if you want to call this function outside class, you should add template and <T1,T2>
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    mName=name;
    mAge=age;
}

template<class T1,class T2>
void Person<T1,T2>::Show()
{
    std::cout<<mName<<mAge<<'\n';
}

void test()
{
    Person<std::string,int>p("aaa",10);
    p.Show();
}

int main()
{
    test();
    return EXIT_SUCCESS;
}