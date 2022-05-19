/* Ввести степени и коэффициенты двух многочленов p1(x) и p2(x). 
Считать, что все коэффициенты могут принимать значения 0 или 1. 
Вычислить и вывести коэффициенты многочленов частного и остатка от деления p1(x) на p2(x). 
Все операции выполнять в арифметике по mod 2 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "l9v9.h"

#define N 5

int main() {

    int deg1, deg2; //Степени многочленов
    int p1[N], p2[N]; //коэффициенты многочленов
    int pDiv[N]; //коэффициенты частного
    
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


        int degRemainder=deg1-deg2; 
        int j=degRemainder;

        while (deg1 > deg2) {
            int fact=(p1[deg1]/p2[deg2]);
            int k2=deg2;
            pDiv[j]=fact;
            j--;
            for (int i=deg1; i>=(deg1-deg2); i--){ 
                p1[i]=abs((p1[i]-fact*p2[k2]) % 2);
                k2--;
            }
            deg1--;
        }

        printf("Result = "); 
        printPolynomial(pDiv,degRemainder);
        printf("\n");

        printf("Remainder = "); 
        printPolynomial(p1,deg1);
    
    }
    return 0;
}