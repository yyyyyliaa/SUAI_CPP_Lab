/*Создайте класс IntSet (множество целых) с операциями +, +=, -, -=, =, ==, !=, >, <, >=, <=, *, 
+ (int) (добавить в множество), - (int) (исключения из множества). */

#include <iostream>
#include <algorithm>
#include "l13v9.h"

using namespace std;

bool IntSet::operator== (IntSet& d2){
    if (this->set.size()!=d2.set.size()) return 0;
    else{
        for (int i = 0; i < this->set.size(); i++) {
            if (find(d2.set.begin(), d2.set.end(), this->set[i])==d2.set.end())
                return 0;
        }
    }
    return 1;
}

bool IntSet::operator!= (IntSet& d2){
    return !(*this==d2);
}

bool IntSet::operator > (IntSet& d2){
    return this->set.size()>d2.set.size();
}

bool IntSet::operator < (IntSet& d2){
    return this->set.size()<d2.set.size();
}

bool IntSet::operator >= (IntSet& d2){
    return this->set.size()>=d2.set.size();
}

bool IntSet::operator <= (IntSet& d2){
    return this->set.size()<=d2.set.size();
}

IntSet IntSet::operator+(int x){
    IntSet ret = *this;
    if (find(set.begin(), set.end(), x)==set.end())

        ret.set.push_back(x);

    return ret;
}
IntSet IntSet::operator+(IntSet d){
    IntSet ret = *this;
    for (int i = 0; i<d.set.size(); i++){
        if (find(this->set.begin(), this->set.end(), d.set[i])==this->set.end()) ret.set.push_back(d.set[i]);
    }
    return ret;
}

IntSet IntSet::operator-(int x){
    IntSet ret = *this;
    ret.set.erase(remove(ret.set.begin(), ret.set.end(), x), ret.set.end());

    return ret;
}
IntSet IntSet::operator-(IntSet d){
    IntSet ret = *this;
    for (int i = 0; i<d.set.size(); i++){
        if (find(this->set.begin(), this->set.end(), d.set[i])!=this->set.end()) 
            ret.set.erase(remove(ret.set.begin(), ret.set.end(), d.set[i]), ret.set.end());
    }
    return ret;
}

IntSet& IntSet::operator+=(const IntSet& d){
    for (int i = 0; i<d.set.size(); i++){
        if (find(this->set.begin(), this->set.end(), d.set[i])==set.end()) this->set.push_back(d.set[i]);
    }
    return *this;
}
IntSet& IntSet::operator+=(int x){
    if (find(set.begin(), set.end(), x)==set.end()) this->set.push_back(x);
    
    return *this;
}

IntSet& IntSet::operator-=(const IntSet& d){
    for (int i = 0; i<d.set.size(); i++){
        this->set.erase(remove(this->set.begin(), this->set.end(), d.set[i]), this->set.end());
    }
    return *this;
}
IntSet& IntSet::operator-=(int x){
    this->set.erase(remove(this->set.begin(), this->set.end(), x), this->set.end());
    return *this;
}

IntSet IntSet::operator*(IntSet d){
    IntSet ret;
    for (int i = 0; i<d.set.size(); i++){
        if (find(this->set.begin(), this->set.end(), d.set[i])!=this->set.end()) ret.set.push_back(d.set[i]);
    }
    return ret;
}

ostream& operator<< (ostream& os, const IntSet& set) {
    os << "{ ";
    for (int i = 0; i< set.set.size(); i++) os<<set.set[i]<<", ";
    os<<"}"<<endl;
    return os;
}




// istream& operator >>(istream& is, Date& d) {
//     is >> d.days;
//     return is;
// }

// void IntSet::pushBack(int n){
//     if (find(set.begin(), set.end(), n)==set.end())
//         this->set.push_back(n);
// }

