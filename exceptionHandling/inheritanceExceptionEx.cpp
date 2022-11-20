#include<iostream>

void copy_str(char* target, char* source)
{
    if(target == NULL)
    {
        std::cout<<"target is NULL"<<'\n';
    }
    if(source == NULL)
    {
        std::cout<<"source is NULL"<<'\n';
    }
}


int main()
{
    char* source = "asdfg";
    char buf[1024];
    return EXIT_SUCCESS;
}