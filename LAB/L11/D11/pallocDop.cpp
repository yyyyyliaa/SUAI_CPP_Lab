#include "pallocDop.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

char memory[16*MemSize]={0};
unsigned int bitArray[MemSize] = {0};
unsigned int bitArraySize[MemSize] = {0};
unsigned int bitArrayCheck[MemSize] = {0};
int lastBlock = MemSize;

char* palloc(int n){
    char* arr = NULL;
    int blocks = 0;
    int rem;
    
    blocks = n / paragraf;
    rem = n % paragraf;
    
    int countZero = 0;
    int indexStart = 0;
    int flag = 0;

    for (int i = 0; i< MemSize; i++){
        if ((i!=lastBlock) && (bitArray[i]==0)) countZero++;
        else countZero = 0;
        if (countZero == blocks+1){
            indexStart = i-countZero+1;
            flag = 1;
            break;
        }
    }
    if (flag==0)
        return NULL;


    for(int i = indexStart; i<indexStart+blocks;i++){
        bitArray[i] = 1;
        bitArrayCheck[i] = 16;
    }

    lastBlock = indexStart+ blocks;
    bitArrayCheck[lastBlock] += rem;
    if (bitArrayCheck[lastBlock]==16){
        bitArray[lastBlock] = 1;
        lastBlock++;
    }
    else if (bitArrayCheck[lastBlock]>16){
        bitArray[lastBlock] = 1;
        bitArrayCheck[lastBlock+1] = bitArrayCheck[lastBlock]- 16;
        lastBlock++;
        
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

void printBitArrayCheck() {
    for (int i = 0; i< MemSize; i++)
        cout<<bitArrayCheck[i]<<" ";
    cout<<endl<<endl;
}