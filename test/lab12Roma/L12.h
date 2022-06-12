#pragma once

#include <iostream>

class IntSet {

private:

    int p_size = 0;

    int* p_set;


public:
    ~IntSet();

    IntSet();

    IntSet(int* set, int size);

    void setNumbers(int* set, int size);

    int check(int num);

    void addNumber(int num);

    void delNumber(int num);

    void unitSets(IntSet set);

    void subSets(IntSet set);

    void printSet();
    
    void unitmas(IntSet* mas, int size);
};