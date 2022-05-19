/*Написать функции char * palloc(int n) и void pfree(char *p), 
реализующие произвольный алгоритм освобождения распределенных блоков (управление буфером). 
Размер блоков должен быть кратен параграфу (16 байт). 
Учет свободного пространства вести с использованием битового массива.
Биты должны быть упакованы в слова unsigned int, 1 - параграф занят, 0 - параграф свободен.*/


#include "pallocDOP11.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    char* arr1 =palloc(16*10);
    printBitArray();

    movingBites(14, 100, 200);
    printBitArray();

    return 0;
}