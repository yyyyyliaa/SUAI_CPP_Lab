
#include "engine.hpp"

#include <fstream>

using namespace std;


void engine::setB(int b){
    B = b;
}

bool engine::check(std:: string& text, std::string& pattern, int startIndex){
    for(int i = 0; i<pattern.size(); i++){
        if(text[startIndex+i]!=pattern[i]) 
            return false;
    }
    if(text[startIndex+pattern.size()]==' ') return true;
    else return false;
}

size_t engine::getHash(string text, size_t len){
    size_t result = 0;
    for(int i = 0; i<len; i++){
        result = (B*result+text[i])%Q;
    }
    return result;
}

size_t engine::searchPattern(string text, string pattern){
    size_t lenText = text.size();
    size_t lenPattern = pattern.size();

    if (lenPattern>lenText) return 0;

    size_t multiplier = 1;
    for(int i = 0; i<lenPattern-1; i++){
        multiplier = (multiplier*B) % Q;
    }

    int patternHash = getHash(pattern, pattern.size());
    int textHash = getHash(text, pattern.size());

    size_t count = 0;

    for(int i = 0; i<lenText-lenPattern+1; i++){
        if ((patternHash == textHash)&&(check(text, pattern, i))){ 
            count++;
            size_t countSpaces = 10;
            size_t tmp = i;
            while(countSpaces!=0){
                if(text[tmp] != ' ') tmp++;
                else {
                    countSpaces--;
                    tmp++;
                }
            }
            cout << "Pattern is found at position: " << i  << endl;
            cout<<"...";
            for(size_t j = i; j!=tmp; j++){
                cout<<text[j];
            }
            cout<<"..."<<endl;
            cout<<endl;
        }
        if(i<lenText-lenPattern){
            textHash = ((textHash-text[i]*multiplier)*B+text[i+lenPattern])%Q;
            if(textHash<0) textHash+=Q;
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