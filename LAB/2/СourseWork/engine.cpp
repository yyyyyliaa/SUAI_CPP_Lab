
#include "engine.hpp"
#include <iostream>
#include <string>

using namespace std;


void engine::setB(int b){
    B = b;
}

bool engine::check(std:: string& text, std::string& pattern, int startIndex){
    // if((text.size()-startIndex)!=pattern.size()) return false;
    
    for(int i = 0; i<pattern.size(); i++){
        if(text[startIndex+i]!=pattern[i]) 
            return false;
    }

    return true;
}

size_t engine::getHash(string text, size_t len){
    // size_t len = text.size();
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
            cout << "Pattern is found at position: " << i  << endl;
        }
        if(i<lenText-lenPattern){
            textHash = ((textHash-text[i]*multiplier)*B+text[i+lenPattern])%Q;

            if(textHash<0) textHash+=Q;
        }
    }

    return count;
}