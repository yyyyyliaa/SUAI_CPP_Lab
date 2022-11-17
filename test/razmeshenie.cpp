#include <iostream>
#include <vector>

using namespace std;

void foo(vector<int> v, int n, int k, int pos, int* used){
    if(pos==k){
        for(int i = 0; i<v.size(); i++){
            cout<<v[i]<< " ";
        }
        cout<<endl;
    } else{
        for(int i = 1; i<=n; i++){
            if(used[i]==0){
                used[i] = 1;
                v.push_back(i);
                foo(v, n, k, pos+1, used);
                used[i] = 0;
                v.pop_back();
            }
        }
    }

}


int main(){
    int n = 5;
    int* used = (int*)malloc(sizeof(int)*(n));
    for(int i = 0; i<n; i++){
        used[i] = 0;
    }
    vector<int> result;
    foo(result, n, 3, 0, used);

    return 0;
}