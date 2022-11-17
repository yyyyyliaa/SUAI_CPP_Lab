#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b){
    int* tmp = a;
    a = b;
    b = tmp;
}

void foo(vector<int> v, int pos, int n){
    if(pos==n-1){
        for(int i = 0; i<v.size(); i++){
            cout<<v[i]<< " ";
        }
        cout<<endl;
    } else {
        for(int i = pos; i<n; i++){
            swap(v[i], v[pos]);
            foo(v, pos+1, n);
            swap(v[i], v[pos]);
        }

   }
}

int main(){
    int n = 3;
    vector<int> result;
    for (int i = 0; i<n; i++){
        result.push_back(i+1);
    }
    foo(result, 0, n);
}