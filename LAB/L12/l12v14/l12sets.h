/*Создайте класс IntSet для выполнения операций с множеством целых чисел. 
Реализовать операции добавления элемента, удаление элемента, проверку вхождения элемента, 
объединения множеств и вычитания одного множества из другого*/

#pragma once
#define SIZE 3

#include <iostream>

class IntSet {

private:

    int size = SIZE;

    int* p_set=(int*)malloc(sizeof(int)*size);


public:

    IntSet();

    void setNumbers(int* set);

    int check(int num);

    void printFirstSet();

    void printSecondSet();

    void printSubSet();

    void printUnitSet();

    void addNumber(int num);

    void delNumber(int num);

    void delSecondSet();

    void uniteSet();

    void firstSubSecond();

    void secondSubFirst();

    
    
};