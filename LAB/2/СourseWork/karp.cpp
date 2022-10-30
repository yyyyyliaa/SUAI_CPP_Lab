#include "engine.hpp"
#include <string>
#include <iostream>

using namespace std;


int main(){
    string pattern = "loh";
    string text = "loh loh loh";

    engine karp;
    // cout<<karp.getHash(pattern)<<endl;
    cout<<karp.searchPattern(text, pattern)<<endl;

}