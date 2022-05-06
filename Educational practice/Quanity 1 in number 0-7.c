/*Программа выводит на экран количество единиц в двоичной записи чисел от 0 до 7*/

#include <stdio.h>

int main(){
    int data;
    int a[]={0, 1, 1, 2, 1, 2, 2, 3};
    printf("Enter a number in range 0-7: ");
    scanf_s("%d", &data);
    while (data>=0 && data<8){
        printf("Answer: %d\n", a[data]);
        printf("\n");
        printf("Enter a number in range 0-7: ");
        scanf_s("%d", &data);
    }
    printf("Incorrected integer. It should be in range 0-7\n");
    return 0;
}