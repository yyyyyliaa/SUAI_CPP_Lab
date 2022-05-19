/*Создайте класс IntSet (множество целых) с операциями +, +=, -, -=, =, ==, !=, >, <, >=, <=, *, 
+ (int) (добавить в множество), - (int) (исключения из множества). */
#include <vector>
#include <iostream>

using namespace std;

class IntSet{

private:
    vector <int> set;

public:
    void pushBack(int x);

    bool operator == (IntSet& d2);
    bool operator != (IntSet& d2);
    bool operator > (IntSet& d2);
    bool operator < (IntSet& d2);
    bool operator >= (IntSet& d2);
    bool operator <= (IntSet& d2);

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