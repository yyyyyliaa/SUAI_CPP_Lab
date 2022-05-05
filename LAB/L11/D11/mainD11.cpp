/*Написать функции char * palloc(int n) и void pfree(char *p), 
реализующие произвольный алгоритм освобождения распределенных блоков (управление буфером). 
Размер блоков должен быть кратен параграфу (16 байт). 
Учет свободного пространства вести с использованием битового массива.
Биты должны быть упакованы в слова unsigned int, 1 - параграф занят, 0 - параграф свободен.*/


#include "pallocDop.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    // char* arr1 =palloc(16*100);
    // if (arr1==NULL) cout<<"ura pobeda pobeda ura pobeda"<<endl;
    // else printBitArray();
    
    char* arr2 =palloc(16+8);
    //if (arr2==NULL) cout<<"ura pobeda pobeda ura pobeda"<<endl;
    cout<<"Bit array:"<< endl;
    printBitArray();
    printBitArrayCheck();

    char* arr3 = palloc(40);
    cout<<"Bit array:"<< endl;
    printBitArray();
    printBitArrayCheck();
    // printBitArray();

    // char* arr5 =palloc(64);
    // printBitArray();

    // pfree(arr5);
    // printBitArray();

    return 0;
}