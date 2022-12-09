#include "RabinKarpAlgorithm.hpp"

#define Q 1e9 + 7
#define B 256

using namespace std;

int main(int argc, char const *argv[]){

    string filePath = argv[1];
    string text = fromFileToString(filePath);

    RabinKarpAlgorithm karp(B, Q);

    cout<<"Enter search pattern: ";
    string pattern;
    cin>>pattern;
   
    cout<<karp.searchPattern(text, pattern)<<endl;
    
    return 0;
}