/*Создайте класс IntSet (множество целых) с операциями +, +=, -, -=, =, ==, !=, >, <, >=, <=, *, 
+ (int) (добавить в множество), - (int) (исключения из множества). */
#include <iostream>
#include <algorithm>
#include "dop13.h"

using namespace std;

int main(){
    IntSet set1, set2, set3;
    
    int (*compAbs)(IntSet& , IntSet&) = &compAbsolution;
    int (*compQuan)(IntSet& , IntSet&) = &compQuanity;
    int (*compSum)(IntSet& , IntSet&) = &compSumma;

    set1+=1;
    set1+=2;
    set1+=4;
    set1+=-10;

    set2+=2;
    set2+=4;
    set2+=1;

    cout<<set1<<endl;
    cout<<set2<<endl;

    cout<<"Compare absolution:";
    compare(set1, set2, compAbs);
    cout<<"Compare quanity:";
    compare(set1, set2, compQuan);
    cout<<"Compare summa:";
    compare(set1, set2, compSum);
    cout<<endl;
    
    return 0;
}