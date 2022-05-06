/*Написать генератор псевдослучайных чисел, распределенных по экспоненциальному закону*/

#include <stdio.h>

#include "d7.h"

#define N 10

int main(){

    printf("Enter parameter L: ");
    double L;
    scanf_s("%lf", &L);


    while (L <= 0){
        printf("Parametr must be greater than zero\n");
        printf("Enter parameter L: ");
        scanf_s("%lf", &L);
    }

    printf("Result:\n");

    long double num;

    for (int i = 0; i < N; i++){
        num = genRandom(L);
        printf("%lf\n", num);
    }

    return 0;
}