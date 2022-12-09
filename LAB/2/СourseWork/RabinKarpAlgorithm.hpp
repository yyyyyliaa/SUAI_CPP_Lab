#pragma once

#include <iostream>
#include <string>


class RabinKarpAlgorithm{
private:
    int Q;
    int B;
public:
    RabinKarpAlgorithm (int q, int b);
    bool check(std:: string& text, std::string& pattern, int startIndex);
    size_t getHash(std::string text, size_t len);
    size_t searchPattern(std::string text, std::string pattern);
    void printResult(size_t indexStart, std::string text);
};

std::string fromFileToString(std::string path);
