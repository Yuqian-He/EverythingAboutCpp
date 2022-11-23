#include <iostream>


int main(){

    int *p = new int[7];

    p[0]= {1};

    //std::cout<<"a = "<<sizeof(a)<<"\n";
    std::cout<<"p = "<<p<<"\n";
    std::cout<<"*p = "<<*p<<"\n";


    return 0;
}