#include <stdio.h>
#include <stdlib.h>

int binarySearch (int * arr , int left , int right , int x ) {
    while ( left <= right ) {
        int m = left + ( right - left ) / 2;
        if ( arr[m] == x ) return m ;
        if ( arr[m] < x ) left = m + 1;
        else right = m - 1; 
    }
    return -1;
}

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

void searchNearest(int size, int* array, int x){
    int index;
    int k = 1;
    index = binarySearch(array, 0, size-1, x);
    if ((index!=-1)&&(array[index]==x)) printf("Search element index - %d", index);
    else{
        while(index == -1){
            index = binarySearch(array, 0, size-1, x+k);
            if (index==-1) index = binarySearch(array, 0, size-1, x-k);
            k++;
        }
        printf("The desired number was not found. Its nearest number is %d. Its index - %d", array[index], index);
    }
}