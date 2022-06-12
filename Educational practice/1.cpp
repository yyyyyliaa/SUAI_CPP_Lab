#include <iostream>
using namespace std;


int func(int x){
    int w = 0;
    while (x>0){
        w+=x&1;
        x>>=1;
    }
    return w;
}

int main(){
    int x = 10;
    int res = x&1;
    cout<<res;

    return 0;
}