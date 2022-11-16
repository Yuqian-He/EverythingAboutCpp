#include <iostream>

template<class T>
class Person
{
    public:
        Person(T _id, T _age)
        {
            mAge=_age;
            mId=_id;
        }

        void Show()
        {
            std::cout<<"ID"<<mId<<"Age"<<mAge<<'\n';
        }

        T mId;
        T mAge;
};

//if you want to inherited class, you much specified it's type, cuz compiler will allocate memory
class SubPerson : public Person<int>
{

};

//when use it
void test()
{
    Person<int>p(10,20);
    p.Show();
}

int main()
{
    test();
    return EXIT_SUCCESS;
}

//if write sepretaly, the call file should be .hpp not .cpp