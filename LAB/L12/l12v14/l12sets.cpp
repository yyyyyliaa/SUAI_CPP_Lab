/*Создайте класс IntSet для выполнения операций с множеством целых чисел. 
Реализовать операции добавления элемента, удаление элемента, проверку вхождения элемента, 
объединения множеств и вычитания одного множества из другого*/

#include <iostream>
#include "l12sets.h"
#include <math.h>
using namespace std;

IntSet::IntSet(int* set, int size){
    setNumbers(set, size);
}

IntSet::~IntSet(){
    free(p_set);
}

void IntSet:: setNumbers(int* set, int size){
    p_size = size;
    p_set = (int*)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        p_set[i] = set[i];
    }

}

int IntSet::check(int num){ //проверка на вхождение элемента в множество
    int result = 0;

    for(int i = 0; i<p_size; i++)
        if (p_set[i]==num) {
            result =  1; 
            break;
        }                      
                                                            
    return result;
}

void IntSet::addNumber(int num){ //добавление элемнта в множество
    int ch = check(num);    
    if(ch!=1){
        p_size++;
        p_set = (int*)realloc(p_set, sizeof(int)*(p_size));
        p_set[p_size-1] = num;
    }
}

void IntSet::delNumber(int num){  //удаление элемента из множества
    int ch = check(num);
    if (ch==1){
        for(int i = 0; i<p_size; i++){
            if(p_set[i]==num){
                for(int j=i; j<p_size; j++) 
                    p_set[j]=p_set[j+1];
                p_size--;
                p_set=(int*)realloc(p_set, sizeof(int)*p_size);
            }
        }
    }
    else cout<<"Number is not in the set"<<endl;
}

void IntSet::unitSets(IntSet set){ //объединение множеств
    for (int i = 0; i<set.p_size; i++){ //остаются элементы, которые есть в первом или во втором множестве (без повторений)
        if(this->check(set.p_set[i])==0){
            this->addNumber(set.p_set[i]);
        }
    }
}

void IntSet::subSets(IntSet set){  //вычитание одного множества из второго       
    for(int i = 0; i<this->p_size; i++){   //из первого множества вычитаются все эелементы, содержащиеся во втором множестве
        if(set.check(this->p_set[i])==1) {
            this->delNumber(this->p_set[i]);
        }
    }
}


void IntSet::printSet(){
    cout<<"[";
    for(int i = 0; i<p_size; i++)
        cout<<p_set[i]<<" ";
    cout<<"]"<<endl;
}