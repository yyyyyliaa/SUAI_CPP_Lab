#include "l17.h"
#include <iostream>

using namespace std;

int main(){

    set<string> set2;
    set2.insert("AAA");
    set2.insert("BBBB");
    set2.insert("BB");
    set2.insert("CCCC");
    set2.insert("CCCC");
    set2.insert("C");

    cout<<set2<<endl;

    return 0;
}