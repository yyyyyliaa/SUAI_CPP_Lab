/*Создайте класс IntSet для выполнения операций с множеством целых чисел. 
Реализовать операции добавления элемента, удаление элемента, проверку вхождения элемента, 
объединения множеств и вычитания одного множества из другого*/
//Доп: +функция которая принемает на вход массив множеств и добовляет несколько множеств в одно, то же самое с вычитанием
#include <iostream>
#include "L12.h"
#include <math.h>
using namespace std;

IntSet::IntSet(int* set, int size){
    setNumbers(set, size);
}

IntSet::~IntSet(){}

void mySort(int* array, int size){
    for (int i = 0; i<size; i++){
        for (int j = size-1; j>i; j--){
            if(array[j-1]>array[j]){
                int tmp= array[j-1];
                array[j-1]=array[j];
                array[j]=tmp;
            }
        }
    }
}

void IntSet:: setNumbers(int* set, int size){
    p_size = size;
    p_set = (int*)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        p_set[i] = set[i];
    }
    mySort(p_set, p_size);
}

int IntSet::check(int num){ 
    int result = 0;

    for(int i = 0; i<p_size; i++)
        if (p_set[i]==num) {
            result =  1; 
            break;
        }                      
                                                            
    return result;
}

void IntSet::addNumber(int num){ 
    int ch = check(num);    
    if(ch!=1){
        p_size++;
        p_set = (int*)realloc(p_set, sizeof(int)*(p_size));
        p_set[p_size-1] = num;
    }
    mySort(p_set, p_size);
}

void IntSet::delNumber(int num){  
    int ch = check(num);
    if (ch==1){
        for(int i = 0; i<p_size; i++){
            if(p_set[i]==num){
                for(int j=i; j<p_size-1; j++) 
                    p_set[j]=p_set[j+1];
                p_size--;
                p_set=(int*)realloc(p_set, sizeof(int)*p_size);
            }
        }
    }
    mySort(p_set, p_size);
}

void IntSet::unitSets(IntSet set){ 
    for (int i = 0; i<set.p_size; i++){ 
        if(this->check(set.p_set[i])==0){
            this->addNumber(set.p_set[i]);
        }
    }
    mySort(p_set, p_size);
}

void IntSet::subSets(IntSet set){
    for (int i = 0; i<set.p_size;i++){
        this->delNumber(set.p_set[i]);
    }
    mySort(p_set, p_size);
}

void IntSet::printSet(){
    cout<<"[";
    for(int i = 0; i<p_size; i++)
        cout<<p_set[i]<<" ";
    cout<<"]"<<endl;
}

void IntSet::unitmas(IntSet* mas, int size){
    for (int i=0; i<size; i++){
        this->unitSets(mas[i]);
    }
}
