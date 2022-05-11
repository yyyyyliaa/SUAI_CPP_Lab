
#include <iostream>
#include <algorithm>
#include "dop13.h"

using namespace std;

// int (*compAbs)(IntSet& , IntSet&) = &compAbsolution;
// int (*compQuan)(IntSet& , IntSet&) = &compQuanity;
// int (*compSum)(IntSet& , IntSet&) = &compSumma;


void compare(IntSet& d, IntSet& d1, int (*f)(IntSet& , IntSet&)){
    if (f(d, d1)==1) cout<<"set1==set2"<<endl;
    else if (f(d, d1)==2) cout<<"set1>set2"<<endl;
    else if (f(d, d1)==3) cout<<"set1<set1"<<endl;
    else if (f(d, d1)==0) cout<<"set1!=set2"<<endl;
    else cout<<"set1!=set2"<<endl;
}

int compQuanity(IntSet& d, IntSet& d1){ //сравнение по количеству элементов
    if (d1.set.size()==d.set.size()) return 1;
    else if (d1.set.size()>d.set.size()) return 2;
    else if (d1.set.size()<d.set.size()) return 3;
    else return 0;
}

int compSumma(IntSet& d, IntSet& d1){  //сравнение по сумме
    int sum2 = 0;
    for(int i =0; i< d1.set.size(); i++)
        sum2+=d1.set[i];
    
    int sum1 = 0;
    for (int i = 0; i< d.set.size(); i++)
        sum1+= d.set[i];
    
    if (sum1==sum2) return 1;
    else if (sum1>sum2) return 2;
    else if (sum1<sum2) return 3;
    else return 0;
}

int compAbsolution(IntSet& d, IntSet& d1){ //сравнение по элементам
    int flag = 2;
    if (d.set.size()==d1.set.size()){
        for (int i = 0; i<d1.set.size(); i++){
            if (d.set[i]==d1.set[i]) flag = 1;
            else flag = 0;

            if (flag==0) return 0;
            else continue;
        }
        if (flag==1) return 1;
        else return 0;
    }
    else return 0;
}



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
