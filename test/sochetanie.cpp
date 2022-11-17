#include <iostream>
#include <vector>

using namespace std;

void foo(vector<int> v, int n, int k, int pos, int last){
    if(pos==k){
        for(int i = 0; i<v.size(); i++){
            cout<<v[i]<< " ";
        }
        cout<<endl;
    } else{
        for(int i = last+1; i<=n; i++){
            v.push_back(i);
            foo(v, n, k, pos+1, i);
            v.pop_back();
        }
    }
}

int main(){
    vector<int> result;
    foo(result, 3, 2, 0, 0);

    return 0;
}