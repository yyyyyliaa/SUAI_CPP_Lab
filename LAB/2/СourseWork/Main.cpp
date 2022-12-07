#include "RabinKarpAlgorithm.hpp"

using namespace std;

int main(int argc, char const *argv[]){
    string text = fromFileToString("text.txt");

    RabinKarpAlgorithm karp(13, 256);

    string pattern = argv[1];

    cout<<pattern;
   
    cout<<karp.searchPattern(text, pattern)<<endl;
    
    return 0;
}



// int main(){

//     string pattern;
//     cout<<"Enter search pattern: ";
//     cin>>pattern;

//     string text = fromFileToString("text.txt");

//     RabinKarpAlgorithm karp(13, 256);
   
//     cout<<karp.searchPattern(text, pattern)<<endl;

// }