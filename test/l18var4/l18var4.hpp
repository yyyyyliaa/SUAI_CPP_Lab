#pragma once

#include <iostream>    
#include <string> 
#include <map>


class LfuCashe{
    private:
        size_t size;
        size_t count;
        size_t min;
        std::map <std::string, int> cashe;

    public:
        LfuCashe(size_t size);

        bool find_and_add(const std::string &adress);
        bool find(const std::string &address);

        int findMin();
	    int getMin();

        std::map<std::string, int>::iterator find_value(const int value);

        friend std::ostream& operator<<(std::ostream& os, LfuCashe& c);
};

