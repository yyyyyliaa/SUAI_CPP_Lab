#pragma once

#include <iostream>    
#include <string> 
#include <map>


class LfuCashe{
    private:
        size_t size;
        size_t count = 0;

        std::map <std::string, int> cashe;
        std::multimap<int, std::string> search;

    public:
        LfuCashe(size_t size);

        bool find_and_add(const std::string &adress);
        void apply(const std::string &address);

        std::string findMin();
	    int getMin();

        std::map<std::string, int>::iterator find_value(const int value);

        friend std::ostream& operator<<(std::ostream& os, LfuCashe& c);

        void printSearch();
};

