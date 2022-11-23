#include<iostream>
#include<cstdlib>
#include"external.h"

int main(){
    int data = 5;
    int data1 = foo1(data);
    int data2 = foo2(data);

    std::cout<<data<<data1<<data2<<"\n";

    return EXIT_SUCCESS;
}