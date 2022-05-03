#include <iostream>
#include "lib.h"

using namespace std;

int main(){
    int a, b, c;
    cout<<"Enter a:";
    cin>>a;
    cout<<"Enter b:";
    cin>>b;

    c = summa(a, b);
    cout<<c<<endl;

    return 0;
}