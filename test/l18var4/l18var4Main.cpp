#include <iostream>  

#include "l18var4.hpp"

using namespace std;

int main(){
    LfuCashe test(3);

    test.find_and_add("ABC");
    test.find_and_add("AA");
    test.find_and_add("ABAA");

    cout<<test<<endl;

    test.find("AA");
    test.find("AA");
    test.find("AA");
    test.find("AA");
    
    test.find("ABAA");
    test.find("ABAA");
    test.find("ABAA");
    test.find("ABAA");
    test.find("ABAA");

    cout<<test<<endl;

    test.find_and_add("BBB");


    

    cout<<test<<endl;

    return 0;
}