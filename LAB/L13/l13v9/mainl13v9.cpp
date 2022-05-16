/*Создайте класс IntSet (множество целых) с операциями +, +=, -, -=, =, ==, !=, >, <, >=, <=, *, 
+ (int) (добавить в множество), - (int) (исключения из множества). */
#include <iostream>
#include <algorithm>
#include "l13v9.h"

using namespace std;

int main(){
    IntSet set1, set2, set3;

    set1+=1;
    set2+=2;
    set2+=4;

    cout<<set1<<endl;
    cout<<set2<<endl;

    set3=set1+set2;
    cout<<set3<<endl;

    set1 = set1*set2;
    cout<<set1<<endl;

    cout<<(set1!=set2)<<endl;

    set3 = set1 + set2;
    cout<<set3<<endl;

    set2-=4;
    cout<<set2<<endl;

    set3 = set1-set2;
    cout<<set3<<endl;

    cout<<(set1>set2)<<endl;
    cout<<(set1>set2)<<endl;
    cout<<(set1>=set2)<<endl;
    cout<<(set1<=set2)<<endl;


    
    return 0;
}