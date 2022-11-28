#include <iostream>  

#include "LFUcashe.hpp"

using namespace std;

int main(){
    LfuCashe test(3);


    test.find_and_add("AA");
    test.find_and_add("ABC");
    test.find_and_add("ABAA");

    cout<<test<<endl;

    test.apply("AA");
    test.apply("AA");
    test.apply("AA");
    test.apply("AA");

    
    test.apply("ABAA");

    test.apply("ABC");

    cout<<test<<endl;

    test.find_and_add("BBB");

    cout<<test<<endl;

    return 0;
}