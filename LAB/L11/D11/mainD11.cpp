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
    
    // char* arr2 =palloc(32);
    // //if (arr2==NULL) cout<<"ura pobeda pobeda ura pobeda"<<endl;
    // cout<<"Bit array:"<< endl;
    // printBitArray();
    // printBitArrayCheck();

    // copyBites(14, 10);
    // cout<<"Bit array:"<< endl;
    // printBitArray();
    // printBitArrayCheck();

    // char* arr3 = palloc(32+8);
    // cout<<"Bit array:"<< endl;
    // printBitArray();
    // printBitArrayCheck();
    // // printBitArray();

    // char* arr5 =palloc(48+12);
    // cout<<"Bit array:"<< endl;
    // printBitArray();
    // printBitArrayCheck();
    // // printBitArray();

    // char* arr6 = palloc(16+7);
    // cout<<"Bit array:"<< endl;
    // printBitArray();
    // printBitArrayCheck();

    // pfree(arr5);
    // printBitArray();

    char* arr1 = palloc(2);
    cout<<"After 1 palloc: "<<endl;
    printBitArray();
    printBitArrayCheck();

    char* arr2 = palloc(2);
    cout<<"After 2 palloc: "<<endl;
    printBitArray();
    printBitArrayCheck();


    char* arr3 = palloc(2);
    cout<<"After 3 palloc: "<<endl;
    printBitArray();
    printBitArrayCheck();

    
    char* arr4 = palloc(2);
    cout<<"After 4 palloc: "<<endl;
    printBitArray();
    printBitArrayCheck();


    char* arr5 = palloc(2);
    cout<<"After 5 palloc: "<<endl;
    printBitArray();
    printBitArrayCheck();


    char* arr6 = palloc(2);
    cout<<"After 6 palloc: "<<endl;
    printBitArray();
    printBitArrayCheck();


    char* arr7 = palloc(2);
    cout<<"After 7 palloc: "<<endl;
    printBitArray();
    printBitArrayCheck();

    char* arr8 = palloc(2);
    cout<<"After 8 palloc: "<<endl;
    printBitArray();
    printBitArrayCheck();

    // pfree(arr4);
    // cout<<"After 4 pfree: "<<endl;
    // printBitArray();
    // printBitArrayCheck();

    // pfree(arr5);
    // cout<<"After 5 pfree: "<<endl;
    // printBitArray();
    // printBitArrayCheck();

    char* arr9 = palloc(4);
    cout<<"After 9 palloc: "<<endl;
    printBitArray();
    printBitArrayCheck();



    return 0;
}