//универсальная сортировка

#include <stdio.h>
#include <iostream>
using namespace std;

void swap(char* a, char* b, size_t n){
    for (size_t i = 0; i<n; i++){
        char tmp = *(a+i);
        *(a+i) = *(b+i);
        *(b+i) = tmp;
    }
}

int comp(char* a, char* b){
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa-*pb;
}

void sortt(void* arr, size_t size, size_t sizeElem,int (*comp)(char*, char*)){
    char* ar = (char*)arr;
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size-i-1; j++){
            if (comp(ar+j*sizeElem, ar+(j+1)*sizeElem)>0) 
                swap(ar+j*sizeElem, ar+(j+1)*sizeElem, sizeElem);
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {3, 6, 1, 2, 9};
    for (int i = 0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sortt(arr, 5, sizeof(int), comp);
    for (int i = 0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
