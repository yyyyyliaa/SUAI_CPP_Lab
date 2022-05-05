#include "pallocDOP11.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

char memory[16*MemSize]={0};
unsigned int bitArray[MemSize] = {0};
unsigned int bitArraySize[MemSize] = {0};

char* palloc(int n){
    char* arr = NULL;
    int blocks = 0;
    if (n % paragraf == 0)
        n = n / paragraf;
    else {
        n = n / paragraf;
        n++;
    }
    blocks = n;
    int countZero = 0;
    int indexStart = 0;
    int flag = 0;
    for (int i = 0; i< MemSize; i++){
        if (bitArray[i]==0) countZero++;
        else countZero = 0;
        if (countZero ==blocks){
            indexStart = i-countZero+1;
            flag = 1;
            break;
        }
    }
    if (flag==0)
        return NULL;


    for(int i = indexStart; i<indexStart+blocks;i++){
        bitArray[i] = 1;
    }

    bitArraySize[indexStart] = blocks;

    return memory+(blocks*paragraf);

}

void pfree(char *p){
    int start = ((int)(p-memory))/(sizeof(int)*4);
    for(int i = start; i<start+bitArraySize[start]; i++){
        bitArray[i] = 0;
    }

}

void printBitArray() {
    for (int i = 0; i < MemSize; i++) 
        cout<<bitArray[i]<< " ";
    cout<<endl<<endl;
}

void movingBites(int from, int size, int into){
    int blockToMove = into/paragraf;
    int start = from/paragraf;

    int blocks;
    if ((size%paragraf)==0) blocks = size/paragraf;
    else blocks = (size/paragraf) + 1;

    int flag = 0;

    for (int i = blockToMove; i<blockToMove+blocks; i++){
        if(bitArray[i]==1) {
            flag = 1;
            break;
        }
    }

    if (flag==1) cout<<"Moving is not possible"<<endl;
    else {
        for(int i = blockToMove; i<blockToMove+blocks; i++){
            bitArray[i] = 1;
        }
        for (int i = start; i<start+blocks;i++){
            bitArray[i] = 0;
        }
    }

    
}