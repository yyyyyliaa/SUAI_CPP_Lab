/* Ввести массив целых чисел и отсортировать его  
Ввести число и найти в массиве ближайшее к нему методом двоичного поиска*/

#include <stdio.h>
#include <stdlib.h>
#include "l8v9.h"


int main(){

    
    printf("Enter the size of the array: ");
    int size;
    scanf_s("%d", &size);

    while (size <= 0){
        printf("The number must be greater than zero\n");
        printf("Enter the size of the array: ");
        scanf_s("%d", &size);
    }

    int* array = (int*)malloc(sizeof(int)*size);

    printf("Enter %d numbers:\n ", size);
    for (int i=0; i<size; i++) scanf_s("%d", &array[i]);

    printf("What element index do you want to know? ");
    int x;
    scanf_s("%d", &x);

    mySort(array, size);

    printf("Array after sorting: \n");
    for (int i =0; i<size; i++) printf("%d\n", array[i]);

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

    return 0;
    
}
