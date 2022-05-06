/* Выполнить проверку деления многочленов */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void scanPolinomial(int deg1, int* p1){
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1); 

    for (int i=deg1; i>=0; i--) {

        printf("Enter coefficient x^%d (0 or 1) = ", i); 
        scanf("%d", &p1[i]); 

        while ((i==deg1) && (p1[i]==0)){ 
            printf("The first coefficient cannot be 0\n");

            printf("Enter coefficient x^%d = ", i); 
            scanf("%d", &p1[i]); 
        }
    }
}

void printPolynomial(int arr[], int count){   //вывод многочлена на экран
    for (int i=count; i>=0; i--)
        printf("%d ", arr[i]);
}

void divCheck(int* p1, int* p2, int* pDiv, int deg1, int deg2, int degRes){
    int tmpDeg = deg2;
    deg2 += degRes;

    for (int i = deg2; i>=deg1; i--){
        p2[i] = p2[i-1];
    }

    // printPolynomial(p2, deg2);
    // printf("\n");
    // printPolynomial(p1, deg1);

    for (int i = deg1; i>=0; i--){
        p2[i] += p1[i];
    }

    printf("Result after checking: ");
    printPolynomial(p2, deg2);
}
