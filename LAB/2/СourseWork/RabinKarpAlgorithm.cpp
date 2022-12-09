#include "RabinKarpAlgorithm.hpp"

#include <fstream>
#include <cmath>

using namespace std;


RabinKarpAlgorithm::RabinKarpAlgorithm(int q, int b){
    B = b;
    Q = q;
}


bool RabinKarpAlgorithm::check(std:: string& text, std::string& pattern, int startIndex){
    for(int i = 0; i<pattern.size(); i++){
        if(text[startIndex+i]!=pattern[i]) 
            return false;
    }
    // if(text[startIndex+pattern.size()]==' ' || text[startIndex+pattern.size()]=='\n') return true;
    // else return false;
    return true;
}


size_t RabinKarpAlgorithm::getHash(string text, size_t len){
    size_t result = 0;
    for(int i = 0; i<len; i++){
        result = (B*result+text[i])%Q;
    }
    return result;
}

void RabinKarpAlgorithm::printResult(size_t indexStart, string text){
    size_t countSpaces = 10;
    size_t tmp = indexStart;
    while(countSpaces!=0 && tmp<text.length()){
        if(text[tmp] == ' ') countSpaces--;
        tmp++;
    }
    cout << "Pattern is found at position: " << indexStart  << endl;
    cout<<"...";
    for(size_t j = indexStart; j<tmp; j++) 
        cout<<text[j];
    cout<<"..."<<endl;
    cout<<endl;
}

size_t RabinKarpAlgorithm::searchPattern(string text, string pattern){
    size_t lenText = text.size();
    size_t lenPattern = pattern.size();

    if (lenPattern>lenText) return 0;

    size_t h = 1;
    for(int i = 0; i<lenPattern-1; i++){
        h = (h*B) % Q;
    }

    int patternHash = getHash(pattern, pattern.size());
    int textHash = getHash(text, pattern.size());

    size_t count = 0;

    for(int i = 0; i<lenText-lenPattern+1; i++){
        if ((patternHash == textHash)&&(check(text, pattern, i))){ 
            count++;
            printResult(i, text);
        }
        if(i<lenText-lenPattern){
            textHash = ((textHash-text[i]*h)*B+text[i+lenPattern])%Q;
            if(textHash<0) 
                textHash += Q;
        }
    }
    cout<<"Found pattern:";
    return count;
}


string fromFileToString(string path){
    string text;
    ifstream in(path);
    if (in.is_open()){
        while (!in.eof()){
            getline(in, text, '\0');
        }
    }
    in.close();
    return text;
}