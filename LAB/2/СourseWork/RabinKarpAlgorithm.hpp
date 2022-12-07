#pragma once

#include <iostream>
#include <string>

// #define Q 256
// #define B 13


class RabinKarpAlgorithm{
private:
    int Q;
    int B;
public:
    RabinKarpAlgorithm(int b, int q);
    bool check(std:: string& text, std::string& pattern, int startIndex);
    size_t getHash(std::string text, size_t len);
    size_t searchPattern(std::string text, std::string pattern);
};

std::string fromFileToString(std::string path);
