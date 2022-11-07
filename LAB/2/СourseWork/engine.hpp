#pragma once

#include <iostream>
#include <string>

class engine{
private:
    int Q = 256;
    int B = 9;
public:
    void setB(int B);
    bool check(std:: string& text, std::string& pattern, int startIndex);
    size_t getHash(std::string text, size_t len);
    size_t searchPattern(std::string text, std::string pattern);
};

std::string fromFileToString(std::string path);
