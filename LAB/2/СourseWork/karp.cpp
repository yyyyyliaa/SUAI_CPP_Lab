#include "engine.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


int main(){

    string pattern = "He said";
    string text;
    string tmp;

    ifstream in("text.txt");
    if (in.is_open()){
        while (!in.eof()){
            getline(in, text, '\0');
            // text+=tmp;
        }
        // while(in){
        //     in>>tmp;
        //     text+=tmp;
        // }
    }
    in.close();

    engine karp;
    // cout<<karp.getHash(pattern)<<endl;
    cout<<karp.searchPattern(text, pattern)<<endl;

}