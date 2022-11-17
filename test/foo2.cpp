#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> v){
    int result = 0;
    for(int i = 0; i<v.size(); i++){
        result+=v[i];
    }
    return result;
}

bool check(vector<int> v, int n){
    for(int i = 0; i<v.size(); i++){
        if (n==v[i]) return false;
    }
    return true;
}

void foo(int S, vector<int> result, int position){
    if(sum(result)==S){
        for(int i = 0; i<result.size(); i++){
            cout<< result[i]<< " ";
        }
    }
    else{
        for (int i = 0; i < S; i++){
            if(check(result, i) && sum(result)+i<S){
                result.push_back(i);
                foo(S, result, position+1);
            }
            else continue;
        }
    }

}

int main(){
    vector<int> result;
    foo(18, result, 0);

    return 0;
}