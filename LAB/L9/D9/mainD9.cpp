/* Выполнить проверку деления многочленов */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "D9.h"

#define N 5

int main() {

    int deg1, deg2; //степени многочленов
    int p1[N] = {0}, p2[N] = {0}; //коэффициенты многочленов
    int pDiv[N] = {0}; //коэффициенты результата
    int degRes; //cтепень результата
    
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
    printf("\n");

    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);

    if (deg2 > deg1){ 
        printf("Result = 0\n");
        printf("Remainder = ");
        printPolynomial(p1,deg1);
    }

    else {
        for (int i=deg2; i>=0; i--) {

            printf("Enter coefficient x^%d = ", i);
            scanf("%d", &p2[i]);

            while ((i==deg2) && (p2[i]==0)) {

                printf("The first coefficient cannot be 0\n");

                printf("Enter coefficient x^%d = ", i);
                scanf("%d", &p2[i]);
            }
        }   
    
        printf("\n");

        degRes = deg1 - deg2;
        int j=degRes;

        while (deg1 > deg2) {
            int fact=(p1[deg1]/p2[deg2]);
            int k2=deg2;
            pDiv[j]=fact;
            j--;
            for (int i=deg1; i>=(deg1-deg2); i--){ 
                p1[i]=(p1[i]-fact*p2[k2]) % 2;
                k2--;
            }
            deg1--;
        }

        printf("Result = "); 
        printPolynomial(pDiv,degRes);
        printf("\n");

        printf("Remainder = "); 
        printPolynomial(p1,deg1);
        printf("\n");
    
    }

    divCheck(p1, p2, pDiv, deg1, deg2, degRes);

    return 0;
}