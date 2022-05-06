/*Написать алгоритм, вычисляющий количество единиц в двоичной записи числа*/

#include <stdio.h>

int main(){
    int x, w, xStart;  //исходное число
    printf("x = ");
    scanf_s("%d", &x);

    while (x>0){
        xStart = x;
        w = 0;
        while (x > 0){
            w += x & 1;
            x>>=1;
        }
        printf("w = %d\n", w);
        printf ("\n");
        printf("x = ");
        scanf_s("%d", &x);
    }
    return 0;
}