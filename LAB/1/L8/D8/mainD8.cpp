/* Определить сложность и скорость выполнения сортировки и функции поиска ближайшего элемента*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "D8.h"


int main(void){

    srand(time(NULL));

    long int startTimeSort, endTimeSort, startTimeSearch, endTimeSearch;
    
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);

    while (size <= 0){
        printf("The number must be greater than zero\n");
        printf("Enter the size of the array: ");
        scanf("%d", &size);
    }

    int* array = (int*)malloc(sizeof(int)*size);
    for (int i =0; i<size; i++) array[i]=rand();

    printf("What element index do you want to know? ");
    int x;
    scanf("%d", &x);

    startTimeSort = (long double)time(NULL);
    mySort(array, size); 
    endTimeSort = (long double)time (NULL);

    startTimeSearch = (long double)time(NULL);
    searchNearest(size, array, x); 
    endTimeSearch = (long double)time(NULL);

    printf("\n");

    printf("Speed of sorting an array of %d elements: ", size);
    printf("%ld\n", endTimeSort-startTimeSort);
    printf("O(n^2) = %ld\n", size*size);


    printf("Search speed: ");
    printf("%ld\n", endTimeSearch-startTimeSearch);
    printf("O(log(n)) = %f\n", log(size));

    return 0;
    
}