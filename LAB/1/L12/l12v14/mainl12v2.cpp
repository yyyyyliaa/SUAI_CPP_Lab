/*Создайте класс IntSet для выполнения операций с множеством целых чисел. 
Реализовать операции добавления элемента, удаление элемента, проверку вхождения элемента, 
объединения множеств и вычитания одного множества из другого*/


#include <iostream>
#include "l12sets.h"
using namespace std;

int main(){
    
    int size;
    cout<<"Enter size of set1: ";
    cin>>size;

    int* set = (int*)malloc(sizeof(int)*size);
    
    cout<<"Enter the elements of set1: "<< endl;
    for (int i =0; i<size; i++){
        cin>>set[i];
    }

    IntSet set1(set, size);

    IntSet* mass = (IntSet*)malloc(sizeof(IntSet)*1);

    cout<<"Enter size of set2: ";
    cin>>size;

    set = (int*)realloc(set ,sizeof(int)*size);
    
    cout<<"Enter the elements of set2: "<< endl;
    for (int i =0; i<size; i++){
        cin>>set[i];
    }

    IntSet set2(set, size);

    free(set);
    int n;

    set1.unitSets(set2);
    cout<<"After unite:"<<endl;   
    set1.printSet();
    cout<<endl;

    cout<<"Enter number for del: ";
    cin>>n;
    cout<<"After delete:"<<endl;
    set1.delNumber(n);
    set1.printSet();
    cout<<endl;

    cout<<"Enter number for add: ";
    cin>>n;
    cout<<"After add:"<<endl;
    set1.addNumber(n);
    set1.printSet();
    cout<<endl;

    cout<<"After sub:"<<endl;
    set1.subSets(set2);
    set1.printSet();

    return 0;
}