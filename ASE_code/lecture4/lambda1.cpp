#include <iostream>
#include <string_view>

void print(std::string_view str){
    std::cout<<str<<"\n";
}

int main(){

    //capture any variable that declared before it 
    //and put in scoape the function so that it can be modifine.

    //second backet is prema list 
    //thrid is the body
    auto print =[](std::string_view str)
    {
        std::cout<<str<<"\n";
    };

    print("hello this");
}