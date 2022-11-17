#include <iostream>

int foo(int n){
    if(n<=0) return 1;
    else return (foo(n/2)+foo(n-2));
}

int main(){
    std::cout<<foo(7);
}