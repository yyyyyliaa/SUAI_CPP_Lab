#include "engine.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


int main(){

    string pattern;
    cout<<"Enter search pattern: ";
    cin>>pattern;

    string text = fromFileToString("text.txt");

    engine karp;
   
    cout<<karp.searchPattern(text, pattern)<<endl;

}