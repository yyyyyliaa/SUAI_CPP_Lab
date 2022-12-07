#include "RabinKarpAlgorithm.hpp"

using namespace std;


int main(){

    string pattern;
    cout<<"Enter search pattern: ";
    cin>>pattern;

    string text = fromFileToString("text.txt");

    RabinKarpAlgorithm karp(13, 256);
   
    cout<<karp.searchPattern(text, pattern)<<endl;

}