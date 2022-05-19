/*Создайте класс IntSet (множество целых) с операциями +, +=, -, -=, =, ==, !=, >, <, >=, <=, *, 
+ (int) (добавить в множество), - (int) (исключения из множества). */
#pragma once
#include <vector>
#include <iostream>

using namespace std;

class IntSet{

private:
    vector <int> set;

public:
    // int (*compAbs)(IntSet& , IntSet&) = &compAbsolution;
    // int (*compQuan)(IntSet& , IntSet&) = &compQuanity;
    // int (*compSum)(IntSet& , IntSet&) = &compSumma;

    bool operator== (IntSet& d2);
    bool operator!= (IntSet& d2);
    bool operator> (IntSet& d2);
    bool operator< (IntSet& d2);
    bool operator>= (IntSet& d2);
    bool operator<= (IntSet& d2);

    friend void compare(IntSet& d, IntSet& d1, int (*f)(IntSet&, IntSet& ));
    friend int compQuanity(IntSet& d, IntSet& d1);
    friend int compSumma(IntSet& d, IntSet& d1);
    friend int compAbsolution(IntSet& d, IntSet& d1);

    IntSet operator+(int x);
    IntSet operator+(IntSet d2);

    IntSet operator-(int x);
    IntSet operator-(IntSet d2);

    IntSet& operator+=(int x);
    IntSet& operator+=(const IntSet& d);
    IntSet& operator-=(int x);
    IntSet& operator-=(const IntSet& d);

    IntSet operator*(IntSet d);

    friend ostream& operator <<(ostream& os, const IntSet& d);
    friend istream& operator >>(istream& is, IntSet& d);

};

void compare(IntSet& d, IntSet& d1, int (*f)(IntSet&, IntSet& ));
int compQuanity(IntSet& d, IntSet& d1);
int compSumma(IntSet& d, IntSet& d1);
int compAbsolution(IntSet& d, IntSet& d1);


